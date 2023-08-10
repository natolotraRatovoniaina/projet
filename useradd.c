#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* crypt(char* mdp);
int readpid(int uid);

int main() {
	
///Les variables utilisées     
    char username[100];		//nom de l'utilisateur 
    char fullname[100];		//description
    //char password[100];		
    char userfile[150];		//dossier personnel
    char cmd[500];			//executer une commande
    int uid=0;			//l'identifiant de l'utilisateur
    char passwd[500];		//pour ecrire dans /etc/passwd
    char shadow[500];		//pour ecrire dans /etc/shadow
    char group[500];		//pour ecrire dans /etc/group
    char gshadow[500];		//pour ecrire dans /etc/gshadow
    
    sprintf(cmd,"sudo cat /etc/passwd |awk -F: '{print $3}' >fic.txt");
	system(cmd);
	//Entrez le nom de l'utilisateur 
    printf("Entrez le nom de l utilisateur:");
    scanf("%s", username);
	
	//Entrez le nom complet
    printf("Entrez le nom complet de l'utilisateur: ");
    scanf("%s", fullname);
	
	/*
	//Entrez le nom de passe
    printf("Entrez le mot de passe: ");
    scanf("%s", password);
    char *password_hash;
	password_hash = crypt(password); // Génère le hash du mot de passe
	*/
	
	//generer le uid de l'utilisateur
	uid=readpid(uid);
    
    // Ajouter une nouvelle entrée dans /etc/passwd
    sprintf(passwd, "sudo echo '%s:x:%d:%d:%s,,,:/home/%s:/bin/bash' >>/etc/passwd", username,uid,uid,fullname,username);
	system(passwd);
	
    // Ajouter une nouvelle entrée dans /etc/shadow
    sprintf(shadow, "sudo echo '%s:$6$fjDiZflGp9HdSR03$ClsOFLWplgv8q9RmEIBcWVxtvvC.wZzGdiUVR4KJb3YQeISQiGhJTvdNXkvnMZW4AujiHYbc1z0Vi/jN9yy1Y1:18894:0:99999:7:::' >>/etc/shadow", username);
	system(shadow);
    // Ajouter une nouvelle entrée dans /etc/group
    sprintf(group, "sudo echo '%s:x:%d:' >>/etc/group", username,uid);
	system(group);
	
    // Ajouter une nouvelle entrée dans /etc/gshadow
    sprintf(gshadow, "sudo echo '%s:!::' >>/etc/gshadow", username);
	system(gshadow);
	
	//Créeer le dossier personnel de l'utilisateur
	sprintf(userfile,"mkdir /home/%s",username);
	system(userfile);
	
	
	//Changer l'utilisateur principal du dossier personnel
	sprintf(cmd,"sudo chown %s:%s /home/%s",username,username,username);
	system(cmd);
	
	
	//copier les élements nécessaire de l'utilisateur dans son document personnel
	sprintf(cmd,"ls -a /etc/skel|cp -Ra * /home/%s",username);
	system(cmd);
	
	
    printf("Le nouveau utilisateur '%s' est bien cree\n.", username);
    return 0;
}

//La fonction qui script une mot de passe
char* crypt(char* mdp){
	char cmd[100];
	
	//scripter le mot de passe entrée
	sprintf(cmd,"openssl passwd -1 %s >fic.txt",mdp);
	system(cmd);
	
	FILE *pt=fopen("fic.txt","r");
	fgets(mdp,100,pt);//on stocke le resultat du script dans chiffre
	fclose(pt);
	system("rm -r fic.txt");
	
	return mdp;
}

 // Récupérer le dernier UID présent dans le fichier /etc/passwd
int readpid(int last_uid){	
    FILE* file = fopen("fic.txt", "r");
    //int last_uid = 0;
    char line[1024];
    
    while (fgets(line, sizeof(line), file)) {
		int uid = atoi(strtok(line, "\n"));
        
        if (last_uid < uid && uid<1100){
            last_uid = uid;
        }
    }
    
    fclose(file);

    // Ajouter 1 à l'UID pour obtenir le nouvel UID unique
    int new_uid = last_uid + 1;
	return new_uid;
}

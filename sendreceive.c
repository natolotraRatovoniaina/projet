#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"unistd.h"
void sread(char* texte);
void textcolor(char* text);
void stime(void);
int main(){
///	
	textcolor("C H A R G E M E N T");
	printf("\n");
	//printf("Partage de fichier\n");
	system("toilet --font big --gay \"Share 	files\"");
///
	//int return_value = 1;
	char ip[100] = "init",						// Variable pour stocker l'adresse IP
		 nom[100] = "name",						// Nom du destinataire
		 fichier[100] = "fic";					// Nom du fichier à envoyer
	char* cmd;
		 
	int option = 0;								// Choix "envoyer" ou "recevoir"
	int choix = 10;
		printf("\033[36m");
		sread("Entrez une option\n\n");
		printf("\033[0m");
		
		sread("Option 1.....");
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		stime();
		
		printf("1-Recevoir un fichier\n");
		stime();
		
		sread("Option 2.....");
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		stime();
		printf("2-Envoyer un fichier\n");
		
		printf("\n--> ");
		scanf("%d", &option);
		system("clear");
		
	switch(option){
		case 1:
/*
	Destinataire
*/
//-------------------------------------------------------------------------------------------------------------
			system("touch IP.txt");						// Créer le fichier IP.txt
			system("hostname -I >> IP.txt");			// Copier le contenu de "hostname -I" dans "IP.txt"
			FILE *adIP = fopen("IP.txt", "r");			// Ouvrir le fichier IP.txt
			
			//char ip[20] = "init";						// Variable pour stocker le contenu du fichier "IP.txt"
			//int m=1;
			fgets(ip, 20, adIP);						// Copie du contenu du fichier dans ip
			strtok(ip , "\n");
			system("rm IP.txt");						// Supprimer le fichier 
			fclose(adIP);								// Fermeture du fichier
		
				if((int)*ip == 10){
					sread("Aucune connexion !! Veuillez connecter à un réseau\n");
					for(int i=0; i<3;i++){
						usleep(600000);
					}
					system("clear");
					system("./sendreceive");
				}
				else{
					sread("User: ");
					system("whoami");
					printf("\nVotre adresse IP est: %s\n", ip);	// Afficher l'adresse IP 
					break;
				}
			
			//m=strlen(ip);
			//printf("\n%d", m);
			break;
//---------------------------------------------------------------------------------------------------------

		case 2:
/*
	Expéditeur
*/
//---------------------------------------------------------------------------------------------------------
	//char nom[20] = "uni";
	cmd = (char*)malloc(sizeof(char)*100);
	char chemin[150] = "way";
	char traverse[100] = "init";
	
	
			printf("Listes des IP disponnibles:\n");
			system("arp -n | awk '{print$1}'");
			printf("\n");
	
			sread("Entrez le nom du destinataire: ");
			scanf("%s", nom);
			sread("Entrez l' adresse IP du destinataire: ");
			scanf("%s", ip);
			
		
			//int choix = 10;
			while(choix != 0){
				sread("Nom du fichier à envoyer: ");
				scanf("%s", fichier);
				sprintf(chemin, "plocate %s | head -1 >> fic.txt", fichier);
				system(chemin);
			
				FILE *fileway = fopen("fic.txt", "r");
				fgets(traverse, 100, fileway);
				strtok(traverse, "\n");
				printf("\n\n");
				printf("chemin vers le fichier: %s", traverse);

				sprintf(cmd, "scp -r %s %s@%s:/home/%s" , traverse, nom, ip, nom);
				printf("\nVotre commande: %s\n\n", cmd);
				
				
				system(cmd);
				//return_value = system(cmd);
				//printf("return value: %d", return_value);
				
				printf("Entrer 1 pour envoyer d'autres fichiers ou 0 pour arrêter: ");
				scanf("%d", &choix);
				
				fclose(fileway);
				system("rm fic.txt");
			}
			break;
		}
//----------------------------------------------------------------------------------------------------------
	return 0;
}

void sread(char* texte){
	for(int i=0; i<strlen(texte) ; i++){
		printf("%c", *(texte+i));
		usleep(60000);
		fflush(stdout);
	}	
}

void textcolor(char* text){
	for(int i=0; i<3; i++){
		printf("%s", text);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		fflush(stdout);
		usleep(400000);
		printf("\033[36m%s\033[0m", text);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		fflush(stdout);
		usleep(400000);
		printf("\033[31m%s\033[0m", text);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		fflush(stdout);
		usleep(400000);
	}
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		printf("  ^_^              ");
}

void stime(void){
	for(int i=0; i<3;i++){
		usleep(600000);
	}
}

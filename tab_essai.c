#include <stdio.h>
void affiche(long *tableau, long tailleTableau);
int main(int argc, char *argv[])
{
long tableau[4] = {10, 15, 3};
// On affiche le contenu du tableau
affiche(tableau, 4);
return 0;
}
void affiche(long *tableau, long tailleTableau)
{
long i;
for (i = 0 ; i < tailleTableau ; i++)
{
printf("%ld\n", tableau[i]);
}
}

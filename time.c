#include <stdio.h>
#include <stdlib.h>
/* Je mets le prototype en haut. Comme c'est un tout
petit programme je ne le mets pas dans un .h, mais
en temps normal (dans un vrai programme) j'aurais placé
le prototype dans un fichier .h bien entendu ;o) */
void decoupeMinutes(long* heures, long* minutes);
int main(int argc, char *argv[])
{
long heures = 0, minutes = 90;
/* On a une variable minutes qui vaut 90.
Après appel de la fonction, je veux que ma variable
"heures" vaille 1 et que ma variable "minutes" vaille 30 */
decoupeMinutes(&heures, &minutes);
printf("%ld heures et %ld minutes", heures, minutes);
return 0;
}
void decoupeMinutes(long* heures, long* minutes)
{
*heures = *minutes / 60; // 90 / 60 = 1
*minutes = *minutes % 60; // 90 % 60 = 30 (rappelez-vous : modulo = reste de la division,"90 divisés par 60 font 1, et il reste 30";)
}

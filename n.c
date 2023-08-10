#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
long nombreEntre = 0, nombreTriple = 0;
printf("Entrez un nombre... ");
scanf("%ld", &nombreEntre);
nombreTriple = triple(nombreEntre);
printf("Le triple de ce nombre est %ld\n", nombreTriple);
return 0;
}
long triple(long nombre)
{
return 3 * nombre;
}

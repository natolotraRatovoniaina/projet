#include <stdio.h>
double conversion(double euros)
{
double francs = 0;
francs = 6.55957 * euros;
return francs;
}
int main(int argc, char *argv[])
{
printf("10 euros = %lfF\n", conversion(0));
printf("50 euros = %lfF\n", conversion(50));
printf("100 euros = %lfF\n", conversion(100));
printf("200 euros = %lfF\n", conversion(200));

return 0;
}

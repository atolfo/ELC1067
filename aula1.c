#include <stdio.h>

void main ()
{

FILE *F;
int matricula;
char nome [99];
printf ("informe matricula");
scanf ("%d", &matricula);

printf ("informe o nome");
scanf ("%s", nome);

F= Fopen ("saida.txt", "w");
Fprint (F, "%d%s\n",matricula,nome);
Fclose (F);

}

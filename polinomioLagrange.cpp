#include<stdio.h>
#include<math.h>
void INPUT(int *, double *, double [][26], double *, int *);
void OUTPUT(int, double, double *, double [][26]);
main()
{
int test;
double Q[26][26],XX[26],D[26];
double X;
int I,J,N,OK;
INPUT(&OK, XX, Q, &X, &N);
if (OK) {
D[0] = X - XX[0];
for (I=1; I<=N; I++)
    {
    D[I] = X - XX[I];
    for (J=1; J<=I; J++)
    {
           Q[I][J] = (D[I] * Q[I-1][J-1] - D[I-J] *
           Q[I][J-1]) / (D[I] - D[I-J]);}
    }
    OUTPUT(N, X, XX, Q);
}
printf("Numero!!");
scanf("%d", test);
return 0;
}
void INPUT(int *OK, double *XX, double Q[][26], double *X, int *N)
{
int I;
char NAME[30];
FILE *INP;
printf("Dar el nombre y la extension del archivo de entrada en el formato ");
printf("nombre.txt\n");
scanf("%s", NAME);
INP = fopen(NAME, "r");
*OK = false;
while (!(*OK))
{
 printf("Dar valor de n\n");
 scanf("%d", N);
             if (*N > 0)
             {
              for (I=0; I<=*N; I++)
                  fscanf(INP, "%lf %lf", &XX[I], &Q[I][0]);
                  fclose(INP);
                  *OK = true;
              }
              else printf("Debe ser un entero positivo\n");
}
if (*OK)
{
 printf("Dar el punto en que se va a evaluar el polinomio ");
 scanf("%lf", X);
}
}
void OUTPUT(int N, double X, double *XX, double Q[][26])
{
int I, J;
for (I=0; I<=N; I++)
{
 printf("%11.6f ", XX[I]);
 for (J=0; J<=I-1; J++) printf("%11.8f ", Q[I][J]);
 printf("\n");
}
}

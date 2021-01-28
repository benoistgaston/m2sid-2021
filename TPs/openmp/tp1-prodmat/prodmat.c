/* Programme executant le produit de deux matrices rectangulaires A et B
 Matrice A 
                n colonnes
             1  1 ... ... 1  1 
             2  2 ... ... 2  2
   m lignes  .               .
             .               .
             .               .
             m  m ... ... m  m
 Matrice B 
                m colonnes
             1  0 ... 0  0 
             0  1 ... 0  0
   m lignes  .           .
             .           .
             .           .
             0  0 ... 0  1
 n-m lignes  0           0
             .           .
             .           .
             0  0 ... 0  0
 Resultat a obtenir
 Matrice C
                m colonnes
             1  1 ... 1  1 
             2  2 ... 2  2
   m lignes  .           .
             .           .
             .           .
             m  m ... m  m         */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
 
int main(int argc, char *argv[])
{
  double** A;  
  double** B;
  double** C; 

  int n,m;
  int i,j,k;
  struct timeval tv1,tv2;
  struct timezone tz;
  float temps;

  /* read m n the size of the array T */
  if (argc > 2)
  {
    m = atoi(argv[1]);
    n = atoi(argv[2]);
  }
  else
  {
    printf("Enter number m\n");
    scanf("%d", &m);
    printf("Enter number n\n");
    scanf("%d", &n);
  }
  
  A = (double**) malloc(m * sizeof(double*));
  for (i=0; i<m; i++)
      A[i]=(double*) malloc(n * sizeof(double));  

  B = (double**) malloc(n * sizeof(double*));
  for (i=0; i<n; i++)
      B[i]=(double*) malloc(m * sizeof(double));  

  C = (double**) malloc(m * sizeof(double*));
  for (i=0; i<m; i++)
      C[i]=(double*) malloc(m * sizeof(double));  

/* Temps de reference */
 
  gettimeofday(&tv1, &tz);
 
    for (i=0;i<m;i++) {
      for (j=0;j<n;j++) {
        A[i][j]= (double) (i+1);
      }
    } 
    for (i=0;i<n;i++) {
      for (j=0;j<m;j++) {
        if (i==j) 
          B[i][j] =(double) 1;
        else
          B[i][j] =(double) 0;       
      }
    }
    for (i=0;i<m;i++) {
      for (j=0;j<m;j++) {
        C[i][j] =(double) 0;
      }
    }
/* Produit de matrices */
    for (i=0;i<m;i++) {
      for (k=0;k<n;k++) {
        for (j=0;j<m;j++) {
          C[i][j] =C[i][j] + A[i][k]*B[k][j];
        }
      }
    }
/* Temps final */
 
  gettimeofday(&tv2, &tz);
  temps = (tv2.tv_sec - tv1.tv_sec) + (tv2.tv_usec - tv1.tv_usec)/1000000.0 ;
 
/* Impression des resultats */
  printf("\n\n\t\tTemps de restitution : %15.4f sec.\n\t\tResulat partiel : %g %g ... %g %g\n\n ",
	 temps,C[0][0], C[1][6],C[m-2][m-7],C[m-1][m-1]); 
  return 0;
}

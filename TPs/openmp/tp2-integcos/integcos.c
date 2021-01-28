/* programme integrant cosinus carre sur [0..Pi/4] par la methode des trapezes
 formule :

 0.5*cos(0)**2 + cos(h)**2 + cos(2h)**2 + ... + cos((n-1)h)**2 + 0.5cos(nh)**2
 
 valeur theorique :   Pi/8 + 1/4 
 
*/

#include <stdio.h>
#include <sys/time.h>
#include <math.h>

int main()
{
  /*const int n=2000000000;*/
  const int n=200000000;
  double    ecart,somme=0,Pi,h,x,ValTheo;
  int       i;
  struct timeval tv1,tv2;
  struct timezone tz;
  double    temps;


/* Temps de reference */
   gettimeofday(&tv1, &tz);

#pragma omp parallel 
  {
 
/* Valeur de Pi */
    Pi=(double)(4)*atan((double) 1);

/* Valeur Theorique */
    ValTheo=Pi/(double)(8)+(double)(1)/(double)(4);

/* calcul du pas d'integration */
    h=Pi/((double)(4)*(double)(n));

    for (i=1;i<n;i++) {
      x= h*(double)(i);
      somme=somme+pow(cos(x),2.);
    }
  } /* fin de la region parallel */
  somme= h*(somme +
            (pow(cos((double) 0),2.)+pow(cos(Pi/(double) 4),2.))
            /(double) 2);
  ecart=fabs(somme-ValTheo)/ValTheo;
/* Temps final */
 
  gettimeofday(&tv2, &tz);
  temps = (tv2.tv_sec - tv1.tv_sec) + (tv2.tv_usec - tv1.tv_usec)/1000000.0 ;
 
/* Impression des resultats */
  printf("\n\t\tTemps de restitution : %15.4f sec.\n\t\tEcart relatif : %g\n ",
         temps,ecart);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define e 2.71828182845

double F (double x)
{
  return x*(pow(sin(x),9)*pow(cos(x),13))/pow(e,(-x));
}

 void romberg(double f(double), double a, double b, int n, double **R) //pass a function to a function
{
  int i, j, k;
  double h, sum;


  h = b - a;
  R[0][0] = 0.5 * h * (f(a) + f(b));   
  printf(" R[1][1] = %0.16lf\n", R[0][0]);

  for (i = 1; i <= n; i++)
  { 
     h *= 0.5;
     sum = 0;
     for (k = 1; k <= pow(2,i)-1; k+=2)
     {
       sum += f(a + k * h);
     } 
     R[i][0] = 0.5 * R[i-1][0] + sum * h;  
     printf(" R[%d][1] = %0.16lf\n", i+1, R[i][0]);
     for (j = 1; j <= i; j++)
     {
       R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (pow(4,j)-1); 
       printf(" R[%d][%d] = %0.16lf\n", i+1,j+1, R[i][j]);
     }
   }

   printf("\nTherefore the Final Value of the Integral is: %0.16lf\n\n",R[n][n]);
}

void main()
{
  int n = 0;
  double a,b;
  printf("\nThe function is F(x) = [x*(sin(x))^9*(cos(x))^13]/e^(-x)\n");
  printf("\nEnter the value of n (Extrapolation till R(n,n))  : ");
  scanf("%d",&n);

  printf("\nEnter the limits of integration:\n");
  printf("a:");
  scanf("%lf",&a);
  printf("b:");
  scanf("%lf",&b);
  printf("\n");

  int i;
  double **R;
  double F(double);

  R = calloc((n+1), sizeof(double *));
  for (i = 0; i <= n; i++)
    R[i] = calloc((n+1), sizeof(double));


  romberg(F,a,b,n-1,R);

}


/*


long double f(long double x){

return x*pow(e,x);
}

long double  R(long double i, long double j){

    long double z=pow(4,j-1);

    if(j==1){
        return 0.5*(R(i-1,1)+);
    }

    else{
    return ((z*R(i,j-1))-R(i-1,j-1))/(z-1);
    }
}


int main(){    return 0;
}
*/
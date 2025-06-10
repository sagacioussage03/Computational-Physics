#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
 float x[20], y[20], xp, h, first_derivative,first_derivative_1,first_derivative_2,second_derivative,second_derivative_2;
 int i,j, n;


 printf("Enter number of data points: ");
 scanf("%d", &n);


 printf("Enter data points:\n");
 for(i = 0; i < n ; i++)
 {
  printf("x[%d] = ", i);
  scanf("%f", &x[i]);
  printf("y[%d] = ", i);
  scanf("%f", &y[i]);
 }


 printf("Enter x: ");
 scanf("%f", &xp);



 /* Calculate finite difference */
 h = x[1] - x[0];

int index;
for(i=0;i<n;i++){
    if(xp==x[i]){
        index=i;
        break;
    }
}




 first_derivative = (y[i+1]-y[i-1])/2*h;

first_derivative_1= (((-1.0)*y[i+2]+4.0*y[i+1]-3.0*y[i]))/2*h;

second_derivative = (y[i+1]-2.0*y[i]+y[i-1])/h*h;

second_derivative_2=(y[i+2]-2.0*y[i+1]+y[i])/h*h;


 /* Displaying final result */
 printf("\nFirst derivative (CDM) at x = %0.2f is %0.2f\n", xp, first_derivative);
  printf("First derivative (CDM_improved) at x = %0.2f is %0.2f\n", xp, first_derivative_1);
  printf("second derivative (CDM) at x = %0.2f is %0.2f\n", xp, second_derivative);
  printf("second derivative (FDM) at x = %0.2f is %0.2f\n", xp, second_derivative_2);

 return 0;
}
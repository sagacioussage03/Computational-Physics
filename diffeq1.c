#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f_dash(double x,double y){

    return -1*y*y;
}


double f(double x){

    return 1/(x+1);
}

double error(double trueValue,double aprxValue){
    return fabs(((trueValue-aprxValue)/trueValue))*100;
}


int main(){

    double x[100];
    double y[100];
    int i=0;
    double iter=0;
    double h=0.0;

    printf("\nThe problem is dy/dx=-y^2\n");

    printf("\nEnter the intitial value y[0]:");
    scanf("%lf",&y[0]);

    printf("Enter the value of h:");
    scanf("%lf",&h);
    printf("Enter the number of iterations:");
    scanf("%lf",&iter);



    printf("\n\t-----------------------------------------------------------------------------");
    printf("\n\tx\ty_true\t\ty_euler\t\tError\n");
    printf("\t-----------------------------------------------------------------------------\n");

    while(i!=iter){
        y[i+1]=y[i]+h*f_dash(i*h,y[i]);

        printf("\t%0.2lf\t%lf\t%lf\t%lf\n",i*h,f(i*h),y[i],error(f(i*h),y[i]));

        i++;
    }
    printf("\t-----------------------------------------------------------------------------\n\n");

    




    return 0;
}

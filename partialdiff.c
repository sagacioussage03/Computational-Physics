#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(){

    double delx;
    double delt;
    double length=1;
    int iter;
    double finali;
    int i,j;

   

    printf("\nGiven length of string = 1\n");
    printf("\nEnter the value of delta t:");
    scanf("%lf",&delt);
    printf("\nEnter the value of delta x:");
    scanf("%lf",&delx);

    finali=length/delx;
    int finalj=finali;

    
    

    printf("\nEnter the number of iterations:");
    scanf("%d",&iter);

    double alpha=pow(delt/delx,2);

    

    double u[iter+1][finalj+1];

    for(j=0;j<=iter;j++){
        for(i=0;i<=finalj;i++){
            if(i==0){
                u[j][i]=0;
            }
            else if(i==finalj){
                u[j][i]=0;
            }
            else if(j==0 && i!=0 && i!=finalj){
                u[j][i]=(1-i*delx)*i*delx;
            }
            else if(j==1 && i!=0 && i!=finalj){
                u[j][i]=(1-alpha)*u[j-1][i]+ alpha*0.5*(u[j-1][i-1]+u[j-1][i+1]);
            }
            else if(j!=0 && j!=1 && i!=0 && i!=finalj){
                u[j][i]=2*(1-alpha)*u[j-1][i]+ alpha*(u[j-1][i-1]+u[j-1][i+1])-u[j-2][i];
            }

        }
    }

    printf("\n\n\n");
    printf("-----------------------------------------------------------------------------------------------\n");

    for(j=0;j<=iter;j++){
        printf("j = %d\t",j);
        for(i=0;i<=finalj;i++){
            printf("%lf  ",u[j][i]);
        }
        printf("\n");
    }
    printf("----------------------------------------------------------------------------------------------\n\n");

}
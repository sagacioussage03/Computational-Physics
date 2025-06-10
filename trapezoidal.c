
#include<stdio.h>
#include<math.h>
#include <string.h>
/*
#include <unistd.h>
#include<time.h>
#include <windows.h>
*/

#define PI 3.14159265

#ifdef __unix__
#include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif
 
/*Functions to be integrated: */
double f(double x){
  return x*x;
}
double f1(double x){
    return pow(2.718281828,x);
}
double f2(double x){
    return cos(x);
}
double f3(double x){
    
    return pow(2.718281828,-(x*x));
}
double f4(double x){
    return (1/(1+(x*x)));
}
double f5(double x){
    return (1/(1+cos(x)));
}
double f6(double x){
    int y=pow(2.718281828,x)*cos(4*x);
    return y;
}
double f7(double x){
    return pow(x,2.5);
}
double f8(double x){
    return pow(2.718281828,cos(x));
}
double f9(double x){
    return sqrt(x);
}

double error(double trueValue, double estimatedValue){
    double y=fabs(trueValue-estimatedValue);
    double z= y/trueValue;
    return z;
}

 

int main(){



while(1){
  int n,i;
  double a,b,h,x,sum=0,integral;
  /*Ask the user for function input */
  char string[10];




    system("CLS");

  printf("\nEnter the integral:");
  scanf("%s",string);





  if(strcmp(string,"e^x")==0){
    printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n; //absolute
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f1(x);
  }
  integral=(h/2)*(f1(a)+f1(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %.13lf\n",integral);


  }




else if(strcmp(string,"x^2")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }
  integral=(h/2)*(f(a)+f(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %.13lf\n",integral);}






else if(strcmp(string,"cos(x)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f2(x);
  }
  integral=(h/2)*(f2(a)+f2(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %.13lf\n",integral);}







  else if(strcmp(string,"e^(-x^2)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f3(x);
  }
  integral=(h/2)*(f3(a)+f3(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %.13lf\n",integral);

  if(a==0 && b==1){
    double e=0.746824132;
  printf("\nERROR:%.6lf",error(e,integral));
  }

  }











    else if(strcmp(string,"1/(1+x^2)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f4(x);
  }
  integral=(h/2)*(f4(a)+f4(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %.13lf\n",integral);

  if(a==0&&b==4){
    double e=1.3258176;
    printf("\nERROR:%.6lf",error(e,integral));
  }
  }







      else if(strcmp(string,"1/(1+cosx)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f5(x);
  }
  integral=(h/2)*(f5(a)+f5(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %.13lf\n",integral);
  if(a==0&&b>=6.28){
    double e=3.627598;
    printf("\nERROR:%.6lf",error(e,integral));
  }
  }





        else if(strcmp(string,"e^(x)cos(4x)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f6(x);
  }
  integral=(h/2)*(f6(a)+f6(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %.13lf\n",integral);
  if(a==0&&b>=3.14){
    double e=1.30239;
    printf("\nERROR:%.6lf",error(e,integral));
  }
  }








        else if(strcmp(string,"x^(5/2)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f7(x);
  }
  integral=(h/2)*(f7(a)+f7(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %.13lf\n",integral);
  if(a==0&&b==1){
    double e=0.2857142;
  printf("\nERROR:%.6lf",error(e,integral));
  }
  }







        else if(strcmp(string,"e^(cosx)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f8(x);
  }
  integral=(h/2)*(f8(a)+f8(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %.13lf\n",integral);
  if(a<=-3.14&&b>=3.14){
    double e=7.95492;
  printf("\nERROR:%.6lf",error(e,integral));
  }
  else if(a==0&&b>=0.78){
    double e=1.93973;
    printf("\nERROR:%.6lf",error(e,integral));
  }
  }







          else if(strcmp(string,"sqrt(x)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f9(x);
  }
  integral=(h/2)*(f9(a)+f9(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %.13lf\n",integral);
  if(a==0&&b==1){
    double e=0.66667;
  printf("\nERROR:%.6lf\n\n",error(e,integral));
  }
  }




printf("\n\n\n--------The result will vanish in 10 seconds---------\n");


Sleep(10*1000);




}






return 0;

}
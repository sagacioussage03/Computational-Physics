
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
  double a,b,h,x,sum=0,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,integral,integral_trap,integral_newsimpson;
  /*Ask the user for function input */
  char string[10];




    system("CLS");

  printf("\nEnter the integral:");
  scanf("%s",string);




//---------------------------------------------------------------------------------------------------------------------
  if(strcmp(string,"e^x")==0){
    printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin simpson Method: */
  h=fabs(b-a)/n; //float absolute

  for(i=1;i<n;i=i+2){
    x=a+i*h;
    sum1=sum1+f1(x);
  }

    for(i=2;i<n-1;i=i+2){
        x=a+i*h;
        sum2=sum2+f1(x);
    }

/*Begin Trapezoidal*/
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f1(x);
  }


  integral_trap=(h/2)*(f1(a)+f1(b)+2*sum);
printf("\nThe integral (trapezoidal) is:%.13lf\n",integral_trap);

  integral=(h/3)*(f1(a)+f1(b)+4*sum1+2*sum2);
  printf("\nThe integral (simpson) is: %.13lf\n",integral);



  /*Begin SIMPSON-3/8*/

  for(i=3;i<=n-3;i=i+3){
    x=a+i*h;
    sum4=sum4+f1(x);
  }
  for(i=1;i<n;i++){
    x=a+i*h;
    sum5=sum5+f1(x);
  }
  sum3=sum5-sum4;


  integral_newsimpson=((3*h)/8)*(f1(a)+f1(b)+3*sum3+2*sum4);
  printf("\nThe integral (simpson-3/8) is: %.13lf\n",integral_newsimpson);


  }



//-----------------------------------------------------------------------------------------------------------------



else if(strcmp(string,"x^2")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);

  /*Begin simpson Method: */
  h=fabs(b-a)/n; //absolute

  for(i=1;i<n;i=i+2){
    x=a+i*h;
    sum1=sum1+f(x);
  }

    for(i=2;i<n-1;i=i+2){
        x=a+i*h;
        sum2=sum2+f(x);
    }


    
/*Begin Trapezoidal*/
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }
  integral_trap=(h/2)*(f(a)+f(b)+2*sum);
printf("\nThe integral (trapezoidal) is:%.13lf\n",integral_trap);



  integral=(h/3)*(f(a)+f(b)+4*sum1+2*sum2);


  
  printf("\nThe integral (simpson-1/3) is:%.13lf\n",integral);


    /*Begin SIMPSON-3/8*/

  for(i=3;i<=n-3;i=i+3){
    x=a+i*h;
    sum4=sum4+f(x);
  }
  for(i=1;i<n;i++){
    x=a+i*h;
    sum5=sum5+f(x);
  }
  sum3=sum5-sum4;


  integral_newsimpson=((3*h)/8)*(f(a)+f(b)+3*sum3+2*sum4);
  printf("\nThe integral (simpson-3/8) is: %.13lf\n",integral_newsimpson);
  
  }




//--------------------------------------------------------------------------------------------------------------

else if(strcmp(string,"cos(x)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);


  /*Begin simpson Method: */
  h=fabs(b-a)/n; //absolute

  for(i=1;i<n;i=i+2){
    x=a+i*h;
    sum1=sum1+f2(x);
  }

    for(i=2;i<n-1;i=i+2){
        x=a+i*h;
        sum2=sum2+f2(x);
    }


  /*Begin Trapezoidal*/
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f2(x);
  }
  integral_trap=(h/2)*(f2(a)+f2(b)+2*sum);
printf("\nThe integral (trapezoidal) is:%.13lf\n",integral_trap);



  integral=(h/3)*(f2(a)+f2(b)+4*sum1+2*sum2);


  
  printf("\nThe integral (simpson-1/3) is:%.13lf\n",integral);
  

    /*Begin SIMPSON-3/8*/

  for(i=3;i<=n-3;i=i+3){
    x=a+i*h;
    sum4=sum4+f2(x);
  }
  for(i=1;i<n;i++){
    x=a+i*h;
    sum5=sum5+f2(x);
  }
  sum3=sum5-sum4;


  integral_newsimpson=((3*h)/8)*(f2(a)+f2(b)+3*sum3+2*sum4);
  printf("\nThe integral (simpson-3/8) is: %.13lf\n",integral_newsimpson);
  }




//----------------------------------------------------------------------------------------------------------------


  else if(strcmp(string,"e^(-x^2)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);




  /*Begin simpson Method: */
  h=fabs(b-a)/n; //absolute

  for(i=1;i<n;i=i+2){
    x=a+i*h;
    sum1=sum1+f3(x);
  }

    for(i=2;i<n-1;i=i+2){
        x=a+i*h;
        sum2=sum2+f3(x);
    }

  
  /*Begin Trapezoidal*/
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f3(x);
  }
  integral_trap=(h/2)*(f3(a)+f3(b)+2*sum);
printf("\nThe integral (trapezoidal) is:%.13lf\n",integral_trap);




  integral=(h/3)*(f3(a)+f3(b)+4*sum1+2*sum2);

  
  printf("\nThe integral (simpson-1/3) is:%.13lf\n",integral);


  /*Begin SIMPSON-3/8*/

  for(i=3;i<=n-3;i=i+3){
    x=a+i*h;
    sum4=sum4+f3(x);
  }
  for(i=1;i<n;i++){
    x=a+i*h;
    sum5=sum5+f3(x);
  }
  sum3=sum5-sum4;


  integral_newsimpson=((3*h)/8)*(f3(a)+f3(b)+3*sum3+2*sum4);
  printf("\nThe integral (simpson-3/8) is: %.13lf\n",integral_newsimpson);


  if(a==0 && b==1){
    double e=0.746824132;
    printf("\nERROR(trapezoidal):%.12lf\n",error(e,integral_trap));
    printf("\nERROR(simpson-1/3):%.12lf\n\n",error(e,integral));
    printf("\nERROR(simpson-3/8):%.12lf\n\n",error(e,integral_newsimpson));
  }

  }










//------------------------------------------------------------------------------------------------------------------------
    else if(strcmp(string,"1/(1+x^2)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);



  /*Begin simpson Method: */
  h=fabs(b-a)/n; //absolute

  for(i=1;i<n;i=i+2){
    x=a+i*h;
    sum1=sum1+f4(x);
  }

    for(i=2;i<n-1;i=i+2){
        x=a+i*h;
        sum2=sum2+f4(x);
    }


/*Begin Trapezoidal*/
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f4(x);
  }
  integral_trap=(h/2)*(f4(a)+f4(b)+2*sum);
printf("\nThe integral (trapezoidal) is:%.13lf\n",integral_trap);




  integral=(h/3)*(f4(a)+f4(b)+4*sum1+2*sum2);



  
  printf("\nThe integral (simpson-1/3) is:%.13lf\n",integral);





    /*Begin SIMPSON-3/8*/

  for(i=3;i<=n-3;i=i+3){
    x=a+i*h;
    sum4=sum4+f4(x);
  }
  for(i=1;i<n;i++){
    x=a+i*h;
    sum5=sum5+f4(x);
  }
  sum3=sum5-sum4;


  integral_newsimpson=((3*h)/8)*(f4(a)+f4(b)+3*sum3+2*sum4);
  printf("\nThe integral (simpson-3/8) is: %.13lf\n",integral_newsimpson);


  if(a==0&&b==4){
    double e=1.3258176;
    printf("\nERROR(trapezoidal):%.12lf\n",error(e,integral_trap));
    printf("\nERROR(simpson-1/3):%.12lf\n\n",error(e,integral));
    printf("\nERROR(simpson-3/8):%.12lf\n\n",error(e,integral_newsimpson));
  }
  }





//-------------------------------------------------------------------------------------------------------------------------------

      else if(strcmp(string,"1/(1+cosx)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);


  /*Begin simpson Method: */
  h=fabs(b-a)/n; //absolute

  for(i=1;i<n;i=i+2){
    x=a+i*h;
    sum1=sum1+f5(x);
  }

    for(i=2;i<n-1;i=i+2){
        x=a+i*h;
        sum2=sum2+f5(x);
    }

/*Begin Trapezoidal*/
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f5(x);
  }
  integral_trap=(h/2)*(f5(a)+f5(b)+2*sum);
printf("\nThe integral (trapezoidal) is:%.13lf\n",integral_trap);





  integral=(h/3)*(f5(a)+f5(b)+4*sum1+2*sum2);



  
  printf("\nThe integral (simpson-1/3) is:%.13lf\n",integral);



    /*Begin SIMPSON-3/8*/

  for(i=3;i<=n-3;i=i+3){
    x=a+i*h;
    sum4=sum4+f5(x);
  }
  for(i=1;i<n;i++){
    x=a+i*h;
    sum5=sum5+f5(x);
  }
  sum3=sum5-sum4;


  integral_newsimpson=((3*h)/8)*(f5(a)+f5(b)+3*sum3+2*sum4);
  printf("\nThe integral (simpson-3/8) is: %.13lf\n",integral_newsimpson);



  if(a==0&&b>=6.28){
    double e=3.627598;
    printf("\nERROR(trapezoidal):%.12lf\n",error(e,integral_trap));
    printf("\nERROR(simpson-1/3):%.12lf\n\n",error(e,integral));
    printf("\nERROR(simpson-3/8):%.12lf\n\n",error(e,integral_newsimpson));
  }
  }



//-------------------------------------------------------------------------------------------------------------------------------

        else if(strcmp(string,"e^(x)cos(4x)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);


  /*Begin simpson Method: */
  h=fabs(b-a)/n; //absolute

  for(i=1;i<n;i=i+2){
    x=a+i*h;
    sum1=sum1+f6(x);
  }

    for(i=2;i<n-1;i=i+2){
        x=a+i*h;
        sum2=sum2+f6(x);
    }


/*Begin Trapezoidal*/
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f6(x);
  }
  integral_trap=(h/2)*(f6(a)+f6(b)+2*sum);
printf("\nThe integral (trapezoidal) is:%.13lf\n",integral_trap);



  integral=(h/3)*(f6(a)+f6(b)+4*sum1+2*sum2);




  
  printf("\nThe integral (simpson-1/3) is:%.13lf\n",integral);

  /*Begin SIMPSON-3/8*/

  for(i=3;i<=n-3;i=i+3){
    x=a+i*h;
    sum4=sum4+f6(x);
  }
  for(i=1;i<n;i++){
    x=a+i*h;
    sum5=sum5+f6(x);
  }
  sum3=sum5-sum4;


  integral_newsimpson=((3*h)/8)*(f6(a)+f6(b)+3*sum3+2*sum4);
  printf("\nThe integral (simpson-3/8) is: %.13lf\n",integral_newsimpson);


  if(a==0&&b>=3.14){
    double e=1.30239;
      printf("\nERROR(trapezoidal):%.12lf\n",error(e,integral_trap));
      printf("\nERROR(simpson-1/3):%.12lf\n\n",error(e,integral));
      printf("\nERROR(simpson-3/8):%.12lf\n\n",error(e,integral_newsimpson));
  }
  }





//----------------------------------------------------------------------------------------------------------------------------


        else if(strcmp(string,"x^(5/2)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);



  /*Begin simpson Method: */
  h=fabs(b-a)/n; //absolute

  for(i=1;i<n;i=i+2){
    x=a+i*h;
    sum1=sum1+f7(x);
  }

    for(i=2;i<n-1;i=i+2){
        x=a+i*h;
        sum2=sum2+f7(x);
    }


/*Begin Trapezoidal*/
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f7(x);
  }
  integral_trap=(h/2)*(f7(a)+f7(b)+2*sum);
printf("\nThe integral (trapezoidal) is:%.13lf\n",integral_trap);


  integral=(h/3)*(f7(a)+f7(b)+4*sum1+2*sum2);


  
  printf("\nThe integral (simpson-1/3) is:%.13lf\n",integral);


  /*Begin SIMPSON-3/8*/

  for(i=3;i<=n-3;i=i+3){
    x=a+i*h;
    sum4=sum4+f7(x);
  }
  for(i=1;i<n;i++){
    x=a+i*h;
    sum5=sum5+f7(x);
  }
  sum3=sum5-sum4;


  integral_newsimpson=((3*h)/8)*(f7(a)+f7(b)+3*sum3+2*sum4);
  printf("\nThe integral (simpson-3/8) is: %.13lf\n",integral_newsimpson);




  if(a==0&&b==1){
    double e=0.2857142;
    printf("\nERROR(trapezoidal):%.12lf\n",error(e,integral_trap));
    printf("\nERROR(simpson-1/3):%.12lf\n\n",error(e,integral));
    printf("\nERROR(simpson-3/8):%.12lf\n\n",error(e,integral_newsimpson));
  }
  }





//------------------------------------------------------------------------------------------------------------------------------

        else if(strcmp(string,"e^(cosx)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);


  /*Begin simpson Method: */
  h=fabs(b-a)/n; //absolute

  for(i=1;i<n;i=i+2){
    x=a+i*h;
    sum1=sum1+f8(x);
  }

    for(i=2;i<n-1;i=i+2){
        x=a+i*h;
        sum2=sum2+f8(x);
    }


/*Begin Trapezoidal*/
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f8(x);
  }
  integral_trap=(h/2)*(f8(a)+f8(b)+2*sum);
printf("\nThe integral (trapezoidal) is:%.13lf\n",integral_trap);



  integral=(h/3)*(f8(a)+f8(b)+4*sum1+2*sum2);


  
  printf("\nThe integral (simpson-1/3) is:%.13lf\n",integral);

  /*Begin SIMPSON-3/8*/

  for(i=3;i<=n-3;i=i+3){
    x=a+i*h;
    sum4=sum4+f8(x);
  }
  for(i=1;i<n;i++){
    x=a+i*h;
    sum5=sum5+f8(x);
  }
  sum3=sum5-sum4;


  integral_newsimpson=((3*h)/8)*(f8(a)+f8(b)+3*sum3+2*sum4);
  printf("\nThe integral (simpson-3/8) is: %.13lf\n",integral_newsimpson);


  if(a<=-3.14&&b>=3.14){
    double e=7.95492;
  printf("\nERROR(trapezoidal):%.12lf\n",error(e,integral_trap));
  printf("\nERROR(simpson-1/3):%.12lf\n\n",error(e,integral));
  printf("\nERROR(simpson-3/8):%.12lf\n\n",error(e,integral_newsimpson));
  }
  else if(a==0&&b>=0.78){
    double e=1.93973;
    printf("\nERROR(trapezoidal):%.12lf\n",error(e,integral_trap));
    printf("\nERROR(simpson-1/3):%.12lf\n\n",error(e,integral));
    printf("\nERROR(simpson-3/8):%.12lf\n\n",error(e,integral_newsimpson));
  }
  }





//-------------------------------------------------------------------------------------------------------------------------------

          else if(strcmp(string,"sqrt(x)")==0){

  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);


  /*Begin simpson Method: */
  h=fabs(b-a)/n; //absolute

  for(i=1;i<n;i=i+2){
    x=a+i*h;
    sum1=sum1+f9(x);
  }

    for(i=2;i<n-1;i=i+2){
        x=a+i*h;
        sum2=sum2+f9(x);
    }

/*Begin Trapezoidal*/
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f9(x);
  }
  integral_trap=(h/2)*(f9(a)+f9(b)+2*sum);
printf("\nThe integral (trapezoidal) is:%.13lf\n",integral_trap);



  integral=(h/3)*(f9(a)+f9(b)+4*sum1+2*sum2);


  
  printf("\nThe integral (simpson-1/3) is:%.13lf\n",integral);


  /*Begin SIMPSON-3/8*/

  for(i=3;i<=n-3;i=i+3){
    x=a+i*h;
    sum4=sum4+f9(x);
  }
  for(i=1;i<n;i++){
    x=a+i*h;
    sum5=sum5+f9(x);
  }
  sum3=sum5-sum4;


  integral_newsimpson=((3*h)/8)*(f9(a)+f9(b)+3*sum3+2*sum4);
  printf("\nThe integral (simpson-3/8) is: %.13lf\n",integral_newsimpson);




  if(a==0&&b==1){
    double e=0.66667;
  printf("\nERROR(trapezoidal):%.12lf\n",error(e,integral_trap));
  printf("\nERROR(simpson-1/3):%.12lf\n\n",error(e,integral));
  printf("\nERROR(simpson-3/8):%.12lf\n\n",error(e,integral_newsimpson));
 
  }
  }




printf("\n\n\n--------The result will vanish in 15 seconds---------\n");


Sleep(15*1000);




}






return 0;

}
/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>



void solveGaussElimination(double matrix[][11], int m, int n) {//Dimensions of augmented matrix
    int i, j, k;
    int p,q;

    for (i = 0; i < m; i++) {
        printf("\n\n\n\nPivot for iteration %d:%ld\n",i+1,matrix[i][i]);
        for (j = i + 1; j < m; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            printf("\n%ld\n",factor);
            for (k = 0; k < n; k++) {
                printf("\n%ld=%ld-%ld*%ld\n",matrix[j][k],matrix[j][k],factor,matrix[i][k]);
                matrix[j][k] = matrix[j][k] - factor * matrix[i][k];
            }
        }

        Sleep(3000);
        printf("\nMatrix after iteration %d:\n\n",i+1);

        for (p = 0; p < m; p++) {
        for (q = 0; q < n; q++) {
            printf("%ld ", matrix[p][q]);
        }
        printf("\n\n");
        }
        

    }

}



int main() {
    int m, n;
    int i, j;
    printf("Enter the dimensions of the matrix:\n");
    scanf("%d %d", &m, &n);

    double augmentedMatrix[10][11]; // Assuming maximum size of 10x11
    printf("Enter the augmented matrix:\n");
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%ld", &augmentedMatrix[i][j]);
        }
    }

    printf("\n\nOriginal Augmented Matrix:\n\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("%ld ", augmentedMatrix[i][j]);
        }
        printf("\n");
    }

    solveGaussElimination(augmentedMatrix, m, n + 1);

    printf("\n\nAfter Gaussian Elimination:\n\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("%ld ", augmentedMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define   SIZE   10

int main()
{
	 float a[SIZE][SIZE], x[SIZE], ratio;
	 int i,j,k,n;
	

	
	 /* Inputs */
	 /* 1. Reading number of unknowns */
	 printf("Enter number of unknowns: ");
	 scanf("%d", &n);
	 /* 2. Reading Augmented Matrix */
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++) //augmented
		  {
			   printf("a[%d][%d] = ",i,j);
			   scanf("%f", &a[i][j]);
		  }
	 }
	/* Applying Gauss Elimination */
	 for(i=1;i<=n-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   printf("Mathematical Error!");
			   exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = a[j][i]/a[i][i];
			   
			   for(k=1;k<=n+1;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }
	 /* Obtaining Solution by Back Subsitution */
	 x[n] = a[n][n+1]/a[n][n];
	
	 for(i=n-1;i>=1;i--)
	 {
		  x[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }
	 /* Displaying Solution */ 
	 printf("\nSolution:\n");
	 for(i=1;i<=n;i++)
	 {
	  	printf("x[%d] = %0.3f\n",i, x[i]);
	 }

	 return(0);
}
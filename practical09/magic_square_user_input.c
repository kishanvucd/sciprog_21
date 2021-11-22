#include<stdio.h>
#include<stdlib.h>
#include "magic_square.h" //Include magic square header file for using isMagicSquare function

int main(){
   
   //Declare variables
   int n;
   printf("Enter the square side:\n");
   scanf("%d", &n); //Get square side from user

   //Allocate a matrix
   int i,j; //Loop variables
   int ** magicSquare = malloc(n * sizeof(int)); //Dynamic memory allocation for square matrix
   
   for(i=0;i<n;i++){
      magicSquare[i] = malloc(n * sizeof(int)); //Dynamic memory allocation for square matrix rows
   }
   
   //define square matrix
   for(i=0;i<n;i++){
      printf("Enter the elements in row %d, separated by blanks and/or linebreaks:\n", i+1);
      for(j=0;j<n;j++){
         scanf("%d", &magicSquare[i][j]); //Get square matrix elements from user
      }
   }
   
   //Check and print whether the square matrix is magic square or not
   printf("The square %s magic \n", isMagicSquare(magicSquare, n) ? "is" : "is NOT");
   for(i=0;i<n;i++){
      free(magicSquare[i]); //free dynamically allocated memory for square matrix 
   }

   return 0;
}

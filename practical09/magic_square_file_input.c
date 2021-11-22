#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE_NAME 100 // Define max 100 char for file name 
#include "magic_square.h" //Include magic square header file for using isMagicSquare function

//Declare and define function
//Read from file and return number of lines count
int getlines(char filename[MAX_FILE_NAME]){

   FILE *fp;
   fp = fopen(filename, "r"); //Open file in read mode
   
   int ch_read;
   int count = 0;
   //get input from file until End of file(EOF)
   while( (ch_read = fgetc(fp)) != EOF){
      if (ch_read == '\n') //Increase count for every new line char to calculate number of lines
         count++;
   }
   printf("No. of lines %d\n", count);
   fclose(fp); //Close the opened file
   return count; //Return line count
}

int main(){
 
   //Declare variables
   FILE *f;  //Declare pointer of type FILE
   char filename[MAX_FILE_NAME]; //Declare filename char array with 100 size
   printf("Enter file name: "); //Print statement for user  
   scanf("%s", filename); //Get filename from user

   f = fopen(filename, "r"); //Open file in read mode
    
   int n = getlines(filename);  //Call getlines function

   //Allocate a matrix
   int i,j;
   int ** magicSquare = malloc(n * sizeof(int*)); //Dynamic memory allocation for square matrix 
   
   for(i=0;i<n;i++){
      magicSquare[i] = malloc(n * sizeof(int)); //Dynamic memory allocation for square matrix rows
   }

   for(i=0;i<n;i++){
      for(j=0;j<n;j++){
         fscanf(f, "%d", &magicSquare[i][j]); //Get square matrix elements from file
      }
   }
   
   //Check and print whether the square matrix is magic square or not
   printf("The square %s magic \n", isMagicSquare(magicSquare, n) ? "is" : "is NOT");
   for(i=0;i<n;i++){
      free(magicSquare[i]); //free dynamically allocated memory for square matrix
   }
   fclose(f); //Close the opened file

   return 0;
}

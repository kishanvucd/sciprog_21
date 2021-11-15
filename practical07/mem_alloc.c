#include<stdio.h>
#include<stdlib.h>

//Declare and Define functions
//Dynamic memory allocation of integer array
int* allocatearray(int n){
   int* array;
   array = (int*) malloc(n * sizeof(int));
   printf("Array of size %d allocated.\n", n);
   return array;
}

// fill array of integers with 1 value
void fillwithones(int* array, int n){
   int i;
   for(i=0;i<n;i++)
      array[i] = 1;
}

//print the array of integers
void printarray(int* array, int n){
   int i;
   for(i=0;i<n;i++)
      printf("%d ", array[i]);
      printf("\n");
}

//Free allocated memory of integer array
void freearray(int* array){
   free(array);
   printf("Array freed\n");
}

int main() {
   //variable declaration
   int n, *array_main;

   printf("Enter the number of elements in the array: ");
   scanf("%d", &n); //get array size from user
   
 
   array_main = allocatearray(n); //Dynamic memory allocation of integer array
   fillwithones(array_main, n); // fill array of integers with 1 value
   printarray(array_main, n); //print the array of integers
   freearray(array_main); //Free allocated memory of integer array
   array_main = NULL; //set pointer to null

   return 0;
}

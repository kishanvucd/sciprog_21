#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Declare and define functions
//Compute factorial
int factorial(int n){
   if(n==0)
      return 1;       
   
   return n * factorial(n - 1);
}

//Compute polynomial
double polynomial(int n,int x){
   double sum = 0.0;
   int i;

   for(i=0;i<=n;i++)
      sum += (double)pow(x,i) / factorial(i);
   return sum;
}

int main() {

   //declare variables
   int order_of_polynomial;
   int size_of_array;
   double* array_of_terms;
   int i,x=1;
 
   printf("Enter the order of polynomial: ");
   scanf("%d", &order_of_polynomial); //get input from user

   size_of_array = order_of_polynomial + 1; //defining array size
   array_of_terms = (double *) malloc(size_of_array * sizeof(double)); //dynamic memory allocation of integer array

   //Compute polynomial 
   for(i=0;i<size_of_array;i++){
      array_of_terms[i] = polynomial(i,x);
      printf("f[%d] = %0.20f\n", i, array_of_terms[i]);
   }

   //Print actual result
   printf("e1 = %0.20f\n", exp(1));

   //Print difference between actaul and computed result
   for(i=0;i<size_of_array;i++){
      printf("Estimate difference for term %d is %0.20f\n", i, exp(1) - array_of_terms[i]);
   }
   free(array_of_terms); //Free allocated memory of integer array
   array_of_terms = NULL; //Set pointer to null

/* Here, Something strange happens with the higher order polynomials the
 estimate gets worse because while computing factorial using factorial
 function that returns integer so for higher factorials like 34! it
 returns 0 because of C integer data type limitation and while computing
 polynomials it divides by 0(return by factorial function for higher values)
 gives infinity and difference with actual result becomes - infinity
*/

   return 0;
}

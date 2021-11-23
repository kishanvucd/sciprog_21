#include<stdio.h>

//Declare and define functions
//Computing gcd using iterative function
int iterativeGCD(int a,int b){
   int temp;
   while(b != 0){
      temp=b;
      b=a%b;
      a=temp;
   }
   return a;
}

//Computing gcd using recursive function
int recursiveGCD(int a, int b){
   if(b==0)
      return a;
   else
      return(recursiveGCD(b, a%b));
}

int main(void){
   //declare variables
   int a,b,error;

   printf("Please inpute two positive integers\n");
   error = scanf("%d %d",&a,&b); //get two positive integers from user
   //checking for two inputs from user if not found then terminate with error message
   if(error != 2){
      printf("Please try again\n");
      return 1;
   }
   
   //checking for negative numbers and if found then terminate with error message
   if(a<=0 || b<=0){
      printf("These numbers are not positive!\n");
      return 1;
   }

   //Print and calling gcd functions
   printf("Iterative gcd(%d,%d)=%d\n", a, b, iterativeGCD(a,b));
   printf("Recursive gcd(%d,%d)=%d\n", a, b, recursiveGCD(a,b));

   return 0;
}

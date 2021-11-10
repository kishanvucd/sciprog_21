#include<stdio.h>
#include<stdlib.h>

//function declaration
void fibonacci(int *a, int *b);

int main() {
   //declare variables
   int n;
   printf("Enter a positive integer for n: \n");
   scanf("%d", &n); //getting value for n from user

   if(n < 1){
      printf("Number is less than 1\n");
      exit(1);   //terminate the code if number is less than 1
   }

   //declare variables for first two number in fibonacci sequence 
   int n1=0;
   int n2=1;
   
   //print first number of sequence
   printf("The Fibonacci sequence :\n");
   printf("%d, ", n1);
  
   //print sequence upto n-1 number
   int i;
   for(i=1;i<n-1;i++){
      fibonacci(&n1,&n2); //calling function as pass by refrence
      printf("%d, ", n1);
   }

   //print last number of sequence
   fibonacci(&n1, &n2);   
   printf("%d\n", n1);
  
   return 0;
}

//calculate fibonacci sequence
void fibonacci(int *a, int *b){
   int next;
   next = *a+*b;
   *a=*b;
   *b=next;
}

#include<stdio.h>
#include<math.h>

//function declaration
double arctanh1(const double x, const double delta);
double arctanh2(const double x);

int main(){

   //variable declaration
   double prec;
   printf("Enter precision for the Maclaurin series:\n");
   scanf("%lf", &prec);  //get input for precision from user
   
   double st,en;
   printf("Enter the start and finish points for x:\n");
   scanf("%lf, %lf", &st, &en); //get input for Start and finish points from user
  
   //calculate size 
   double a = (fabs(st) + fabs(en)/prec) + 1.;
   int asize = a;

   //array declaration
   double tan1[asize];
   double tan2[asize];

   //calculate hyperbolic arc tangent by Maclaurin Series and by natural logarithms
   double i;
   int j = 0; 
   for(i = st; i<= en; i+=prec){
      tan1[j] = arctanh1(i, prec);
      tan2[j] = arctanh2(i);
      printf("The difference between tan1[%.3lf] and tan2[%.3lf] is %.10lf.\n", i, i, fabs(tan1[j] - tan2[j]));
      j++;
   }   
   
   return 0;
}

//Calculate using Maclaurin Series
double arctanh1(const double x, const double delta){
   double arcTan = 0;
   double elem;
   int n = 0;
   do {
      double val = 2*n +1;
      elem = pow(x, val)/val;
      arcTan += elem;
      n++;
   }while(fabs(elem) >= delta);
   return arcTan;
}

//calculate using natural logarithms
double arctanh2(const double x){
   return (log(1 + x) - log(1 - x))/2;
}

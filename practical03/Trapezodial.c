#include<stdio.h>
#include<math.h>

int main(){
  
  //Declare Variables
  int N=12, i;
  float a=0.0, b_deg=60.0;

  //Convert degree to radians
  float b_rad;
  b_rad=(M_PI * b_deg)/180.0;
  
  //Calculate f(x0)+f(xN)
  float area=tan(a)+tan(b_rad);

  //Calculate 2*[f(x1)+f(x2)...+f(xn-1)]
  for(i=5; i<60; i+=5){
    area=area+2*tan((M_PI*i)/180.0);
  }

  //Multiply with b-a/2N
  float mult_rad=M_PI*((b_deg-a)/(2*N)/180.0);
  area=mult_rad*area;

  //Trapezodial result value
  printf("Trapezodial result=%f\n", area);
  //Actual result
  printf("Real result=%f\n", log(2.0));
  
return 0;
}

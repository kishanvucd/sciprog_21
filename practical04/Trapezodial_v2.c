#include<stdio.h>
#include<math.h>

//Declare functions globally
float degtorad(float degang);
float trapezodialcalc(int N, float TanArr[N+1]);

int main(){
  
  //Declare variables
  int N=12, i;
  float TanArr[N+1], deg, rad;

  // Calculate the values of f(xi) where i=0, 1, ..., 12
  // as array elements (xi in radians)
  for(i=0; i<=N; i++){
    deg=i*5.0;
    rad=degtorad(deg); // Calling degtorad function as pass by value
    TanArr[i]=tan(rad);    
  }
  
  //Find the area by trapezodial rule
  float area;
  area=trapezodialcalc(N, TanArr); // Calling trapezodialcalc function as pass by value

  //Trapezodial result value
  printf("Trapezodial result: %f\n", area);
  //Actual value
  printf("Real Result: %f\n", log(2.0));

return 0;
}

float degtorad(float degang){
  return((M_PI*degang)/180.0);
}

float trapezodialcalc(int N, float TanArr[N+1]){
  
  // Declare local variables
  int i;
  float area;

  // Calculate f(x0)+2*[f(x1)+f(x2)+...+f(xn-1)]+f(xn) 
  area=TanArr[0]+TanArr[N];
  for(i=1; i<N; i++){
    area=area+2.0*TanArr[i];  
  }
  
  //Multiply area by (pi/3)/2N after converting it to radians
  float mult_rad=degtorad((60.0-0.0)/(2.0*N));
  area=mult_rad*area;
  return area;
}

#include<stdio.h>

int main(){

	//variable declaration	
	int n=5,p=3,q=4;
	double a[n][p],b[p][q],c[n][q]; //3 matrices of 2 dimensional
	
	//variable declaration for loops
	int i,j,k;
	
	//initialize mateix C with 0.0 
	for(i=0;i<n;i++){
		for(j=0;j<q;j++){
			c[i][j]=0.0;
			
		}
	}

	//initialize matrix A with Aij = i+j	
	for(i=0;i<n;i++){
		for(j=0;j<p;j++){
			a[i][j]=i+j;
			
		}
	}
	
	//initialize matrix B with Bij = i-j
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			b[i][j]=i-j;
			
		}
	}
	
	//function call from matmult.c file
	matmult(n,p,q,a,b,c);
	
	//print matrix A
	printf("Matrix A is : \n");
	for(i=0;i<n;i++){
		for(j=0;j<p;j++){
			printf("%4.0f",a[i][j]);
			
		}
		printf("\n");
	}
	
	//print matrix B
	printf("Matrix B is : \n");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			printf("%4.0f",b[i][j]);
			
		}
		printf("\n");
	}


	//print matrix C	
	printf("Matrix C after multiplication of matrices A and B is : \n");
	for(i=0;i<n;i++){
		for(j=0;j<q;j++){
			printf("%4.0f",c[i][j]);
			
		}
		printf("\n");
	}
	
	
	
	return 0;
	
}

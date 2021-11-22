#include<stdio.h>
#include<stdlib.h>

//Declare function
void hanoi(int, int, int, int);

void main(){
  
        //Declare variables
	int n;
	printf("Enter number of disks : \n");
	scanf("%d",&n); //get number of disks input from user
	printf("Tower of hanoi solution for %d disks : \n",n);
	hanoi(n,1,3,2);	//Call hanoi function
}

//Function Defination
//Print sequence of moves required to solve puzzle for n(user input) disks
void hanoi(int n,int source, int dest, int mid){
	
	if(n==1){
		printf("Moved disk %d from %d to %d\n",n,source,dest); //Move nth disc from rod 1 to rod 3
	}
	
	else{
		hanoi(n-1,source,mid,dest);  //Recursive function call to move n - 1 discs from rod 1 to rod 2, using rod 3 as an intermediary
		printf("Moved disk %d from %d to %d\n",n,source,dest);
		hanoi(n-1,mid,dest,source);  //Recursive function call to move the n - 1 discs from rod 2 to rod 3, using rod 1 as an intermediary.
	}
	
}

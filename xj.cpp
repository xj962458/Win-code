#include<stdio.h>
int main(){
	int i,j;
	for(i=1;i<=9;i++){
		for(int j=i;j<=9;j++)
			printf("%d*%d=%d ",i,j,i*j);
		printf("\n");
	}
}



#include <stdio.h>
int max(int a,int b){return a>b?a:b;}
int main(){
	printf("Enter capacity and number of items -\n");
	int w,n;
	scanf("%d %d",&w,&n);
	printf("Enter weight and value for each item -\n");
	int weight[100],value[100];
	for(int i=0;i<n;i++) scanf("%d %d",&weight[i],&value[i]);
	int matrix[100][100];
	for(int i=0;i<=n;i++) for(int j=0;j<=w;j++) matrix[i][j]=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++){
			if(j<weight[i-1]) matrix[i][j] = matrix[i-1][j];
			else{
				matrix[i][j] = max(matrix[i-1][j],value[i-1]+matrix[i-1][j-weight[i-1]]);
			}
		}
	}
	printf("The best value is - %d\n",matrix[n][w]);
	printf("The items in the bag are - \n");

	int i=n,j=w;
	while(i>0 && j>0){
		if(matrix[i][j] == matrix[i-1][j])
			i--;
		else{
			printf("%d ",i);
			i--;
			j-=weight[i];
		}
	}
	return 0;
}
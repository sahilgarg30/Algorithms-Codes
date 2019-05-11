#include <stdio.h>
int n,d,arr[100];

int subsetSum(int cur,int curSum,int size,int nos[]){
	if(cur==n && curSum == d){
		for(int i=0;i<size;i++) printf("%d ",nos[i]);
		printf("\n");
		return 1;
	}
	if(cur==n) return 0;

	nos[size]=arr[cur];
	size++;
	int a = subsetSum(cur+1,curSum+arr[cur],size,nos);
	size--;
	int b = subsetSum(cur+1,curSum,size,nos);
	return a+b;
}

int main(){
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	printf("The subsets are - \n");
	int nos[100];
	int res = subsetSum(0,0,0,nos);
	printf("The number of subsets are - %d.\n",res);
	return 0;
}
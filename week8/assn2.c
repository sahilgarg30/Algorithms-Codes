#include <stdio.h>
#include <stdio.h>

int subsetSum(int arr[],int n,int i){
	if(i==1<<n) return 0;

	int first=-10000,last=-10000;
	for(int j=0;j<n;j++){
		if(i & (1<<j)){
			if(first==-10000) first = arr[n-j-1];
			last = arr[n-j-1];
		}
	}

	return (first - last) + subsetSum(arr,n,i+1);
}

int main(){
	int n,arr[100];
	printf("Enter no - \n");
	scanf("%d",&n);
	printf("Enter elements - \n");
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	printf("The subset sum for diff between first and last element is - \n");
	printf("%d \n",subsetSum(arr,n,0));
	return 0;
}
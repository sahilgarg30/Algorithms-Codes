#include <stdio.h>
#include <stdlib.h>

int swap(int *a,int *b){
	int temp = *a; *a = *b; *b = temp;
}
int partition(int arr[],int l,int r){
	int pivot = arr[l];
	int i=l+1,j=r;
	while(i<=j){
		while(arr[i]<pivot) {i++;}
		while(arr[j]>pivot) {j--;}
		if(i<=j){swap(&arr[i],&arr[j]);i++;j--;}
	}
	swap(&arr[j],&arr[l]);
	return j;
}

void quicksort(int arr[],int l,int r){
	if(l>=r) return;

	int p = partition(arr,l,r);
	quicksort(arr,l,p-1);
	quicksort(arr,p+1,r);
}
int main(){
	int n,arr[100];
	printf("Enter size -\n");
	scanf("%d",&n);
	printf("Enter array - \n");
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	printf("Quick Sorted array - \n");
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	return 0;
}
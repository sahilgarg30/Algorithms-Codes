#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l,int r,int mid){
	int i=l;int j=mid+1;
	int narr[100],c=0;

	while(i<=mid && j<=r){
		if(arr[i]<arr[j]){narr[c++]=arr[i];i++;}
		else{narr[c++]=arr[j];j++;}
	}
	while(i<=mid){narr[c++]=arr[i++];}
	while(j<=r){narr[c++]=arr[j++];}
	for(int i=0;i<c;i++){
		arr[l+i]=narr[i];
	}
}

void mergeSort(int arr[],int l,int r){
	if(l>=r) return;
	int mid = (l+r)/2;
	mergeSort(arr,l,mid);
	mergeSort(arr,mid+1,r);
	merge(arr,l,r,mid);
}

int main(){
	int n,arr[100];
	printf("Enter size -\n");
	scanf("%d",&n);
	printf("Enter array - \n");
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	mergeSort(arr,0,n-1);
	printf("Merge Sorted array - \n");
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	return 0;
}
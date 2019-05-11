#include <stdio.h>
#include <stdio.h>
#include "heap.h"

void topDown(int arr[],int heap[],int n){
	for(int i=0;i<n;i++){
		heap[i] = arr[i];
		shiftUp(heap,i);
	}
}	

int main(){
	int n,arr[100],heap[100];
	printf("Enter no - \n");
	scanf("%d",&n);
	printf("Enter elements - \n");
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	printf("The heap is - \n");
	topDown(arr,heap,n);
	for(int i=0;i<n;i++) printf("%d ",heap[i]);
	return 0;
}
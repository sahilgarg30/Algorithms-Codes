#include <stdio.h>
#include <stdio.h>
#include "heap.h"

void heapify(int heap[],int n){
	for(int i=n/2;i>=0;i--){
		shiftDown(heap,i,n);
	}
}

int main(){
	int n,arr[100],heap[100],sorted[100];
	printf("Enter no - \n");
	scanf("%d",&n);
	printf("Enter elements - \n");
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		
		heap[i] = arr[i];
	}
	printf("The sorted array is - \n");
	heapify(heap,n);
	for(int i=0;i<n;i++){
		sorted[n-i-1] = extractMax(heap,n-i);
		heapify(heap,n-i);
	}
	for(int i=0;i<n;i++) printf("%d ",sorted[i]);
	return 0;
}
#include <stdio.h>
#include <stdio.h>

void swap(int *a,int *b){
	int temp = *a; *a = *b; *b = temp; 
}
void shiftUp(int arr[],int i){
	if(i==0) return;
	if(arr[i] > arr[i/2]){
		swap(&arr[i],&arr[i/2]);
		shiftUp(arr,i/2);
	}
}
void shiftDown(int arr[],int i,int n){
	int index = 2*i+1;
	int greater = arr[i];
	if(index < n && arr[index]>greater){
		greater = arr[index];
	}
	if(index+1 < n && arr[index+1]>greater){
		greater = arr[index+1];
		index++;
	}

	if(greater != arr[i]){
		swap(&arr[i],&arr[index]);
		shiftDown(arr,index,n);
	}
}

int extractMax(int heap[],int n){
	int val = heap[0];
	heap[0] = heap[n-1];
	shiftDown(heap,0,n);
	return val;
}
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,j;
	printf("Enter n - ");
	scanf("%d",&n);
	int arr[100];
	printf("Enter the elements - ");
	for(i=0;i<n;i++) //scanf("%d",&arr[i]);
		arr[i] = n-i;

	int sorted = 0;
	int opcount=0;
	for(i=0;i<n-1;i++){
		sorted = 0;
		for(j=0;j<n-i-1;j++){
			opcount++;
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				sorted = 1;
			}
		}
		if(sorted==0) break;
	}

	for(i=0;i<n;i++) printf("%d  ",arr[i]);
	printf("\n %d \n",opcount);
	return 0;
}
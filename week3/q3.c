#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j,n;
	int p;
	printf("Enter n -\n");
	scanf("%d",&n);
	int arr[100];
	for(i=0;i<n;i++) scanf("%d",&arr[i]);

	if(n<2){
		printf("Not possible.\n");
		return 0;
	}

	for(p=0;p < 1<<n - 1;p++){
		int cur = p;
		int sum1=0,sum2=0;
		for(i=0;i<n;i++){
			if(cur%2==0) sum1+=arr[i];
			else sum2+=arr[i];
			cur/=2;
		}
		if(sum1==sum2){
			cur = p;
			printf("\nset 1 - ");
			for(i=0;i<n;i++){
				if(cur%2==0) printf("%d ",arr[i]);
				cur/=2;
			}
			printf("\nset 2 - ");
			cur = p;
			for(i=0;i<n;i++){
				if(cur%2!=0) printf("%d ",arr[i]);
				cur/=2;
			}
			return 0;
		}
	}

	printf("No subset found.\n");
	return 0;
}
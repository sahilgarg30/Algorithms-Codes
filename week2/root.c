#include <stdio.h>

unsigned int root(unsigned int m){
	int l = 1,r=m;

	while(l<=r){
		int mid = (l+r)/2;
		int prod = mid*mid;
		if(prod == m)
			return mid;

		if(prod < m)
			l = mid+1;
		else
			r = mid-1;
	}

	return r;
}

int main(){
	unsigned int m;
	scanf("%d",&m);
	printf("\nRoot - %d\n",root(m));
	return 0;
}
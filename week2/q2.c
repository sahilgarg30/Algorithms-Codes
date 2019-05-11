#include <stdio.h>
#include <stdlib.h>

int primes[100005];

void seive(int n){
	int i,j;
	for(i=0;i<=n;i++) primes[i] = 0;

	for(i=2;i*i<=n;i++){
		if(!primes[i]){
			for(j=i*i;j<=n;j=j+i)
				primes[j] = 1;
		}
	}
}
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int t = a>b?b:a;
	seive(t);
	int res = 1,i=2;

	while(a!=1 && b!=1 && i<=t){
		if(!primes[i] && a%i == 0 && b%i==0){
			res *= i;
			a /= i;
			b /= i;
		}
		else
			i++;
	}

	printf("%d\n",res);
	return 0;
}
#include <stdio.h>
int n,W,weights[100],val[100],vw[100];
int mp=0,ub=0;

void swap(int *a,int *b){
	int temp = *a; *a = *b; *b = temp;
}

void sortItems(){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(vw[j]<vw[j+1]){
				swap(&weights[j],&weights[j+1]);
				swap(&val[j],&val[j+1]);
				swap(&vw[j],&vw[j+1]);
			}
		}
	}
}

void knapsack(int cur,int curProfit,int curwt){
	int ub1,ub2;
	if(weights[cur]+curwt > W) ub1 = -1;
	else ub1 = (val[cur]+curProfit) + (W-(curwt+weights[cur]))*vw[cur+1];

	ub2 = curProfit + (W-curwt)*vw[cur+1];

	if(cur==n-1){
		if(ub1>ub) {mp = curProfit+val[cur]; ub=ub1;}
		if(ub2>ub) {mp = curProfit;ub=ub2;}
		return;
	}
	if(ub1 >= ub2){
		if(ub2 > ub){mp = curProfit;ub=ub2;}
		knapsack(cur+1,curProfit+val[cur],curwt+weights[cur]);
	}else{
		if(ub1 > ub){mp = curProfit+val[cur]; ub=ub1;}
		knapsack(cur+1,curProfit,curwt);
	}
}

int main(){
	scanf("%d %d",&n,&W);
	for(int i=0;i<n;i++){
		scanf("%d %d",&weights[i],&val[i]);
		vw[i] = val[i]/weights[i];
	}
	vw[n]=0;
	sortItems();
	knapsack(0,0,0);
	printf("Maximum profit - %d \n",mp);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	float price;
	float number;
} Buying;

Buying getAverage(Buying* pBuying, int n);

int main(){
	int n;
	scanf("%d", &n);
	Buying *buy=(Buying*)malloc(sizeof(Buying)*n);

	for(int i=0; i<n; i++)
		scanf("%f%f", &buy[i].price, &buy[i].number);

	Buying res;
	res=getAverage(buy, n);

	printf("%.2f %.2f\n", res.price, res.number);
	free(buy);

	return 0;
}

Buying getAverage(Buying* buy, int n){
	Buying res;
	res.price=0; res.number=0;
	for(int i=0; i<n; i++){
		res.price += buy[i].price;
		res.number += buy[i].number;
	}

	res.price /= n;
	res.number /= n;

	return res;
}


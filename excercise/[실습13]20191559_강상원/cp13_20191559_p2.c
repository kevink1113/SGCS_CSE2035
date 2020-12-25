#include <stdio.h>
struct CoinBox{
	int n500;
	int n100;
	int n50;
	int n10;
};

int main(){
	int price;
	scanf("%d", &price);
	struct CoinBox res={0, 0, 0, 0};

	res.n500=price/500;
	price=price-(price/500)*500;

	res.n100=price/100;
	price=price-(price/100)*100;

	res.n50=price/50;
	price=price-(price/50)*50;

	res.n10=price/10;
	price=price-(price/10)*10;

	printf("%d\n%d\n%d\n%d\n", res.n500, res.n100, res.n50, res.n10);

	return 0;
}

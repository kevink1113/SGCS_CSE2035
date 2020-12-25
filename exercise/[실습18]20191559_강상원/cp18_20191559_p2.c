#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union utemp{
	int i;
	float f;
	double d;
};

typedef struct stemp{
	int type;
	char name[20];
	union utemp u;
} stemp;

void power (stemp *s);

int main() {
	int n, type;
	printf("Number of iterations : ");
	scanf("%d", &n);
	
	stemp* arr=(stemp*)malloc (sizeof(stemp)*n);

	for(int i=0; i<n; i++){
		printf("Type [1 for int, 2 for float, 3 for double] : ");
		scanf("%d", &arr[i].type);

		switch (arr[i].type) {
			case 1:
				strcpy(arr[i].name, "integer");
				printf("Enter an integer value : ");
				scanf("%d", &arr[i].u.i);
				break;
			case 2:
				strcpy(arr[i].name, "float");
				printf("Enter a float value : ");
				scanf("%f", &arr[i].u.f);
				break;
			case 3:
				strcpy(arr[i].name, "double");
				printf("Enter a double value : ");
				scanf("%lf", &arr[i].u.d);
				break;
		}
	}

	printf("-----------Result-----------\n");
	for(int i=0; i<n; i++){
		power(&arr[i]);

		switch (arr[i].type) {
			case 1:
				printf("%-10s : %d\n", arr[i].name, arr[i].u.i);
				break;
			case 2:
				printf("%-10s : %.4f\n", arr[i].name, arr[i].u.f);
				break;
			case 3:
				printf("%-10s : %.4lf\n", arr[i].name, arr[i].u.d);
				break;
		}
	}
	free(arr);

	return 0;
}

void power (stemp *s){
	switch (s-> type){
		case 1:
			s->u.i *= s->u.i;
			break;
		case 2:
			s->u.f *= s->u.f;
			break;
		case 3:
			s->u.d *= s->u.d;
			break;
	}
}

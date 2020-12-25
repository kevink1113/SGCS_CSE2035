#include <stdio.h>
char* arr;
enum Date{Sunday=0, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
struct Calendar{
		int year, month, day;
		enum Date date;
		char* dateString;
	};
enum Date getDate(int y, int m, int d);
char* getDay(enum Date currDate);

int main(){
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);
	int realdate=getDate(y, m, d);
	getDay(realdate);
	
	struct Calendar res={y, m, d, realdate, arr};
	
	printf("%s\n", arr);
	return 0;
}

enum Date getDate(int y, int m, int d){
	return (y+y/4-y/100+y/400+(13*m+8)/5+d)%7;
}

char* getDay(enum Date currDate){
	
	arr=(char*)(sizeof(char)*10);
	if (currDate==0) return "Sunday";
	else if (currDate==1) arr="Monday";
	else if (currDate==2) arr="Tuesday";
	else if (currDate==3) arr="Wednesday";
	else if (currDate==4) arr="Thursday";
	else if (currDate==5) arr="Friday";
	else if (currDate==6) arr="Saturday";
	else arr=0;

	return arr;
}



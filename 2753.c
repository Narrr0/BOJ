#include <stdio.h>

/*
연도가 주어졌을 때, 윤년이면 1, 아니면 0을 출력하는 프로그램을 작성하시오.
윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.
*/

int main() {
	int year;
	scanf("%d",&year);
	if (year % 400 == 0)
		printf("1");
	else if (year % 100 == 0)
		printf("0");
	else if (year % 4 == 0)
		printf("1");
	else
		printf("0");
}
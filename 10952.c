#include <stdio.h>

/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
입력은 여러 개의 테스트 케이스로 이루어져 있다.
입력의 마지막에는 0 두 개가 들어온다.
*/

int main() {
	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) return 0;
		printf("%d\n", a + b);
	}
}
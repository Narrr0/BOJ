#include <stdio.h>

/*
�� ���� A�� B�� �Է¹��� ����, A/B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ����� ��°��� ������� �Ǵ� �������� 10-9 �����̸� �����̴�.
*/

int main() {
	int a, b;
	double result;
	scanf("%d %d", &a, &b);
	result = (double)a / b;
	printf("%.10f\n", result);
}
#include <stdio.h>

/*
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 
당신은 그들에게 슬픈 진실을 알려줘야 한다.

첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

각 케이스마다 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력하시오.
*/

int main() {
	int count, student, higher;
	int score[1000];
	float avg, rate;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		int sum = 0;
		higher = 0;
		scanf("%d ", &student);
		for (int j = 0; j < student; j++) {
			scanf("%d ", &score[j]);
			sum += score[j];
		}
		avg = sum / student;
		for (int j = 0; j < student; j++) {
			if (score[j] > avg) higher++;
		}
		rate = (float)higher * 100 / student;
		printf("%.3f%%\n", rate);
	}
}
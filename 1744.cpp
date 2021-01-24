#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*
길이가 N인 수열이 주어졌을 때, 그 수열의 합을 구하려고 한다. 
하지만, 그냥 그 수열의 합을 모두 더해서 구하는 것이 아니라, 
수열의 두 수를 묶으려고 한다. 어떤 수를 묶으려고 할 때, 위치에 상관없이 묶을 수 있다. 
하지만, 같은 위치에 있는 수(자기 자신)를 묶는 것은 불가능하다. 
그리고 어떤 수를 묶게 되면, 수열의 합을 구할 때 묶은 수는 서로 곱한 후에 더한다.

예를 들면, 어떤 수열이 {0, 1, 2, 4, 3, 5}일 때, 그냥 이 수열의 합을 구하면 0+1+2+4+3+5 = 15이다. 하지만, 2와 3을 묶고, 4와 5를 묶게 되면, 0+1+(2*3)+(4*5) = 27이 되어 최대가 된다.
수열의 모든 수는 단 한번만 묶거나, 아니면 묶지 않아야한다.

수열이 주어졌을 때, 수열의 각 수를 적절히 묶었을 때, 
그 합이 최대가 되게 하는 프로그램을 작성하시오.
*/

bool desc(int a, int b) {
	return a > b;
}

int main() {
	int N; cin >> N; // 수열의 크기
	int sum = 0;
	deque<int> pos, neg; // 1 초과, 0 이하

	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		if (tmp < 1)
			neg.push_back(tmp);
		else if (tmp > 1)
			pos.push_back(tmp);
		else
			sum++;
	}
	sort(pos.begin(), pos.end(), desc);
	sort(neg.begin(), neg.end());

	
	for (int i = 0; i < pos.size(); ) {
		if (i + 1 == pos.size()) {
			sum += pos[i];
			break;
		}
		else {
			sum += pos[i] * pos[i + 1];
			i = i + 2;
		}
	}
	for (int i = 0; i < neg.size(); ) {
		if (i + 1 == neg.size()) {
			sum += neg[i];
			break;
		}
		else {
			sum += neg[i] * neg[i + 1];
			i = i + 2;
		}
	}
	cout << sum;
}
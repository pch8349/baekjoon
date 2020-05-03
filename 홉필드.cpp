#include<iostream>
#include<vector>
using namespace std;

#define PATTERN 5 // ㄱ, ㄴ, ㅇ, ㅁ, ㅅ 5가지 이기에 5
#define NEURON 25 // 5*5 크기로 배열이 만들어지므로 1차원 배열 25줄로 표현

vector<vector<int> > p(PATTERN, vector<int>(NEURON));//패턴저장할 배열
vector<vector<int> > w(NEURON, vector<int>(NEURON));//가중치 집합을 저장할 배열 w
vector<int> testcase(NEURON); // 노이즈를 갖고 입력받기 위한 벡터

int main() {
	int sum;
	p[0] = { 1, 1, 1, 1, 1,-1,-1,-1,-1, 1,-1,-1,-1,-1, 1,-1,-1,-1,-1, 1,-1,-1,-1,-1, 1 };//ㄱ
	p[1] = { 1,-1,-1,-1,-1, 1,-1,-1,-1,-1, 1,-1,-1,-1,-1, 1,-1,-1,-1,-1, 1, 1, 1, 1, 1 };//ㄴ
	p[2] = {-1,-1, 1,-1,-1,-1, 1,-1, 1,-1, 1,-1,-1,-1, 1,-1, 1,-1, 1,-1,-1,-1, 1,-1,-1 };//ㅇ
	p[3] = { 1, 1, 1, 1, 1, 1,-1,-1,-1, 1, 1,-1,-1,-1, 1, 1,-1,-1,-1, 1, 1, 1, 1, 1, 1 };//ㅁ
	p[4] = {-1,-1, 1,-1,-1,-1,-1, 1,-1,-1,-1,-1, 1,-1,-1,-1, 1,-1, 1,-1, 1,-1,-1,-1, 1 };//ㅅ
	for (int t = 0; t < PATTERN; t++) {
		for (int i = 0; i < NEURON; i++) {
			for (int j = 0; j < NEURON; j++) {
				w[i][j] += p[t][j] * p[t][i]; // w = y1y1 + y2y2
			}
		}
	}
	for (int i = 0; i < NEURON; i++) {
		w[i][i] -= 2; // w - 2I
		cin >> testcase[i]; // 테스트할 값 입력받기
		if (testcase[i] == 0) testcase[i] = -1; // 입력받을때 -1로 받으면 불편해서 -1은 0으로 받겠습니다.
	}
	for (int i = 0; i < NEURON; i++) {
		sum = 0; // 가중치 계산해서 총 합할 변수 초기화
		for (int j = 0; j < NEURON; j++) sum += w[i][j] * testcase[j]; // 가중치 계산. 단위행렬로 인해 대각선끼리 대칭이므로 행을 기준으로 곱하든, 열을 기준으로 곱하든 상관없다.
		if (sum > 0) testcase[i] = 1; // 0보다 크면 1로 저장
		else if (sum < 0) testcase[i] = -1; // 0보다 작으면 -1로 저장, 0나오면 입력받은값 건들지 않음.
	}
	for (int i = 0; i < NEURON; i++) {
		if (testcase[i] == 1) cout << "■"; // 1이면 하얀네모로
		else cout << "□"; // -1이면 검은네모로 출력
		if (i % 5 == 4) cout << endl; // 모양을 보기 위해 5번째마다 줄띄움
	}
}
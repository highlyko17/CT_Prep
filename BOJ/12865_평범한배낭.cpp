#include <iostream>
using namespace std;

#define MAX 110

int N, K;
int W[MAX];
int V[MAX];
int DP[MAX][100010];  

int main(void) {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= N; i++) {                    
		for (int j = 1; j <= K; j++) {               
			if (j >= W[i]) {                          
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);  //핵심
                //i번째 물건을 넣을 수 있을 때, 이전물건까지 고려한 가치(DP[i-1][j])와 이번 물건을 넣을 때의 가치(DP[i-1][j-W[i]]+V[i]) 중 큰 것 선택 
			}
			else DP[i][j] = DP[i - 1][j];
		}   
	}
	cout << DP[N][K] << endl;
	
	return 0;
}
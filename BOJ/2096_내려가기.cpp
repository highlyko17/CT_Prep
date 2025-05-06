#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a, b, c;
    int maxDp[3], minDp[3], tempMax[3], tempMin[3];

    cin >> a >> b >> c;
    maxDp[0] = minDp[0] = a;
    maxDp[1] = minDp[1] = b;
    maxDp[2] = minDp[2] = c;

    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;

        // 임시 배열에 기존 값을 저장하여 안전한 갱신 수행
        tempMax[0] = a + max(maxDp[0], maxDp[1]);
        tempMax[1] = b + max({maxDp[0], maxDp[1], maxDp[2]});
        tempMax[2] = c + max(maxDp[1], maxDp[2]);

        tempMin[0] = a + min(minDp[0], minDp[1]);
        tempMin[1] = b + min({minDp[0], minDp[1], minDp[2]});
        tempMin[2] = c + min(minDp[1], minDp[2]);

        // 값을 업데이트
        for (int j = 0; j < 3; j++) {
            maxDp[j] = tempMax[j];
            minDp[j] = tempMin[j];
        }
    }

    cout << max({maxDp[0], maxDp[1], maxDp[2]}) << ' ' << min({minDp[0], minDp[1], minDp[2]}) << '\n';

    return 0;
}

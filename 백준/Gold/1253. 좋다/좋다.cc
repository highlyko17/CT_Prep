#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int answer = 0;

    for (int i = 0; i < N; i++) {
        long long target = v[i];
        int left = 0, right = N - 1;

        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }

            long long sum = v[left] + v[right];
            if (sum == target) {
                answer++;
                break;
            }
            if (sum < target) left++;
            else right--;
        }
    }

    cout << answer;
    return 0;
}

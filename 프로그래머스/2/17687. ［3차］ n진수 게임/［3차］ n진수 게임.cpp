
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string convert(int n, int k) {
    string digits = "0123456789ABCDEF";
    string result = "";

    if (n == 0) return "0";

    while (n > 0) {
        result += digits[n % k];
        n /= k;
    }

    reverse(result.begin(), result.end());

    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string example = "";

    int num = 0;

    // 필요한 길이만큼 진법 변환
    while (example.length() < t * m) {
        example += convert(num, n);
        num++;
    }

    int idx = p - 1;

    while (answer.length() < t) {
        answer += example[idx];
        idx += m;
    }

    return answer;
}

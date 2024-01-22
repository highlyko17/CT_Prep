#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool desc(int i, int j){
    return j < i;
}

string solution(string number, int k) {
    string answer = "";
    int length = number.length() - k;
    int startidx = 0;
    
    for(int i = 0; i < length; i++){
        char max = number[startidx];
        int maxidx = startidx;
        for(int j = startidx; j <= i + k; j++){
            if(max < number[j]){
                max = number[j];
                maxidx = j;
            }
        }
        answer += max;
        startidx = maxidx + 1;
    }
    return answer;
}
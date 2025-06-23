#include <iostream>
#include <deque>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    deque<int> belt(2 * N);
    deque<bool> robot(2 * N, false);

    for (int i = 0; i < 2 * N; ++i) {
        cin >> belt[i];
    }

    int step = 0;

    while(1){
        step++;

        belt.push_front(belt.back());
        belt.pop_back();

        robot.push_front(false);
        robot.pop_back();

        if(robot[N - 1]) robot[N - 1] = false;

        for(int i = N - 2; i >= 0; i--){
            if(robot[i] && !robot[i + 1] && belt[i + 1] > 0){
                robot[i] = false;
                robot[i + 1] = true;
                belt[i + 1]--;
            }
        }

        if(robot[N - 1]) robot[N - 1] = false;

        if(belt[0] > 0 && !robot[0]){
            robot[0] = true;
            belt[0]--;
        }

        int zero_cnt = 0;
        for (int i = 0; i < 2 * N; ++i) {
            if (belt[i] == 0) zero_cnt++;
        }

        if (zero_cnt >= K) break;
    }

    cout << step;

    return 0;
}
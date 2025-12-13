#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    bool first = true;
    
    while(1){
        int k;
        cin >> k;

        if(k == 0) break;

        vector<int> nums(k);
        vector<int> temp(k, 1);
        
        for(int i = 0; i < k; i++){
            cin >> nums[i];
        }

        for(int i = 0; i < 6; i++){
            temp[i] = 0;
        }

        if(!first) cout << '\n';
        first = false;

        do{
            for(int i = 0; i < k; i++){
                if(temp[i] == 0) cout << nums[i] << ' ';
            }
            cout << '\n';
        }while(next_permutation(temp.begin(), temp.end()));
    }
    
    return 0;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool used[10001];
int depth = 0;
bool flag = false;
vector<string> answer;

void srch(string curr, vector<vector<string>> tickets){
    if(depth == tickets.size()){
        flag = true;
    }
    
    answer.push_back(curr);
    
    for(int i = 0; i < tickets.size(); i++){
        string from = tickets[i][0];
        string to = tickets[i][1];
        
        if(from == curr && !used[i]){
            used[i] = true;
            depth++;
            srch(to, tickets);
            
            if(!flag){
                used[i] = false;
                answer.pop_back();
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    srch("ICN", tickets);
    
    return answer;
}
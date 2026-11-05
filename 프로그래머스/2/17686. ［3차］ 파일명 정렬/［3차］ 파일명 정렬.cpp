#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    int files_cnt = files.size();
    vector<pair<pair<string, int>, int>> new_files;
    
    for(int i = 0; i < files_cnt; i++){
        string name = files[i];
        
        string head = "";
        string num = "";
        int j = 0;
        
        while(j < name.size() && !isdigit(name[j])) {
            head += tolower(name[j]);
            j++;
        }
        
        while(j < name.size() && isdigit(name[j])){
            num += name[j];
            j++;
        }
         
        new_files.push_back({{head, stoi(num)}, i});
    }
    
    sort(new_files.begin(), new_files.end());
    
    for(int i = 0; i < files_cnt; i++){
        int idx = new_files[i].second;
        answer.push_back(files[idx]);
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0, skill_idx, same;
    
    for(auto skill_tree: skill_trees){
        same = 1;
        skill_idx = 0;
        for(auto each_skill: skill_tree){
            int present = skill.find(each_skill);
            if(present == -1) continue;
            if(skill[skill_idx] == each_skill){
                skill_idx++;
                same = 1;
            }
            else{
                same = 0;
                break;
            }
        }
        if(same == 1){
            answer++;
            //cout << skill_tree;
        }
    }
    return answer;
}
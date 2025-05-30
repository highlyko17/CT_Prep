#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int time_limit = fees[0], default_fee = fees[1], extra_time = fees[2], extra_fee = fees[3];
    
    unordered_map<string, int> in_time;
    unordered_map<string, int> total_time;
    for(int i = 0; i < records.size(); i++){
        string time_str, car_num, in_out;
        stringstream ss(records[i]);
        
        ss >> time_str >> car_num >> in_out;
        
        int hour = stoi(time_str.substr(0, 2));
        int minute = stoi(time_str.substr(3, 2));
        int time_sum = hour * 60 + minute;
        
        if(in_out == "IN"){
            in_time[car_num] = time_sum;
        }
        else if(in_out == "OUT"){
            int duration = time_sum - in_time[car_num];
            total_time[car_num] += duration;
            in_time.erase(car_num);
        }
    }
    
    for(auto& pair : in_time){
        string car_num = pair.first;
        int duration = (23 * 60 + 59) - in_time[car_num];
        total_time[car_num] += duration;
    }
    
    map<string, int> sorted_time(total_time.begin(), total_time.end());
    
    for(auto& pair : sorted_time){
        int total = pair.second;
        
        if(total <= time_limit){
            answer.push_back(default_fee);
        }
        else{
            int extra = ceil((total - time_limit) / (double)extra_time); 
            answer.push_back(extra * extra_fee + default_fee);
        }
    }
    
    return answer;
}
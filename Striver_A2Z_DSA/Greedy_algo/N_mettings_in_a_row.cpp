#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool static customComparator(vector<int> v1, vector<int> v2){
            return v1[1] < v2[1];
        }
        vector<int> maxmeetings(vector<int> s, vector<int> e) {

            // for(int i=0; i<s.size(); i++){
            //     cout << s[i] <<" :" << e[i] <<endl;
            // }

            vector<vector<int>> events;
            int n=s.size();

            for(int i=0; i<n; i++){
                events.push_back(vector<int>{s[i],e[i], i+1});
                // cout << i << ":" << events[i][0] << " : " << events[i][1] << endl;
            }

            sort(events.begin(), events.end(), customComparator);
            
            int curr_end_time = events[0][1], ans=1;
            vector<int> res;
            res.push_back(events[0][2]);
            for(int i=1; i<events.size(); i++){
                if(events[i][0] > curr_end_time){
                    ans++;
                    // cout << events[i][0] << " : " << events[i][1] << endl;
                    res.push_back(events[i][2]);
                    curr_end_time = events[i][1];
                }
            }
            return res;
        }
    };

int main(){

    Solution sol;

    vector<int> s{1,3,0,5,8,5}, e{2,4,5,7,9,9};

    vector<int> res = sol.maxmeetings(s, e);
    for(auto i : res){
        cout << i << endl;
    }
}
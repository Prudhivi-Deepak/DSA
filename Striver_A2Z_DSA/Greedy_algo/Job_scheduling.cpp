#include <bits/stdc++.h>
using namespace std;

class Solution{  
    public:  
      bool static customComparator(vector<int> v1, vector<int> v2 ){
        return v1[2] > v2[2];
      }
      vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
          //your code goes here
        int n = Jobs.size();
        vector<int> timeline(n, -1);
        sort(Jobs.begin(), Jobs.end(), customComparator);
        int cnt_jobs = 0, profit = 0;

        for(int i=0; i<n; i++){
            // for each job id check if its time is free or not if not check for past time.
            int job_time = Jobs[i][1]-1;
            while(timeline[job_time]!=-1 && job_time>-1){
                job_time--;
            }
            if(job_time >=0){
                timeline[job_time] = Jobs[i][0];
                cnt_jobs +=1;
                profit += Jobs[i][2];
            }
        }

        // for(int i=1; i<Jobs.size(); i++){
        //     cout << i << ": " << Jobs[i][0] << " : " << Jobs[i][1] << " : "<< Jobs[i][2] << endl;
        //     if(Jobs[i][1] >= i){
        //         cout << i << ": " << Jobs[i][0] << " : " << Jobs[i][1] << " : "<< Jobs[i][2] << endl;
        //         cnt_jobs++;
        //         profit+=Jobs[i][2];
        //     }
        // }
        return vector<int>{cnt_jobs, profit};
      } 
  };

int main(){
    vector<vector<int>> Jobs  = {vector<int>{1, 4, 20} , vector<int>{2, 1, 10} , vector<int>{3, 1, 40} , vector<int>{4, 1, 30}};
    // vector<vector<int>> Jobs = {{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,1,15}};
    Solution sol;
    vector<int> ans = sol.JobScheduling(Jobs);
    cout << ans[0] << " : " << ans[1] << endl;
}
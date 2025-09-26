#include<bits/stdc++.h>
using namespace std;

class Solution{  
  public:  
  bool static customComparator(vector<int> v1, vector<int> v2 ){
        return v1[2] > v2[2];
      }
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        //your code goes here
        sort(Jobs.begin(), Jobs.end(), customComparator);
        int profit = 0, cnt_jobs = 0;
        vector<int> time_slots(Jobs.size()+1, -1);
        for(int i=0; i<Jobs.size(); i++){
            int job_deadline = Jobs[i][1];
            while(time_slots[job_deadline]!=-1){job_deadline--;}
            if(job_deadline!=0){
                time_slots[job_deadline] = Jobs[i][0];
                profit += Jobs[i][2];
                cnt_jobs += 1;
            }
        }
        return vector<int>{cnt_jobs, profit};
    } 
};
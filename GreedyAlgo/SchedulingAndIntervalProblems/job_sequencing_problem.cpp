class Solution{  
  public:
    bool static comparator(vector<int> &v1, vector<int> &v2){
        // < should be used for ascending order
        // > should be used for descending order
        return v1[2] > v2[2];
    }

    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        //your code goes here
        sort(Jobs.begin(), Jobs.end(), comparator);
        int n = Jobs.size();
        vector<int> time(n+1, -1);
        int total_profit = 0, jobs_cnt = 0;
        for(int i=0; i<n; i++){
            // fill time array from last possible index, take care if deadline is not met
            int jobid = Jobs[i][0], deadline = Jobs[i][1], profit = Jobs[i][2];
            while(deadline>=0 && time[deadline]!=-1){
                deadline--;
            }
            if(deadline>0 && time[deadline]==-1) {
                time[deadline] = jobid;
                total_profit += profit;
                jobs_cnt++;
                // cout << profit << endl;
            }
        }
        return {jobs_cnt, total_profit};
    } 
};
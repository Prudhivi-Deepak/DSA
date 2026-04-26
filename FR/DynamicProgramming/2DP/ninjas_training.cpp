class Solution {
public:

    // consoder we are going from day n-1 to day 0
    // and consider lastT is curr day-1 task taken
    // each task has 3 activities
    int f(int day, int lastT, vector<vector<int>>& matrix, vector<vector<int>> dp){

        if(day<0) return 0;

        if(lastT!=-1 && dp[day][lastT]!=-1) return dp[day][lastT];

        int meritPoints = -1e9;
        for(int task=0; task<3; task++){
            if(task!=lastT){
                meritPoints = max(meritPoints, f(day-1, task, matrix, dp)+matrix[day][task]);
            }
        }

        if(lastT==-1) return meritPoints;

        return dp[day][lastT] = meritPoints;

    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vector<vector<int>> dp(n+1, vector<int>(3, 0));

        vector<int> prev(3, 0), curr(3, 0);

        // consoder we are going from day n-1 to day 0
        // and consider lastT is curr day-1 task taken
        // each task has 3 activities

        // Now for iteration approach
        // consider day from -1 to n-1
        // task from -1 to 0 1 2
        // base case is consider first day -1 is 0

        // for(int task=0; task<3; task++){
        //     dp[0][task] = dp[0][task]+matrix[0][task];
        // }

        // dp[0][0] = meritPoints;

        for(int day=0; day<n; day++){
            for(int lastT=0; lastT<3; lastT++){
                
                int meritPoints = -1e9;
                for(int task=0; task<3; task++){
                    if(task!=lastT){
                        // meritPoints = max(meritPoints, (day-1<0 ? 0 : dp[day-1][task] )+matrix[day][task]);
                        meritPoints = max(meritPoints, (day-1<0 ? 0 : prev[task] )+matrix[day][task]);
                    }
                }

                curr[lastT] = meritPoints;
            }
            prev = curr;
        }

        // return max({dp[n-1][0] , dp[n-1][1] , dp[n-1][2]});
        return max({prev[0] , prev[1] , prev[2]});


        // return f(n-1, -1, matrix, dp);
    }
};
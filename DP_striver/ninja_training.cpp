
#include <bits/stdc++.h>
using namespace std;
// https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=SUBMISSION

int f(int day, int ldt, int n, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day == n-1) return points[day][ldt];
    if(dp[day][ldt]!=-1) return dp[day][ldt];
    else{
        int max_point_task = -1;
        for(int task=0; task<3; task++){
            if(task != ldt){
                max_point_task = max(max_point_task, f(day+1, task, n, points, dp));
            }
        }
        return dp[day][ldt] = max_point_task + points[day][ldt];
    }
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int max_points = -1;
    vector<vector<int>> dp(n, vector<int>(3, -1));

    vector<int> prev_day(3,-1);
    vector<int> curr_day(3,-1);

    for(int day=n-1; day>=0; day--){
        for(int ldt = 0; ldt<3; ldt++){
            if(day == n-1){
                // dp[day][ldt] 
                curr_day[ldt] = points[day][ldt];
            }
            else{
                int max_point_task = -1;
                for(int task=0; task<3; task++){
                    if(task != ldt){
                        max_point_task = max(max_point_task, prev_day[task]);
                        // dp[day+1][task]);
                        // f(day+1, task, n, points, dp));
                    }
                }
                curr_day[ldt] = max_point_task + points[day][ldt];
            }
        }
        prev_day = curr_day;
    }

    


    for(int first_task = 0; first_task <3; first_task++){
        max_points = max(max_points, prev_day[first_task]);
        // (0, first_task, n, points, dp));
    }
    return max_points;
}
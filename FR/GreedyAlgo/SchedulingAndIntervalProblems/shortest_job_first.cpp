class Solution {
  public:
    long long solve(vector<int>& bt) {
        //your code goes here
        // 0 1 2 3 4
        // 4 1 3 7 2

        // 1 (1)--> wt = 0
        // 2 (4)--> wt = 1
        // 3 (2)--> wt = 1+2 = 3
        // 4 (0)--> wt = 1+2+3 = 6
        // 7 (3)--> wt = 1+2+3+4 = 10
        // total wt = 20/5 = 4

        sort(bt.begin(), bt.end());
        long long total_wt = 0, current_wt = 0, n = bt.size();
        for(int i=0; i<n; i++){
            total_wt += current_wt;
            current_wt += bt[i];
        }
        return floor(total_wt/n);
    }
};
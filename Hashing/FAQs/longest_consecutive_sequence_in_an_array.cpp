class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;

        for(int n: nums){
            uset.insert(n);
        }

        int maxLen = 1;
        for(int n: nums){
            int currLen = 0;
            if(uset.find(n+1)==uset.end()){
                int x = n;

                while(uset.count(x)){
                    uset.erase(x);
                    x--;
                    currLen++;
                }
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};
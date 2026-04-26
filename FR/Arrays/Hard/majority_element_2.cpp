class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {

        // sort --> n log n --> easily find the elements
        // no extra space

        // O(n) space --> maintain freq
        // O(n) complexity

        // what we need O(n) TC and O(1) SC 

        // i know one thing if nums size is 20
        // 20/3 = 6 < 7
        // 7x2 = 14
        // 7x3 = 21 ( not possible)

        // 21/3 = 7 < 8
        // 8x2 = 16
        // 8x3 = 24 (not possible)
        // maximum 2 possible elements only >n/3 times repeated

        // 1 2 1 1 3 2
        //           i

        // cnt1 = 2, ele1 = 1
        // cnt2 = 1, ele2 = 
        
        int cnt1 = 0, cnt2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;

        for(int i : nums){
            if(ele1 == i){
                cnt1++;
            }
            else if(ele2 == i){
                cnt2++;
            }
            else if(cnt1 == 0){
                ele1 = i;
                cnt1++;
            }
            else if(cnt2 == 0){
                ele2 = i;
                cnt2++;
            }
            else{
                cnt1--;cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;

        for(int i : nums){
            if(ele1 == i) cnt1++;
            if(ele2 == i) cnt2++;

            if(cnt1>nums.size()/3 && cnt2>nums.size()/3) break;
        }
        
        
        vector<int> ans;

        if(cnt1 > nums.size()/3) ans.push_back(ele1);
        if(cnt2 > nums.size()/3) ans.push_back(ele2);

        return ans;
    }
};
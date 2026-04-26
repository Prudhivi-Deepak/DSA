class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // majority voting algorithm should work 
        // maintain element and cnt
        // if curr value is equal to element cnt++ else cnt--
        // if cnt is 0 then change element
        // at last verify the element is majority or not

        int cnt = 1, ele = nums[0];

        for(int i=1; i<nums.size(); i++){

            if(ele == nums[i]){
                cnt++;
            }
            else cnt--;

            if(cnt==0){
                ele = nums[i];
                cnt= 1;
            }
        }

        cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==ele) cnt++;
        }

        // cout << ele << " : " << cnt << endl;

        if(cnt > nums.size()/2) return ele;

        return -1;        
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> nums_index;
        for(int i=0; i<nums.size(); i++){
            nums_index.push_back(pair<int,int>(nums[i], i));
        }

        sort(nums_index.begin(), nums_index.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        });

        int left = 0, right=nums_index.size()-1;
        while(left<right){
            int value = nums_index[left].first+nums_index[right].first;
            if(value  == target){
                return vector<int>{nums_index[left].second, nums_index[right].second};
            }
            else if(value < target){
                left++;
            }
            else{
                right--;
            }
        }

        return vector<int>{-1,-1};

        // unordered_map<int, int> umap;
        // for(int i=0; i<nums.size(); i++){
        //     if(umap.find(target-nums[i])!=umap.end()) return vector<int>{umap[target-nums[i]], i};
        //     umap[nums[i]] = i;
        // }
    }
};
#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> d;
        for (int i = 0;i<nums.size(); ++i) {
            int x = nums[i];
            int y = target   - x;
            if (d.find(y) != d.end()) {
                return {d[y], i};
            }
            d[x] = i;
        }
    }
};

int main(){
    
    Solution twosum = Solution();
    vector<int> arr = {12,2,4,1,8,3,7,10};
    arr = twosum.twoSum(arr, 11);

    for(int a: arr){
        cout << a << " " << endl;
    }

    return 0;
}

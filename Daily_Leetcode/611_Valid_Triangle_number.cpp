#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 4 2 3 4
    // 2 3 4 4
    // 0 1 2 3

    // 2 (0)i
    // 3 (1)j
    // 2+3 = 5
    // find a value index (p) from j+1 to n-1 whihc is less than 5 and count p - j
    //  here it is p(3) count = 3-1 = 2

    // 2 (0)
    // 4 (2)
    // 2+4 = 6
    // indx 3 to 4 less value than 6 is index 4 (p) count = 4-2 = 1

    // 2(0)
    // 4 (3) j+1=4 out of bound

    // i++
    // 3 (1)
    // 4 (2)
    // 3+4 = 7
    // index 3 to 3 value 4 p = 3 count = 3-2 = 1

    // use binary search to find the greater less value for sum

    // lower bound for 5 from j+1 to n 
    // lower bound means find value greater than or equal to ele
    // upper bound means find value greater than ele


    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = nums[i]+nums[j];

                int l = j+1, r = n-1;
                while(l<=r){
                    int mid = r-(r-l)/2;
                    if(nums[mid]<sum)
                        l = mid+1;
                    else
                        r = mid-1;
                }
                count += (l-1-j);
            }
        }
        return count;
    }






    int IsPossibleTraiangle(int a, int b, int c){
        // cout << a << " " << b << " " << c << endl;
        if(a+b > c && b+c > a && c+a > b) return 1;
        return 0;
    }

    int validTriangle(vector<int>& nums, int i, vector<int> &sides){

        if(sides.size() == 3) return IsPossibleTraiangle(sides[0], sides[1], sides[2]);
        if(i >= nums.size()) return 0;

        int notTake = validTriangle(nums, i+1, sides);
        sides.push_back(nums[i]);
        int Take = validTriangle(nums, i+1, sides);
        sides.pop_back();

        return notTake+Take;
    }

    int triangleNumber1(vector<int>& nums) {
        vector<int> sides;
        // 
        return validTriangle(nums, 0, sides);
    }
};
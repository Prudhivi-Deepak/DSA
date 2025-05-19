#include <bits/stdc++.h>
using namespace std;
//resource allocation, ship carry weight
class Solution {
    public:
        int IsPossibleTolimitPagesToX(vector<int> &nums, int m, int xPages){
            int students = 0;
            int current_pages =0;
            for(int i=0; i<nums.size(); i++){
                current_pages += nums[i];
                // cout << "current_pages : " << current_pages << " XPages : " << xPages << " students : " << students << endl;
    
                if(current_pages > xPages){
                    students++;
                    current_pages = nums[i];
                }
            }
    
            if(current_pages!=0 && current_pages <= xPages) students++;
    
            // return student<=m;
            // cout << students << endl;
            if(students == m) return 0;
            else if(students < m) return -1;
    
            return 1;
        }
    
        int splitArray(vector<int>& nums, int m) {
            int min_ele = nums[0], sum = nums[0], mid, AllocateX = INT_MAX;
    
            if(m > nums.size()) return -1;
    
            for(int i=1; i<nums.size(); i++){
                min_ele = max(min_ele, nums[i]);
                sum += nums[i];
            }
    
            while(min_ele <= sum){
                mid = min_ele + (sum-min_ele)/2;
                // cout << mid << endl;
                // student == m possible --> go to left part and wait for next min value 0
                // student < m means less students are given to more pages decrease pages go left -1
    
                // student > m means more students are given to less pages increase pages go right 1
                int flag = IsPossibleTolimitPagesToX(nums, m, mid);
                // cout << flag << endl;
                if(flag == 0 || flag == -1) {
                    // cout << " possible" << endl;
                    AllocateX = min(mid, AllocateX); sum = mid-1;
                }
                // else if(flag == -1){
                //      sum = mid-1; 
                // }
                else min_ele = mid+1;
            }
    
            if(AllocateX == INT_MAX) return -1;
    
            return AllocateX;
        }
    };
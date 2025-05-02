#include<bits/stdc++.h>

using namespace std;
// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/?envType=daily-question&envId=2024-12-22
class Solution {

private:
    int SearchIndex(vector<int>& heights, int search_i, int max_height_index, int equalto, int n){
        while(search_i < n){
            if((true && heights[search_i] >= heights[max_height_index]) ||
                (false && heights[search_i] > heights[max_height_index])  ){
                return search_i;
            }
            search_i++;
        }
        return -1;
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // 6 4 8 5 2 7
        vector<int> ans;
        int max_height_index, search_i, n=heights.size(), j, equalto = 1;
        for(auto q: queries){
            equalto = 1;
            cout << "==================" << endl;
            cout << q[0] << q[1] << endl;

            if(q[0] > q[1]){
                // search_i = q[0];
                swap(q[0], q[1]);
            }
            // else{
                // search_i = q[1];
            // }

            search_i = q[0];

            
            if(heights[q[0]] == heights[q[1]]){
                max_height_index = q[0];
                search_i++;
            }
            else if(heights[q[0]] > heights[q[1]]){
                max_height_index = q[0];
                equalto = 0;
            }
            else{
                max_height_index = q[1];
            }
            cout << "search_i : " << search_i << endl;
            cout << "max_height_index: " << max_height_index << endl;
            cout << "equalto : " << equalto << endl;

            if(q[0] == q[1]){
                ans.push_back(q[0]);
            }
            else{
                ans.push_back(SearchIndex(heights, search_i, max_height_index, equalto, n));
            }
        }
        return ans;
    }
};
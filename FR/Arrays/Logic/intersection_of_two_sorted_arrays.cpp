class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        int i1 = 0, i2 = 0, n1 = nums1.size(), n2 = nums2.size();

        while(i1<n1 || i2<n2){

            int v1 = (i1<n1) ? nums1[i1] : INT_MAX;
            int v2 = (i2<n2) ? nums2[i2] : INT_MAX;

            if(v1==INT_MAX && v2==INT_MAX) break;

            if(v1==v2 && v1!=INT_MAX) { 
                // if(ans.empty() || v1!=ans.back()) 
                ans.push_back(v1); 
                i1++; i2++;
            }
            else if(v1 < v2) { 
                // if(ans.empty() || v1!=ans.back()) ans.push_back(v1); 
                i1++;
            }
            else{
                // if(ans.empty() || v2!=ans.back()) ans.push_back(v2); 
                i2++;
            }
        }

        return ans;   
    }
};
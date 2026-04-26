class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (m+n)/2 + (m+n)%2, ind1, ind2, i, j;

        while(gap>0){
            // cout << gap << endl;
            int i=0, j = gap+i;
            while(j<m+n){
                if(i>=m){
                    ind1 = i-m;
                    ind2 = j-m;
                    if(nums2[ind1]>nums2[ind2]){
                        swap(nums2[ind1], nums2[ind2]);
                    }
                }
                else if(j>=m){
                    ind2 = j-m;
                    if(nums1[i]>nums2[ind2]){
                        swap(nums1[i], nums2[ind2]);
                    }
                }
                else{
                    if(nums1[i]>nums1[j]){
                        swap(nums1[i], nums1[j]);
                    }
                }
                i++; j++;
            }
            if(gap==1) break;
            gap = (gap)/2 + (gap)%2;
        }

        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
        }
    }
};
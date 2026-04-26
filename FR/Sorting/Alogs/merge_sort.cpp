class Solution {
public:
    void mergeArray(vector<int> &arr, int left, int mid, int right){
        int l1 = left, r1 = mid, l2 = mid+1, r2 = right, i1=l1, i2=l2;

        vector<int> ans;

        while(i1<=r1 && i2<=r2){
            if(arr[i1] <= arr[i2]){
                ans.push_back(arr[i1]); i1++;
            }
            else{
                ans.push_back(arr[i2]); i2++;
            }
        }

        while(i1<=r1){
            ans.push_back(arr[i1]); i1++;
        }

        while(i2<=r2){
            ans.push_back(arr[i2]); i2++;
        }

        int index = 0;

        for(int i3=left; i3<=r2; i3++){
            arr[i3] = ans[index++];
        }

    }

    void divideArray(vector<int> &arr, int left, int right){
        // int left = 0, right = nums.size();
        if(left >= right) return;

        // int mid = right - (right - left)/2;
        int mid = (right + left)/2;
        // cout << left << " : " << right << endl;
        divideArray(arr, left, mid);
        divideArray(arr, mid+1, right);
        mergeArray(arr, left, mid, right);
    }

    vector<int> mergeSort(vector<int>& nums) {
        divideArray(nums, 0, nums.size()-1);
        return nums;
    }
};

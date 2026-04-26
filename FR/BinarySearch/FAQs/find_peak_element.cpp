class Solution {
public:
    int findPeakElement(vector<int> &arr) {

        // so the idea is to do BS --> t find peak element 
        // if an element is not peak element then going towards it's greatest neg may lead to the peak element
        // because question says array has atleast one peak element

        if(arr.size()==1) return 0;

        int l = 1, r = arr.size()-2, mid;

        if(arr[l-1] > arr[l]) return 0;
        if(arr[r] < arr[r+1]) return r+1;

        while(l<=r){
            mid = l+(r-l)/2;

            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid;
            else if(arr[mid-1] > arr[mid]) r = mid-1;
            else l = mid+1;
        }
        return mid;
    }
};
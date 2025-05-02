//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {

        // cout << "=============================" << endl;
        // code here

        sort(arr.begin(), arr.end());
        int ans = arr[arr.size()-1] - arr[0];
        int maxv, minv;

        for(int i=1; i<arr.size(); i++){
            if(arr[i]-k <0){
                continue;
            }

            minv = min(arr[0]+k, arr[i]-k);
            maxv = max(arr[arr.size()-1]-k, arr[i-1]+k);

            ans = min(ans, maxv-minv);

        }

        return ans;



        // int min = 0;
        // int max = 0;
        // for(int i =0 ; i<arr.size();i++){
        //     if(arr[i] < arr[min] ){
        //         min = i;
        //     }
        //     if(arr[i] > arr[max]){
        //         max = i;
        //     }
        // }

        // int minv;
        // int maxv;


        // arr[min] = arr[min] + k;
        // if((arr[max] - k) >= 0){
        //     arr[max] = arr[max] - k;
        // }
        // else{
        //     arr[max] = arr[max] + k;
        // }

        // if(arr[min] < arr[max]){
        //     minv = arr[min];
        //     maxv = arr[max];
        // }
        // else{
        //     minv = arr[max];
        //     maxv = arr[min];
        // }
                
        // int calculatedMin;
        // int calculatedMax;

        // for(int i=0; i<arr.size(); i++){
        //     if(i == min || i == max){
        //         continue;
        //     }            

        //     if((arr[i] - k) <0){                
        //         calculatedMax = abs(minv - (arr[i]+k));
        //         arr[i] = arr[i]+k;
        //         if(arr[i] > maxv){
        //             maxv = arr[i];
        //         }
        //     }
        //     else{
        //         calculatedMin = abs(arr[i]-k - maxv);
        //         calculatedMax = abs(minv - (arr[i]+k));        

        //         if( calculatedMin <= calculatedMax){
        //             arr[i] = arr[i]-k;
        //             if(arr[i] < minv){
        //                 minv = arr[i];
        //             }
        //         }
        //         else{
        //             arr[i] = arr[i]+k;
        //             if(arr[i] > maxv){
        //                 maxv = arr[i];
        //             }
        //         }
        //     }
        // }
        // return abs(maxv-minv);

                    // cout << "--------------" << endl;
            // cout << "maxv : " << maxv << endl;
            // cout << "minv : " << minv << endl;

            // cout << "arr[i]-k : " << arr[i]-k << endl;
            // cout << "arr[i]+k : " << arr[i]+k << endl;

            // cout << "arr[i]-k m: " << arr[i]-k - maxv << endl;
            // cout << "arr[i]+k m: " << minv - (arr[i]+k) << endl;
            // cout << "calculated min : " << calculatedMin << endl;
            // cout << "calculated max : " << calculatedMax << endl;    

            // for(int j: arr){
            //     cout << j << " ";
            // }
            // cout << endl;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012_temp(vector<int>& arr) {
        // code here
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;

        for(int i:arr){
            if(i==0){
                count_0++;
            }
            if(i == 1){
                count_1++;
            }
            if(i == 2){
                count_2++;
            }
        }

        int index = 0;
        while(count_0>0 || count_1 >0 || count_2>0){
            if(count_0 >0){
                arr[index] = 0;
                index++;
                count_0--;
            }
            else if(count_1 >0){
                arr[index] = 1;
                index++;
                count_1--;
            }
            else if(count_2 >0){
                arr[index] = 2;
                index++;
                count_2--;
            }
        }
    }

    void sort012(vector<int>& arr) {
        // code here
        int p_0 = 0;
        int p_2 = arr.size()-1;
        int p_1 = 0;

        while(p_1 <= p_2){
            if(arr[p_1] == 1){
                p_1++;
            }
            else if(arr[p_1] == 0){
                swap(arr[p_1++], arr[p_0++]);
            }
            else if(arr[p_1] == 2){
                swap(arr[p_1],arr[p_2--]);
            }
        }

    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
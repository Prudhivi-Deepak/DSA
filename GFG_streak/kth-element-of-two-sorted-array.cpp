//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        //  2 3 6 7 9
        //  i
        //  1 4 8 10
        //  j j
        //  k = 5
         
        //  2 > 1
         
         
         
         
        //  i > j
        //     kth = i
        // else
        //     kth = j
        // count++
        
        // if(count == k){
        //     return kth_ele;
        // }
        
        int i=0, j=0, a_size = a.size(), b_size = b.size(), kth_ele, count = 0;
        while(i<a_size || j<b_size){
            if(i<a_size && j<b_size){
                if(a[i] >= b[j]){
                    kth_ele = b[j++];
                }
                else{
                    kth_ele = a[i++];
                }
                count++;
                if(count == k){
                    return kth_ele;
                }
            }
            else if(i<a_size){
                kth_ele = a[i++];
                count++;
                if(count==k){
                    return kth_ele;
                }
            }
            else if(j<b_size){
                kth_ele = b[j++];
                count++;
                if(count==k){
                    return kth_ele;
                }
            }
        }
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends
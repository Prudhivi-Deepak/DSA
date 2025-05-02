//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        string firstNum = "";
        string secondNum = "";        
        sort(arr.begin(),arr.end());

        for(int i=0; i<arr.size();i+=2){            
            firstNum += to_string(arr[i]);
            if(i+1 < arr.size()){
                secondNum += to_string(arr[i+1]);
            }
        }

        // cout << firstNum << endl;
        // cout << secondNum << endl;

        int cs = 0;

        int i = firstNum.size()-1;
        int j = secondNum.size()-1;

        if(i<j){
            string tempNum = firstNum;
            firstNum = secondNum;
            secondNum = tempNum;
        }

        i = firstNum.size()-1;
        j = secondNum.size()-1;

        while(j>=0){            
            cs = firstNum[i]-'0' + secondNum[j]-'0' + cs;
            firstNum[i] = cs%10 + '0';
            cs = cs/10;            
            i--;
            j--;
        }

        // cout << " cs : " << cs << endl;

        if(cs!='0'){
            if(i<0){
                firstNum = to_string(cs) + firstNum;
            }
            else{
                firstNum[i] = firstNum[i]-'0' +cs  + '0';
            }
            
        }
        
        i = 0;
        j = 1;
        while(firstNum[i] =='0' && firstNum[j] =='0'){
            firstNum[i] = '-';
            i = j;
            j = j+1;
        }

        if(firstNum[i]=='0'){
            firstNum[i] = '-';
        }
        // cout << firstNum << endl;
        firstNum.erase(remove(firstNum.begin(), firstNum.end(), '-'),firstNum.end());

        if(firstNum==""){
            return "0";
        }

        // cout << firstNum << endl;

        return firstNum;

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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
class Solution {
public:
    int MOD = 1e9+7;
    void findNSE(vector<int> &NSE, vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        for(int i=n-1; i>=0; i--){

            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void findPSE(vector<int> &PSE,  vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        for(int i=0; i<n; i++){
            // while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            // here it consider even == as smaller element (not expand range)
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            PSE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> NSE(n, n), PSE(n, -1);
        findPSE(PSE, arr);
        findNSE(NSE, arr);
        int sum = 0;
        for(int i=0; i<n; i++){
            int freq = ((i-PSE[i]) * (NSE[i]-i) * 1LL * arr[i]) % MOD ;
            sum = (sum + freq) % MOD;
        }
        return sum;
    }
    int sumSubarrayMins1(vector<int> &arr) {
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            // stack<int> st;
            // cout << i << endl;
            int mini = 1e9;
            for(int j=i; j<n; j++){
                // cout << arr[j] << " ";
                if(arr[j] < mini) mini = arr[j];
                sum+=mini;
                // cout << mini << endl;
            }
            // cout << endl;
        }
        return sum;
    }
};

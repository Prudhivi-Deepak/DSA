class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> st;

        for(char c : nums){
            while(!st.empty() && st.top()-'0' > (c-'0') && k>0) {
                st.pop(); k--;
            }
            st.push(c);
        }

        while(k>0){
            st.pop();k--;
        }

        string ans;
        while(!st.empty()){
            ans += st.top(); st.pop();
        }

        while(ans.back()=='0') ans.pop_back();

        reverse(ans.begin(), ans.end());

        // int i=0;
        // while(i<ans.size() && ans[i]=='0') i++;

        // ans.erase(ans.begin(), ans.begin()+i);

        if(ans.size()==0) return "0";

        return ans;
    }
};
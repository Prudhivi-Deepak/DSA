class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }

    void f(int i, string s, vector<string> onePartition, vector<vector<string>> &allPartitions){

        if(i>=s.size()){
            allPartitions.push_back(onePartition); return;
        }

        for(int j=i; j<s.size(); j++){
            if(isPalindrome(s, i, j)){
                onePartition.push_back(s.substr(i, j-i+1));
                f(j+1, s, onePartition, allPartitions);
                onePartition.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        //your code goes here
        vector<string> onePartition;
        vector<vector<string>> allPartitions;
        f(0, s, onePartition, allPartitions);
        return allPartitions;
    }
};
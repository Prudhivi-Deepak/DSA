class Solution {
public:

    void f(int i, string digits, string substring, vector<string> &ans, vector<string> &keypad){

        if(i==digits.size()){
            // cout << substring << endl;
            ans.push_back(substring); return;
        }

        if(i>digits.size()) return;

        for(char c : keypad[digits[i]-'0']){
            // not take --> no we have to take any one of them consider it because that button is pressed
            // take
            f(i+1, digits, substring+c, ans, keypad);
        }

    }

    vector<string> letterCombinations(string digits) {
        //your code goes here
        vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string substring;
        f(0, digits, substring, ans, keypad);
        return ans;
    }
};
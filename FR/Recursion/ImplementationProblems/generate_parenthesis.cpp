class Solution {
public:

    void f(int n, string str, vector<string> &ans, int open, int close){

        if(str.size()>2*n) return;

        if(str.size()== 2*n){
            ans.push_back(str);
            return;
        }

        if(open > close){
            // take open if < n
            if(open < n) f(n, str+'(', ans, open+1, close);
            // take close as well
            f(n, str+')', ans, open, close+1);
        }
        else if(open == close){
            // take open
            if(open < n) f(n, str+'(', ans, open+1, close);
        }

    }

    vector<string> generateParenthesis(int n) {
        //your code goes here
        vector<string> ans;
        f(n, "", ans, 0, 0);
        return ans;
        // use a function to recursively build the string
        // take ( or ) based on open and close values then call function
        // if string length is 2*n push it to the vector

        // example
        // open = 0, close = 0 string = ""

        // string = "(" open = 1 close = 0
        
        // string="((" open = 2 close = 0
        //     string="(((" open = 3 close = 0
        //         string="((()" open = 3 close = 1
        //     string="(()" open = 2 close = 1
        // string="()" open = 1 close = 1
        //     string="()(" open = 2 close = 1


        // if(open > close){
        //     take close
        //     if(open < n) take open
        // }
        // else{
        //     take open
        // }


    }
};
class Solution {  
public:
    bool isValid(string s) {
        //your code goes here

        // (*))
        // range(INT_MAX, INT_MIN)
        // range(1, 1) --> -1 0 1
        // range(0, 2)
        // range(-1, 1)
        // range(-2, 0)

        int mini = 0, maxi = 0;
        for(char c : s){
            if(c == '('){
                maxi++; mini++;
            }
            else if(c == ')'){
                maxi--; mini--;
            }
            else{
                mini--;
                maxi++;
            }
            if(maxi<0) return false;
            if(mini<0) mini = 0;
        }
        // cout << mini << " : "<< maxi << endl;
        return mini == 0;
    }
};
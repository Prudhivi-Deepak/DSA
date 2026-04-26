class Solution {
public:
    int countRev (string s) {
        int open = 0, close = 0;
        for(char c : s){
            if(c=='(') open++;
            else {
                if(open>0) open--;
                else close++;
            }
        }
        if((open+close)%2) return -1;
        return open%2 + close%2 + open/2 + close/2;
    }
};

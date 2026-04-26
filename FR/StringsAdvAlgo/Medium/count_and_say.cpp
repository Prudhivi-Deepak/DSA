class Solution {
  public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string one = "1";
        for(int i=0; i<n-1; i++){
            string temp;
            int j = 0, cnt = 0;
            char curr;
            while(j<one.size()){
                curr = one[j];
                while(j<one.size() && curr==one[j]) { j++; cnt++;}
                temp += (cnt+'0');
                temp += curr;
                cnt=0;
            }
            one = temp;
        }
        return one;
    }   
};
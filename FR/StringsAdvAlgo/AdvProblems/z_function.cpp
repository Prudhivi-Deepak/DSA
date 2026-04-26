class Solution {
   public:
    void computeZ(string str, vector<int> &z){

        int l = 0, r = 0, n = str.size();

        for(int i=0; i<n; i++){

            // if i out of window compute bruteforce
            if(i > r){

                // use a while loop to calculate z[i] in ith position
                // initial z[i] is 0
                while( i+z[i] < n && str[i+z[i]] == str[z[i]] ) {
                    z[i]++;
                }
            }
            else{
                // now i is inside the window
                // inside window and let's copy th evalid values okay
                // copy from which value (front value)
                // i-l is the distance from 0 to that position = z[i-l]
                if(i+z[i-l] <= r) { z[i] = z[i-l];}
                // but now we see it's inside window but not in valid window size 
                // assign curr valid value and check for the values beyond the window size
                else{
                    z[i] = r-i+1;
                    while(i+z[i] < n && str[i+z[i]] == str[z[i]]){
                        z[i]++;
                    }
                }
            }
            l = i;
            r = i+z[i]-1;
            // cout << z[i] << " ";
        }
        // cout << endl;
    }

    vector<int> search(string text, string pattern) {
        string str = pattern + "$" + text;
        int n = str.size(), m = pattern.size();
        vector<int> z(n, 0);
        computeZ(str, z);
        vector<int> ans;
        // Now i have the z array
        // if z[i] value is m then it's matched the patterne
        // iterate from m+1 to n
        for(int i=m+1; i<n; i++){
            if(z[i]==m){
                // now we have z[i] value m, but what is the index ?
                // index is currIndex i-(m+1) is the actual txt index
                ans.push_back(i-(m+1));
            }
        }
        return ans;
    }
};

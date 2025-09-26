#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        //your code goes here

        // abcba

        // find minimum length substring containing all 3 characters and 
        // obviously when we add any characters to that substring it becomes or gives us a set count of substrings

        // ....a(2)...b(7).. => 2+1 substrings after adding new chars in front along with existing one

        int cnt[3] = {-1, -1, -1}, r = 0, n = s.size(), cnt_substr = 0;

        while(r < n){
            cnt[s[r]-'a'] = r;

            if(cnt[0]!=-1 && cnt[1]!=-1 && cnt[2]!=-1){
                int min_index = min({cnt[0], cnt[1], cnt[2]});
                cnt_substr += (min_index+1);
            }
            r++;
        }
        return cnt_substr;
    }
};
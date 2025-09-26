#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string& s){
        //your code goes here
        int alp[256], l=0, r=0, n = s.size(), max_len = 1;

        if(n<2) return n;

        for(int i=0; i<256; i++) alp[i] = -1;

        while(r<n){
            if(alp[s[r]]!=-1) l = max(alp[s[r]]+1, l);
            max_len = max(max_len, r-l+1);
            alp[s[r]] = r;r++;
        }
        return max_len;
    }
    int lengthOfLongestSubstringSecondTry(string s) {
        // unordered_map<int,int> umap;
        // abcddabac

        // { a :1, b:1, c:1, d:1,
        // { a :1, b:1, c:1, d:2,
        // { d:1,
        // { d:1, a:2, b:1
        // { a:1
        // { a:1, c:1

        // aaabbbccc
        // {a:1
        // {a:2 => a:1
        // {a:2
        // {a:2 => a:1
        // {a:1, b:2
        // {a:1, b:1
        // {a:1, b:2
        // {a:1, b:1, c:1

        int alp[256] ={0}, l=0, r=0, n = s.size(), max_len = 0;

        while(r<n){
            // cout << s[r]-'a' << endl;
            alp[s[r]]++;

            while(l<r && alp[s[r]]>1){
                alp[s[l]]--;l++;
            }
            // cout << l << " : " << r << " : " <<  alp[s[r]-'a'] << endl;

            max_len = max(max_len, r-l+1);
            r++;
        }
        return max_len;
    }

    int lengthOfLongestSubstringFirstTry(string s) {
        // unordered_map<int,int> umap;
        vector<int> hash(256, -1);

        int i=0, j=0, maxlen = 1, n=s.size();

        if(n<2) return n;

        while(j<n){

            if(hash[s[j]] != -1){
                if(hash[s[j]] >= i){
                    i = hash[s[j]]+1;
                }
                hash[s[j]] = j;
            }
            else{
                hash[s[j]] = j;
            }

            maxlen = max(maxlen, j-i+1);

            j++;
        }

        return maxlen;
    }
}; 
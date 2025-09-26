#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool IsPalindrome(string &s){
            // cout << s << endl;
            int i=0, n = s.size()-1;
            // a a b a a
            // 0 1 2 3 4
            // 4 3 2 1 0
            while(i<=n && s[i] == s[n]){
                i++;n--;
            }
    
            if(i>n) return true;
            return false;        
        }
        bool IsPalindrome(string &s, int &start, int &end){
            // cout << s << endl;
            int i=start, n = end;
            // a a b a a
            // 0 1 2 3 4
            // 4 3 2 1 0
            // 
            while(i<=n && s[i] == s[n]){
                i++;n--;
            }
    
            if(i>n) return true;
            return false;        
        }
    
        void makePartition(int i, string &s, vector<string> &each_partition, vector<vector<string>> &partitions){
            if(i==s.size()){
                partitions.push_back(each_partition);return;
            }
    
            for(int c=i; c<s.size(); c++){
                if(IsPalindrome(s, i, c)){
                    //substr(begin, length);
                    each_partition.push_back(s.substr(i, c-i+1));
                    makePartition(c+1, s, each_partition, partitions);
                    each_partition.pop_back();
                }
            }
    
        }
    
        vector<vector<string>> partition(string s) {
            vector<vector<string>> partitions;
            vector<string> each_partition;
            makePartition(0, s, each_partition, partitions);
            return partitions;
        }
    };
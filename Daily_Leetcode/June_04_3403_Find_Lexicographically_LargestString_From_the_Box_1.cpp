#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string answerString(string word, int numFriends) {
    
            if(numFriends==1) return word;
    
            int i=0, j=1, k=i, n=word.size();
    
            while(j<n){
                // start to find word[j] > word[i] chracter
                while( j<n && word[i] > word[j]) j++;
    
                if(j<n && word[j]>word[i]){       //found a lexicographically larger letter , make it the ans
                    i=j;
                }
                else{ // else if both letters are same find the larger substring
                    int k=0;
                     while(j+k<n && word[i+k]==word[j+k]){      //eliminating or counting equal letters
                        k++;
                    }
                    if(j+k<n && word[i+k]<word[j+k])  i=j; // substring starts with j is better
                }
                j++;
            }
    
            return word.substr(i, min(n-i, n-numFriends+1));
    
        }
    
        string answerString1(string word, int numFriends) {
            // numFriends --> that many strings 
    
    
            // dbca --> 2 (1 split in each round)
            // round 1 --> d , bca
            // round 2 --> db, ca
            // round 3 --> dbc, a
            //  size n = 4 split = numFriends-1 (1)
            //  substring len = n-(numFriends-1)
            // 4 -(2-1) = 3
    
            // gggg --> 4 (3 splits in each round)
            // round 1 --> g, g, g, g
            // 4-(4-1) = 1
            // cout << word.size() << endl;
            if(numFriends==1) return word;
    
            // store all substrings of len n-numFriends+1 in max_heap adn get top value
            // priority_queue<string> max_heap;
            string max_s = "";
    
            int n = word.size(), substring_len = n-numFriends+1;
            for(int i=0; i<=n; i++){
                // cout << i << " : " << i+substring_len << " : " << word.substr(i, substring_len) << endl;
                // max_heap.push(word.substr(i, substring_len));
                max_s = max(max_s, word.substr(i, substring_len));
            }
    
            return max_s;
        }
    };
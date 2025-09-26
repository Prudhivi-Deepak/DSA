#include<bits/stdc++.h>
using namespace std;


// #define pair<char, vector<int>> P;
class Solution {
    public:
        // below solution MLE - try to optimize in terms of memory
        string clearStars(string s) {
            //map<int,vector<int>> index_map; //returns the smallest char and its index vector
            //lets use 26 stacks instead of map here
            stack<int> index_stack[26];
    
            int i=0;
            while(i<s.size()){
                if(s[i]=='*'){
                    int smallest_non_star_char_stack_index;
                    for(int k=0; k<26; k++){
                        if(index_stack[k].size()>0){
                            smallest_non_star_char_stack_index = index_stack[k].top();index_stack[k].pop();
                            break;
                        }
                    }
    
                    s[smallest_non_star_char_stack_index] = '*';
                    // auto smallest_non_star = index_map.begin();
                    // int smallest_non_star_char = smallest_non_star->first;
                    // vector<int> smallest_non_star_index = smallest_non_star->second;
    
                    // s[smallest_non_star_index.back()] = '*';
    
                    // smallest_non_star_index.erase(smallest_non_star_index.end()-1, smallest_non_star_index.end());
                    // if(!smallest_non_star_index.empty())
                    //     index_map[smallest_non_star_char] = smallest_non_star_index;
                    // else
                    //     index_map.erase(smallest_non_star_char);
                }
                else{
                    // index_map[s[i]].push_back(i);
                    index_stack[s[i]-'a'].push(i);
                }
                i++;
            }
    
            string ans="";
            for(int i=0; i<s.size(); i++){
                if(s[i]!='*') ans+=s[i];
            }
    
            return ans;
        }
    };
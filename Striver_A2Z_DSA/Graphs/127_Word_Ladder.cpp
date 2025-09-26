#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int BFS(string startWord, string targetWord, set<string> &setWords){
            queue<pair<string,int>> q; //storing node, len;
    
            q.push({startWord, 1});
            while(!q.empty()){
                auto [currWord, len] = q.front(); q.pop();
                if(currWord==targetWord) return len;
    
                // change every letter in every pos and check in set;
                for(int i=0; i<currWord.size(); i++){
                    char j = 'a';
                    string temp_currWord = currWord;
                    while(j-'a' < 27){
                        temp_currWord[i] = j;
                        if(setWords.count(temp_currWord)){
                            q.push({temp_currWord, len+1});
                            setWords.erase(temp_currWord);
                        }
                        j = char(j+1);
                    }
                }
            }
            return 0;
        }
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            set<string> setWords(wordList.begin(), wordList.end());
            return BFS(beginWord, endWord, setWords);
        }
    };
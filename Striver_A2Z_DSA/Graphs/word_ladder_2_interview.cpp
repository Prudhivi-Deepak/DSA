#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<string>> BFS(string startWord, string targetWord, set<string> &setWords){
            queue<pair<vector<string>,int>> q; //storing node, len;
            vector<vector<string>> allSeqs;
            
            q.push({{startWord}, 1});
            setWords.erase(startWord);
    
            while(!q.empty()){
    
                int size = q.size();
    
                set<string> eraseStrings = {};
    
                for(int j=0; j<size; j++){
    
                    auto [currWordVector, len] = q.front(); q.pop();
                    string currVectorlastWord = currWordVector.back();
                    if(currVectorlastWord==targetWord){
                        allSeqs.push_back(currWordVector);continue;
                    }
    
                    // change every letter in every pos and check in set;
                    for(int i=0; i<currVectorlastWord.size(); i++){
                        char j = 'a';
                        string temp_currWord = currVectorlastWord;
                        while(j-'a' < 27){
                            temp_currWord[i] = j;
                            if(setWords.count(temp_currWord)){
                                // cout << temp_currWord << " --> " ;
                                eraseStrings.insert(temp_currWord);
                                currWordVector.push_back(temp_currWord);
                                q.push({currWordVector, len+1});
                                currWordVector.pop_back();
                                // setWords.erase(temp_currWord);
                            }
                            j = char(j+1);
                        }
                    }
                }
    
                for(string setString : eraseStrings){
                    setWords.erase(setString);
                }
    
            }
            return allSeqs;
        }
        vector<vector<string>> findSequences(string beginWord, string endWord,
                                             vector<string> &wordList) {
            set<string> setWords(wordList.begin(), wordList.end());
            return BFS(beginWord, endWord, setWords);
        }
    };
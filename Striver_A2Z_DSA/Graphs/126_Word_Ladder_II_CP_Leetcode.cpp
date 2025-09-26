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

    //DFS from endword to beginWord
    void dfsCP(string beginWord, string endWord, unordered_map<string, int> &stringLevelMap, vector<string> &OneSeq, vector<vector<string>> &allSeqs){
        //start from teh endword
        OneSeq.push_back(endWord);
        if(endWord == beginWord){
            reverse(OneSeq.begin(), OneSeq.end());
            allSeqs.push_back(OneSeq);
            reverse(OneSeq.begin(), OneSeq.end());
            OneSeq.pop_back();
            return;
        }

        //try all possible positions and letters --> also if its present in stringLevelMap with one level below
        for(int i=0; i<endWord.size(); i++){
            string temp_endWord = endWord;
            for(char c='a'; c<='z'; c++){
                temp_endWord[i] = c;
                if(stringLevelMap[temp_endWord] == stringLevelMap[endWord]-1){
                    dfsCP(beginWord, temp_endWord, stringLevelMap, OneSeq, allSeqs);
                }
            }
        }
       
        OneSeq.pop_back();
    }

    // to create map with (word, len)
    void bfsCP(string beginWord, string endWord, set<string> setWords, unordered_map<string, int> &stringLevelMap){

        // unordered_map<string, int> stringLevelMap;
        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        setWords.erase(beginWord);

        while(!q.empty()){
            auto [ currWord, len] = q.front(); q.pop();
            stringLevelMap[currWord] = len;

            if(currWord == endWord){
                break;
            }

            for(int i=0; i<currWord.size();i++){
                string temp_currWord = currWord;
                for(char c='a'; c<='z'; ++c){
                    temp_currWord[i] = c;
                    if(setWords.count(temp_currWord)){
                        q.push({temp_currWord, len+1});
                        setWords.erase(temp_currWord);
                    }
                }
            }
        }
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> setWords(wordList.begin(), wordList.end());
        unordered_map<string, int> stringLevelMap;

        bfsCP(beginWord, endWord, setWords, stringLevelMap);

        // for(auto slm : stringLevelMap){
        //     cout << slm.first << " : " << slm.second << endl;
        // }

        vector<string> OneSeq;
        vector<vector<string>> allSeqs;

        dfsCP(beginWord, endWord, stringLevelMap, OneSeq, allSeqs);
        
        return allSeqs;
    }
};
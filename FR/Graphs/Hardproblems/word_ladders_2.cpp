class Solution{
public:
    vector<vector<string>> BFS(string beginWord, string endWord, unordered_set<string> &wordSet){
        queue<pair<vector<string>, int>> q;

        vector<vector<string>> allSeq;

        q.push({{beginWord}, 0});
        if(wordSet.count(beginWord)) wordSet.erase(beginWord);

        while(!q.empty()){
            
            unordered_set<string> eraseWordsSet;

            int qSize = q.size();

            for(int s=0; s<qSize; s++){
                auto [currSeq, len] = q.front(); q.pop();
                string lastWord = currSeq.back();

                if(lastWord == endWord) {
                    if(allSeq.empty() || allSeq.back().size() == currSeq.size()) allSeq.push_back(currSeq);
                    continue;
                }

                for(int i=0; i<lastWord.size(); i++){
                    string tempWord = lastWord;
                    for(int c=0; c<26; c++){
                        char ch = c+'a';
                        tempWord[i] = ch;
                        if(wordSet.count(tempWord)){
                            eraseWordsSet.insert(tempWord);
                            
                            currSeq.push_back(tempWord);
                            q.push({currSeq, len+1});
                            currSeq.pop_back();
                            
                        }
                    }
                }
            }

            for(string eraseString : eraseWordsSet){
                wordSet.erase(eraseString);
            }

        }
        return allSeq;
    }


    void bfs(string beginWord, string endWord, unordered_set<string> &wordSet, unordered_map<string,int> &stringLevelMap){

        queue<pair<string, int>> q;

        q.push({beginWord, 0});
        if(wordSet.count(beginWord)) wordSet.erase(beginWord);

        while(!q.empty()){
            auto [currString, len] = q.front(); q.pop();
            stringLevelMap[currString] = len;

            if(currString == endWord) return;

            for(int i=0; i<currString.size(); i++){
                string tempString = currString;

                for(int c=0; c<26; c++){
                    tempString[i] = c+'a';
                    if(wordSet.count(tempString)){
                        wordSet.erase(tempString);
                        q.push({tempString, len+1});
                    }
                }
            }
        }
        return;
    }

    void dfs(string beginWord, string endWord, unordered_map<string,int> &stringLevelMap, vector<vector<string>> &allSeq, vector<string> seq){

        seq.push_back(endWord);

        if(endWord == beginWord){
            reverse(seq.begin(), seq.end());
            allSeq.push_back(seq);
            reverse(seq.begin(), seq.end());
            seq.pop_back();
            return;
        }

        for(int i=0; i<endWord.size(); i++){
            string tempString = endWord;

            for(int c=0; c<26; c++){
                tempString[i] = c+'a';
                if(stringLevelMap[tempString] == stringLevelMap[endWord]-1){
                    dfs(beginWord, tempString, stringLevelMap, allSeq, seq);
                }
            }
        }

        seq.pop_back();

    }

    


    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        unordered_map<string,int> stringLevelMap;

        vector<vector<string>> allSeq;
        vector<string> seq;

        // return BFS(beginWord, endWord, wordSet);
        bfs(beginWord, endWord, wordSet, stringLevelMap);
        dfs(beginWord, endWord, stringLevelMap, allSeq, seq);
        return allSeq;
    }
};
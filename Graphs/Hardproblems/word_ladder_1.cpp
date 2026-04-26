class Solution{
public:

    int bfs(string startWord, string targetWord, unordered_set<string> wordSet){

        queue<pair<string, int>> q; //string, transformation count

        q.push({startWord, 1});

        while(!q.empty()){
            auto [currStr, count] = q.front(); q.pop();

            if(currStr == targetWord) return count;
            for(int i=0; i<currStr.size(); i++){
                string tempStr = currStr;
                for(int c=0; c<26; c++){
                    tempStr[i] = 'a'+c;
                    if(wordSet.count(tempStr)){
                        wordSet.erase(tempStr);
                        q.push({tempStr, count+1});
                    }
                }
            }
        }
        return 0;
    }

    

    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if(wordSet.count(targetWord)==0) return 0;

        // for(string word: wordList){
        //     wordSet.insert(word);
        // }
        return bfs(startWord, targetWord, wordSet);
    }
};
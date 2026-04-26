
struct TrieNode{
    TrieNode *letters[26];
    bool flag;
};

class Trie{
    public:
    TrieNode *head = new TrieNode();
    Trie(){

    }

    void insert(string word){
        TrieNode *tempHead = head;

        for(char c: word){
            int index = c-'a';

            if(tempHead->letters[index] == nullptr){
                TrieNode *currNode = new TrieNode();
                tempHead->letters[index] = currNode;
                tempHead = currNode;
            }
            else{
                tempHead = tempHead->letters[index];
            }
        }
        tempHead->flag = true;

    }

    bool searchForAllPrefix(string word){
        TrieNode *tempHead = head;
        for(char c : word){
            int index = c-'a';

            if(tempHead->letters[index]==nullptr) return false;
            if(tempHead->letters[index]->flag==false) return false;
            tempHead = tempHead->letters[index];
        }
        return tempHead->flag;
    }


};

class Solution {
public:
    string completeString(vector<string>& nums) {
        //your code goes here
        Trie *T = new Trie();
        for(string word: nums){
            T->insert(word);
        }

        int maxLength = 0;
        string maxString ;

        for(string word: nums){
            if(T->searchForAllPrefix(word)){
                if(maxLength < word.size()){
                    maxLength = word.size();
                    maxString = word;
                }
                else if(maxLength == word.size()){
                    if(word < maxString){
                        maxString = word;
                    }
                }
            }
        }
        return maxString;
    }
};
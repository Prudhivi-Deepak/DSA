#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode *alp[26];
    bool flag = false;
};

class Trie{
    public:
    TrieNode *root;
    Trie(){
        root = new TrieNode();
    };
    void insert(string word) {
        TrieNode *temp_root = root;
        for(int i=0; i<word.size(); i++){
            char c = word[i];
            int alp_index = c-'a';
            TrieNode *newTrieNode = new TrieNode();
            if(temp_root->alp[alp_index]==nullptr){
                temp_root->alp[alp_index] = newTrieNode;
                temp_root = newTrieNode;
            }
            else{
                temp_root = temp_root->alp[alp_index];
            }

            if(i==word.size()-1){
                temp_root->flag = true;
            }
        }
    }

    bool search(string word) {
        TrieNode *temp_root = root;
        for(int i=0; i<word.size(); i++){
            char c = word[i];
            int alp_index = c-'a';
            if(temp_root->alp[alp_index]==nullptr){
                return false;
            }
            else{
                temp_root = temp_root->alp[alp_index];
            }

            if(i==word.size()-1){
                return temp_root->flag;
            }
        }
    }

    bool startsWith(string prefix) {
        TrieNode *temp_root = root;
        for(int i=0; i<prefix.size(); i++){
            char c = prefix[i];
            int alp_index = c-'a';
            if(temp_root->alp[alp_index]==nullptr){
                return false;
            }
            else{
                temp_root = temp_root->alp[alp_index];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
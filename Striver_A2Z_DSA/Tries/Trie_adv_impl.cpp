#include <bits/stdc++.h>
using namespace std;


struct TrieNode{
    TrieNode *alp[26];
    int countWords = 0;
    int countPrefix = 0;
};

class Trie {
	public:
        TrieNode *root;
	    Trie() {
	        root = new TrieNode();
	    }

	    void insert(string word) {
            TrieNode *temp_root = root;
	        for(int i=0; i<word.size(); i++){
                // cout << "i : " << i << endl;
                char c = word[i];
                int index = c-'a';
                TrieNode *newNode = new TrieNode();
                if(temp_root->alp[index]==nullptr){
                    temp_root->alp[index] = newNode;
                    temp_root = newNode;
                    temp_root->countPrefix = temp_root->countPrefix+1;
                }
                else{
                    temp_root = temp_root->alp[index];
                    temp_root->countPrefix = temp_root->countPrefix+1;
                }
                // cout << temp_root->countPrefix << endl;

                if(i==word.size()-1){
                    temp_root->countWords = temp_root->countWords+1;
                }

            }
    	}

	    int countWordsEqualTo(string word) {
	        // return how many times its ends at countWords
            TrieNode *temp_root = root;
            for(int i=0; i<word.size(); i++){
                // cout << i << endl;
                char c = word[i];
                int index = c-'a';
                if(temp_root->alp[index]==nullptr){
                    return 0;
                }
                else{
                    temp_root = temp_root->alp[index];
                }

                // cout << c  <<  " : "  << i <<  " : " << word.size() << " : " << temp_root->countWords << endl;

                if(i==word.size()-1){
                    return temp_root->countWords;
                }
            }
    	}

	    int countWordsStartingWith(string word) {
	         TrieNode *temp_root = root;
            for(int i=0; i<word.size(); i++){
                char c = word[i];
                int index = c-'a';
                if(temp_root->alp[index]==nullptr){
                    return 0;
                }
                else{
                    temp_root = temp_root->alp[index];
                }

                if(i==word.size()-1){
                    return temp_root->countPrefix;
                }
            }
    	}

	    void erase(string word) {
	         TrieNode *temp_root = root;
            for(int i=0; i<word.size(); i++){
                char c = word[i];
                int index = c-'a';
                if(temp_root->alp[index]==nullptr){
                    return;
                }
                else{
                    temp_root = temp_root->alp[index];
                    temp_root->countPrefix = temp_root->countPrefix-1;
                }

                if(i==word.size()-1){
                    temp_root->countPrefix = temp_root->countPrefix-1;
                }
            }
	    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
#include <bits/stdc++.h>
using namespace std;


struct TrieNode1{
    TrieNode1 *alp[26];
    bool flag;
};

class Trie1{
    public:
    TrieNode1 *root;
    int totalUniqueSubstrings = 0;

    Trie1(){
        root = new TrieNode1();
    }

    void insert(string word){
        TrieNode1 *temp_root = root;
        for(int i=0; i<word.size(); i++){
            char c = word[i];
            int index = c-'a';
            TrieNode1 *newNode = new TrieNode1();
            if(temp_root->alp[index] == nullptr){
                temp_root->alp[index] = newNode;
                temp_root = newNode;
            }
            else{
                temp_root = temp_root->alp[index];
            }

            if(i==word.size()-1 && temp_root->flag==false){
                temp_root->flag = true;
                totalUniqueSubstrings +=1;
            }
        }
    }

    bool search(string word){
        TrieNode1 *temp_root = root;
        for(int i=0; i<word.size(); i++){
            char c = word[i];
            int index = c-'a';
            if(temp_root->alp[index] == nullptr){
                return false;
            }
            else{
                temp_root = temp_root->alp[index];
            }

            if(i==word.size()-1){
                return temp_root->flag;
            }
        }
    }

};

class Solution{	
	public:
		int countDistinctSubstring(string s){
			//your code goes here
            TrieNode1 *root = new TrieNode1();
            int count = 0;
            int n = s.size();
            for(int i=0; i<n; i++){
                TrieNode1 *rootNode = root;
                for(int j=i; j<n; j++){
                    char c = s[j];
                    int index = c-'a';

                    if(rootNode->alp[index] == nullptr){
                        TrieNode1 *newNode = new TrieNode1();
                        rootNode->alp[index] = newNode;
                        rootNode = newNode;
                        count++;
                    }
                    else{
                        rootNode = rootNode->alp[index];
                    }
                }
            }
            return count+1;
		}
};
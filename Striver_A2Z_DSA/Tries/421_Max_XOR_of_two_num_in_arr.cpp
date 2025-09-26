#include <bits/stdc++.h>
using namespace std;



struct TrieNode{
    TrieNode *bits[2];
};

class Trie{

    public:
    TrieNode *root;
    Trie(){
        root = new TrieNode();
    }

    void insert(int num){
        TrieNode *rootNode = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;

            if(rootNode->bits[bit]==nullptr){
                TrieNode *newNode = new TrieNode();
                rootNode->bits[bit] = newNode;
                rootNode = newNode;
            }
            else{
                rootNode = rootNode->bits[bit];
            }
        }
    }

    int getMaximumXOR(int num){
        int maximumXor = 0;
        TrieNode *rootNode = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            int needbit = 1-bit;

            if(rootNode->bits[needbit]!=nullptr){
                maximumXor = maximumXor | (1<<i);
                rootNode = rootNode->bits[needbit];
            }
            else{
                rootNode = rootNode->bits[bit];
            }
        }
        return maximumXor;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *trie = new Trie();

        for(int i=0; i<nums.size(); i++){
            trie->insert(nums[i]);
        }

        int maximumXor = 0;

        for(int i=0; i<nums.size(); i++){
            maximumXor = max(maximumXor, trie->getMaximumXOR(nums[i]));
        }
        return maximumXor;
    }
};
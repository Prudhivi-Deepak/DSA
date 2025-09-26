#include <bits/stdc++.h>
using namespace std;


// struct TrieNode{
//     TrieNode *alp[26];
//     int countWords = 0;
//     int countPrefix = 0;
// };

// class Trie{
//     public:
//     TrieNode root;

//     Trie(){
//         root = new TrieNode();
//     }

//     void insert(string word){
//         TrieNode *temp_root = root;
//         for(int i=0; i<word.size(); i++){
//             char c = word[i];
//             int index = c-'a';
//             TrieNode *newNode = new TrieNode();
//             if(temp_root->alp[index] == nullptr){
//                 temp_root->alp[index] = newNode;
//                 temp_root = newNode;
//                 temp_root->countPrefix = temp_root->countPrefix+1;
//             }
//             else{
//                 temp_root = temp_root->alp[index];
//                 temp_root->countPrefix = temp_root->countPrefix+1;
//             }

//             if(i==word.size()){
//                 temp_root->countWords = temp_root->countWords+1;
//             }
//         }
//     }

//     int countWordswithPrefix(string word){
//         TrieNode *temp_root = root;
//         for(int i=0; i<word.size(); i++){
//             char c = word[i];
//             int index = c-'a';
//             if(temp_root->alp[index] == nullptr){
//                 return 0;
//             }
//             else{
//                 temp_root = temp_root->alp[index];
//             }

//             if(i==word.size()){
//                 return temp_root->countPrefix;
//             }
//         }
//     }

//     int countWordsEnd(string word){
//         TrieNode *temp_root = root;
//         for(int i=0; i<word.size(); i++){
//             char c = word[i];
//             int index = c-'a';
//             if(temp_root->alp[index] == nullptr){
//                 return 0;
//             }
//             else{
//                 temp_root = temp_root->alp[index];
//             }

//             if(i==word.size()){
//                 return temp_root->countWords;
//             }
//         }
//     }

//     int countWordsEnd(string word){
//         TrieNode *temp_root = root;
//         for(int i=0; i<word.size(); i++){
//             char c = word[i];
//             int index = c-'a';
//             if(temp_root->alp[index] == nullptr){
//                 return 0;
//             }
//             else{
//                 temp_root = temp_root->alp[index];
//             }

//             if(i==word.size()){
//                 return temp_root->countWords;
//             }
//         }
//     }
// }


struct TrieNode1{
    TrieNode1 *alp[26];
    bool flag;
};

class Trie1{
    public:
    TrieNode1 *root;

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

            if(i==word.size()-1){
                temp_root->flag = true;
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

    bool searchWordWithAllPrefix(string word){
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

            if(!temp_root->flag) return false;

            if(i==word.size()-1){
                return temp_root->flag;
            }
        }
    }


};


class Solution {
public:
    string completeString(vector<string>& nums) {
        //your code goes here
        Trie1 *trie = new Trie1();
        for(int i=0; i<nums.size(); i++){
            trie->insert(nums[i]);
        }

        string longestString = "";
        int maxLength = 0;

        for(int i=0; i<nums.size(); i++){
            if(trie->searchWordWithAllPrefix(nums[i])){
                if(maxLength < nums[i].size()){
                    maxLength = nums[i].size();
                    longestString = nums[i];
                }
                else if(maxLength == nums[i].size()){
                    if(nums[i] < longestString){
                        longestString = nums[i];
                    }
                }
            }
        }

        if(longestString == "") return "None";
        return longestString;
    }
};
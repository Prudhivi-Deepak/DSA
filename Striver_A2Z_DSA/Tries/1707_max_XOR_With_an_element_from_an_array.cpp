#include <bits/stdc++.h>
using namespace std;


struct TrieNode {
    TrieNode *bits[2];
};

class Trie {
   public:
    TrieNode *root;
    Trie() { root = new TrieNode(); }

    void insert(int num) {
        TrieNode *rootNode = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (rootNode->bits[bit] == nullptr) {
                TrieNode *newNode = new TrieNode();
                rootNode->bits[bit] = newNode;
                rootNode = newNode;
            } else {
                rootNode = rootNode->bits[bit];
            }
        }
    }

    int getMaximumXOR(int num) {
        int maximumXor = 0;
        TrieNode *rootNode = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int needbit = 1 - bit;

            if (rootNode->bits[needbit] != nullptr) {
                maximumXor = maximumXor | (1 << i);
                rootNode = rootNode->bits[needbit];
            } else {
                rootNode = rootNode->bits[bit];
            }
        }
        return maximumXor;
    }
};

class Solution {
public:
    bool static comparator(vector<int> v1, vector<int> v2) {
        return v1[1] < v2[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        Trie *trie = new Trie();
        // 0 1 2 4 5 9 ==> sorted
        // 3, 0 | 3, 10 | 7, 5  ==> sort by second element
        // push each number along with that check for queries if number matches
        // any second value in queries
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][0], queries[i][1], i});
        }

        sort(q.begin(), q.end(), comparator);
        vector<int> ans(queries.size(), 0);
        int i = 0, n = nums.size();

        for (auto qy : q) {
            while (i < n && nums[i] <= qy[1]) {
                trie->insert(nums[i]);
                i++;
            }
            // ans[qy[2]] = trie->getMaximumXOR(qy[0]);
            if (i == 0) {
                ans[qy[2]] = -1;
            } else {
                ans[qy[2]] = trie->getMaximumXOR(qy[0]);
            }
        }

        return ans;
    }
};

struct TrieNode{
    TrieNode *bits[2];
};

class Trie{
    public:
    TrieNode *head = new TrieNode();
    Trie(){

    }

    void insert(int num){
        TrieNode *tempHead = head;

        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            
            if(tempHead->bits[bit] == nullptr){
                TrieNode *currNode = new TrieNode();
                tempHead->bits[bit] = currNode;
                tempHead = currNode;
            }
            else{
                tempHead = tempHead->bits[bit];
            }
        }

    }

    int getMaxXOR(int num){
        TrieNode *tempHead = head;
        int maximumXor = 0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            int neededBit = 1-bit;

            if(tempHead->bits[neededBit]!=nullptr){
                maximumXor = maximumXor | (1<<i);
                tempHead = tempHead->bits[neededBit];
            }
            else{
                tempHead = tempHead->bits[bit];
            }
        }
        return maximumXor;
    }

};

class Solution {
	public:
		int findMaximumXOR(vector<int>& nums) {
		      //your code goes here
              Trie *t = new Trie();
              for(int i : nums){
                t->insert(i);
              }

              int maxXor = 0;

              for(int i : nums){
                maxXor = max(maxXor, t->getMaxXOR(i));
              }
              return maxXor;
    	}
};
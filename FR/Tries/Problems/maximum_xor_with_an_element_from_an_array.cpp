
struct TrieNode{
    TrieNode *bits[2];
};

class Trie{
    public:
    TrieNode *head ;
    Trie(){
        head = new TrieNode();
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
        bool static comparator(vector<int> v1, vector<int> v2){
            return v1[1] < v2[1]; //how it should be there
        }

    	vector<int> maximizeXor(vector<int>& nums, vector<vector<int> >& queries) {
    		//your code goes here

            Trie *trie = new Trie();

            sort(nums.begin(), nums.end());

            vector<vector<int>> Queries;

            for(int i=0; i<queries.size(); i++){
                Queries.push_back({queries[i][0], queries[i][1], i});
            }

            sort(Queries.begin(), Queries.end(), comparator);

            vector<int> ans(queries.size(), 0);

            // for each query
            int i=0;
            for(auto q : Queries){
                // insert into trie untill q[1]
                while(i<nums.size() && nums[i]<=q[1]){
                    trie->insert(nums[i]); i++;
                }
                if(i==0){
                    ans[q[2]] = -1;
                }
                else{
                    ans[q[2]] = trie->getMaxXOR(q[0]);
                }
            }
            return ans;
    	}
};
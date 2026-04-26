struct TrieNode{
    TrieNode *letters[26];
    bool flag;
};

class Solution{	
	public:
		int countDistinctSubstring(string s){
			//your code goes here
            int count = 0;
            TrieNode *head = new TrieNode();
            int n = s.size();
            for(int i=0; i<n; i++){
                TrieNode *tempHead = head;
                for(int j=i; j<n; j++){
                    char c = s[j];
                    int index = c-'a';
                    // cout << c ;

                    if(tempHead->letters[index] == nullptr){
                        TrieNode *currNode = new TrieNode();
                        tempHead->letters[index] = currNode;
                        tempHead = currNode;
                        count++;
                    }
                    else{
                        tempHead = tempHead->letters[index];
                    }
                }
                // cout << endl;
            }
            return count+1;
		}
};

struct TrieNode{
    TrieNode *letters[26];
    int countLetters = 0;
    int countEnds = 0;    
};

class Trie {
	public:
        TrieNode *head = new TrieNode();
	    Trie() {
	        
	    }

	    void insert(string word) {
	        TrieNode *tempHead = head;
            for(char c: word){
                int index = c-'a';
                if(tempHead->letters[index] == nullptr){
                    TrieNode *currNode = new TrieNode();
                    currNode->countLetters++;
                    tempHead->letters[index] = currNode;
                    tempHead = currNode;
                }
                else{
                    tempHead->letters[index]->countLetters++;
                    tempHead = tempHead->letters[index];
                }
            }
            tempHead->countEnds++;
    	}

	    int countWordsEqualTo(string word) {
	        TrieNode *tempHead = head;
            for(char c: word){
                int index = c-'a';
                if(tempHead->letters[index]==nullptr) return 0;
                tempHead = tempHead->letters[index];
            }
            return tempHead->countEnds;
    	}

	    int countWordsStartingWith(string word) {
	        TrieNode *tempHead = head;
            for(char c: word){
                int index = c-'a';
                if(tempHead->letters[index]==nullptr) return 0;
                tempHead = tempHead->letters[index];
            }
            return tempHead->countLetters;
    	}

	    void erase(string word) {
	        TrieNode *tempHead = head;
            for(char c: word){
                int index = c-'a';
                if(tempHead->letters[index]==nullptr) return;
                tempHead->letters[index]->countLetters--;
                tempHead = tempHead->letters[index];
            }
            tempHead->countEnds--;
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
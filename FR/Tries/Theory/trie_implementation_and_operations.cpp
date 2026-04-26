
struct TrieNode{
    TrieNode *letters[26];
    bool flag;
};

class Trie{
    public:
    TrieNode *head;
    Trie(){
        head = new TrieNode();
    }
    void insert(string word) {
        TrieNode *tempHead = head;

        for(char c : word){
            int index = c-'a';
            if(tempHead->letters[index] == nullptr){
                TrieNode *currNode = new TrieNode();
                tempHead->letters[index] = currNode;
                tempHead = currNode;
            }
            else{
                tempHead = tempHead->letters[index];
            }
        }

        tempHead->flag = true;
    }

    bool search(string word) {
        TrieNode *tempHead = head;
        for(char c : word){
            int index = c-'a';
            if(tempHead->letters[index]==nullptr) return false;
            tempHead = tempHead->letters[index];
        }
        return tempHead->flag;
    }

    bool startsWith(string prefix) {
        TrieNode *tempHead = head;
        for(char c : prefix){
            int index = c-'a';
            if(tempHead->letters[index]==nullptr) return false;
            tempHead = tempHead->letters[index];
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
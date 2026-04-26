struct Node {
    int key;
    int value;
    int freq;

    Node(int k, int v){
        key = k;
        value = v;
        freq = 1;
    }
};

class LFUCache {
public:
    unordered_map<int, Node*> keyNode;           // key → node
    unordered_map<int, list<Node*>> freqList;    // freq → list of nodes
    int cap;
    int minFreq;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node){
        int f = node->freq;

        // remove from current freq list
        freqList[f].remove(node);

        // if this was the only node in minFreq list
        if(f == minFreq && freqList[f].empty()){
            minFreq++;
        }

        // increase freq
        node->freq++;

        // add to new freq list
        freqList[node->freq].push_back(node);
    }

    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1;

        Node* node = keyNode[key];
        updateFreq(node);

        return node->value;
    }

    void put(int key, int value) {
        if(cap == 0) return;

        // key exists → update + move
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        // capacity full → evict LFU
        if(keyNode.size() == cap){
            Node* nodeToRemove = freqList[minFreq].front();
            freqList[minFreq].pop_front();

            keyNode.erase(nodeToRemove->key);
            delete nodeToRemove;
        }

        // insert new node
        Node* newNode = new Node(key, value);
        keyNode[key] = newNode;

        freqList[1].push_back(newNode);
        minFreq = 1;
    }
};


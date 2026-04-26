
struct Node {
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int key_, int val){
        key = key_;
        value = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
  public:
  Node *head, *tail;
  unordered_map<int, Node *> umap; 
  int cap ;
  LRUCache(int capacity) {
    head = tail = nullptr;
    cap = capacity;
  }

  void display(){
    Node *hh = head;
    while(hh!=nullptr){
        cout << hh->value << " --> ";
        hh = hh->next;
    }
    cout << endl;
  }

  int get(int key_) {
    // cout << "get : " << key_ << endl;
    if(umap.find(key_) == umap.end()) return -1;

    // key exists delete it and insert at end
    auto currNode = umap[key_];
    
    if(tail == currNode){
        // cout << "getting from tail" << endl;
    }
    else if(head == currNode){
        // cout << "getting from head" << endl;
        // detach from head
        head = currNode->next;
        if(head) head->prev = nullptr;

        // attach at tail
        currNode->next = nullptr;
        currNode->prev = tail;
        tail->next = currNode;
        tail = currNode;

    }
    else{
        // cout << "getting from middle" << endl;
        // dettached
        if(currNode->prev) currNode->prev->next = currNode->next;
        if(currNode->next) currNode->next->prev = currNode->prev;

        // attach at tail
        currNode->next = nullptr;
        currNode->prev = tail;
        tail->next = currNode;
        tail = currNode;

    }
    // display();
    return currNode->value;

  }

  void put(int key_, int value) {
    // cout << "put : " << key_ << " value : " << value << endl;
    Node *currNode = nullptr;
    if(umap.find(key_) != umap.end()){
        currNode = umap[key_];
        currNode -> value = value;
        get(key_);
        return;
    }
    else{
        currNode = new Node(key_, value);
    }
    // cout << "capacity : " << cap << endl;

    if(umap.size()==cap){
        // no capacity
        // delete node from head
        // cout << "deleteing node because no capacity" << endl;
        // if(head) cout << "key:value  = " << head->key << " : " << head->value << endl;
        // if(umap.find(head->key) != umap.end()) umap.erase(head->key);
        // if(head) head = head->next;
        // if(head) head->prev = nullptr;
        Node* temp = head;
        if(temp) {
            umap.erase(temp->key);
            head = head->next;
            if(head) head->prev = nullptr;
            else tail = nullptr;
            delete temp;
        }
    }

    if(head==nullptr && tail == nullptr){
        head = tail = currNode;
    }
    else{
        currNode->prev = tail;
        currNode->next = nullptr;
        tail->next = currNode;
        tail = currNode;
    }
    umap[key_] = currNode;
    // display(head);
    return;
  }
};

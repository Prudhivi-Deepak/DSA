class QueueStack {
public:
    queue<int> q;
    QueueStack() {
    }
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        while(size>0){
            q.push(q.front()); q.pop(); size--;
        }
    }
    
    int pop() {
        int tp = q.front(); q.pop();
        return tp;
    }
    
    int top() {
        return q.front();
    }
    
    bool isEmpty() {
        return q.empty();
    }
};
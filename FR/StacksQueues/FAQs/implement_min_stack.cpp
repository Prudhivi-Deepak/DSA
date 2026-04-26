
class MinStack {
   public:
    stack<int> st;
    int mini = 1e9;
    MinStack() {

    }

    void push(int value) {
        if(st.empty()){
            mini = value;
            st.push(value);
        }
        else if(value < mini){
            // value is new mini --> we have to modify it 
            int modified_value = 2*value - mini;
            st.push(modified_value);
            mini = value;
        }
        else{
            // mini is th eminimum value;
            st.push(value);
        }
    }

    void pop() {
        // we might pop the modified value --> means have to modify mini too
        int tp_value = st.top(); st.pop();
        if(tp_value < mini){
            // modified value --> so modify the mini too
            mini = 2*mini - tp_value;
        }
    }

    int top() {
        // we have to return top value (but it might be modified value)
        
        if(st.top() < mini){
            // modified value
            return mini;
        }
        // else jsut return top value
        return st.top();
    }

    int getMin() { return mini;}
};
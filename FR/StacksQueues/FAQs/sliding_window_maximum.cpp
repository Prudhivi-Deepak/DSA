class Solution{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k) {
        // 4 0 -1 3 5 3 6 8
        // Q --> monotonic increasing Q
        // remove invalid entries from front (out of window)
        // use dequeue
        deque<int> dq;

        vector<int> window;

        for(int i=0; i<arr.size(); i++){

            // keep the valid window 
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();

            // remove invalid back entries and push the i value
            // we need to push i after removing minimum values than i 

            while(!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();

            // now we can push i 
            dq.push_back(i);

            // now take max from valid window whihc is th efirst front one
            if(i >= k-1){
                window.push_back(arr[dq.front()]);
            }

        }
        return window;
    }
};
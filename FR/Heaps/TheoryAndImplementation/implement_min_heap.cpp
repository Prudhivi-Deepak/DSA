class Solution{
    public:

        vector<int> minHeap;

        void initializeHeap(){
            minHeap.clear();
        }

        void heapifyUp(int ind){
            while(ind>0){
                int parent = (ind-1)/2;
                if(parent>=0 && minHeap[parent] > minHeap[ind]){
                    swap(minHeap[parent], minHeap[ind]);
                }
                else break;
                ind = parent;
            }
        }

        void heapifyDown(int ind){
            while(ind < minHeap.size()){
                int child1 = 2*ind+1, child2 = 2*ind+2;

                int smallest_index = ind;

                if(child1 < minHeap.size() && minHeap[child1] < minHeap[smallest_index]) smallest_index = child1;
                if(child2 < minHeap.size() && minHeap[child2] < minHeap[smallest_index]) smallest_index = child2;

                if(smallest_index == ind) break;
                swap(minHeap[smallest_index], minHeap[ind]);
                ind = smallest_index;
            }
        }

        void insert(int key){
            minHeap.push_back(key);
            heapifyUp(minHeap.size()-1);
        }

        void changeKey(int index, int new_val){
            minHeap[index] = new_val;

            int parent = (index-1)/2;
            
            if(parent >=0 && minHeap[index] < minHeap[parent]){
                heapifyUp(index);
            }
            else{
                heapifyDown(index);
            }
        }

        void extractMin(){
            if(minHeap.empty()) return;
            swap(minHeap[0], minHeap.back()); minHeap.pop_back();
            heapifyDown(0);
        }

        bool isEmpty(){
            return minHeap.empty();   
        }

        int getMin(){
            return minHeap[0];
        }

        int heapSize(){
            return minHeap.size();
        }
};
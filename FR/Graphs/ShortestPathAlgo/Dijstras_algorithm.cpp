
struct compare{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        return p1.first > p2.first;
    }
};

class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        set<pair<int,int>> st; //stores in asc order;
        vector<int> shortDist(V, 1e9);
        shortDist[S] = 0;
        st.insert({0,S});

        while(!st.empty()){
            auto [ dist, currNode ] = *(st.begin());st.erase(st.begin());

            for(vector<int> k : adj[currNode]){
                int node = k[0];
                int w = k[1];
                int cal_dist = dist + w;
                if(cal_dist < shortDist[node]){

                    if(shortDist[node]!=1e9){
                        st.erase({shortDist[node], node});
                    }
                    shortDist[node] = cal_dist;
                    st.insert({cal_dist, node});
                }
            }
        }
        return shortDist;
    }
    // TC  -  O((V+E)logV) , C - O(V)
    vector<int> dijkstraPQ(int V, vector<vector<int>> adj[], int S) {
        //min_heap // (dist, node) => 
        // start with S node with 0 dist in queue
        // in while loop
        //      calculate dist to adjacent nodes --> less dist(change) insert into Q;
        // q.empty() -> exit
        // priority_queue<pair<int, int>, vector<pair<int,int>, greater<pair<int,int>> min_heap;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        vector<int> shortDist(V, 1e9);
        shortDist[S] = 0;
        min_heap.push({0,S});

        while(!min_heap.empty()){
            auto [dist, currNode] = min_heap.top(); min_heap.pop();

            for(vector<int> k : adj[currNode]){
                int node = k[0];
                int w = k[1];

                int cal_dist = dist + w;
                if(cal_dist < shortDist[node]){
                    shortDist[node] = cal_dist;
                    min_heap.push({cal_dist, node});
                }
            }
        }

        return shortDist;
    }
};
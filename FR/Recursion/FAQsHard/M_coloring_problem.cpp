class Solution{
public:

    bool isValid(int colorCanBeSet, int vertex, vector<int> colors, vector<vector<int>> &adj){

        // check if all colorCanBeSet
        for(auto neg : adj[vertex]){
            if(colors[neg] == colorCanBeSet) return false;
        }
        return true;
    }

    bool f(int prevColor, int vertex, int m, int n, vector<int> colors, vector<vector<int>> &adj){ 

        if(vertex==n) return true;        

        for(int color = 1; color<=m; color++){
            // set any one color apart from prevColor && valid one
            if(color != prevColor && isValid(color, vertex, colors, adj)){
                colors[vertex] = color;
                if(f(color, vertex+1, m, n, colors, adj)) return true;
                colors[vertex] = -1;
            }
        }

        return false;

    }


    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
    	//your code goes here

        // make a adj list first
        // iterate from 0 vertex assign color 0 (0 to m colors)
        // go to its neighbours (you can assign any color other than prev color)
        // then go to their neg and try to assign the colors
        // if already assigned and prev color is also same return false that color can't be assigned

        vector<vector<int>> adj(n);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> colors(n, -1);

        // you can start with coloring any color from 1 to make
        return f(-1, 0, m, n, colors, adj);


    }
};
class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int top = 0, down = M.size()-1;

        while(top < down){
            if(M[top][down]==1) top++;
            else if(M[down][top]) down--;
            else{
                top++;
                down--;
            }
        }

        // check if top is celebrity
        for(int i=0; i<M.size(); i++){
            if(i!=top && M[top][i]==1) return -1;
            // top knows someone so he is not celebrity
            if(i!=top && M[i][top]==0) return -1;
            // top is not known by someone so he is not celebrity
        }
        return top;
    }
};

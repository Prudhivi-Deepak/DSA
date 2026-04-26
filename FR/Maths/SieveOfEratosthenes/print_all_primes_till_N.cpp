class Solution{
    public:
        vector<int> primeTillN(int n){
            //your code goes here
            vector<bool> primes(n+1, true);
            primes[0] = false;
            primes[1] = false;
            
            for(int i=2; i<=n; i++){
                if(primes[i]){
                    int multiple = 2;
                    while(i*multiple<=n){
                        primes[i*multiple] = false;
                        multiple++;
                    }
                }
            }

            vector<int> ans;
            for(int i=0; i<=n; i++){
                if(primes[i]) ans.push_back(i);
            }
            return ans;
        }
};
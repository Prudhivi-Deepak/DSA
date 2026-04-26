#define MAX_N 100000

vector<bool> primes(MAX_N+1, true);

class Solution{
    public:
        void findPrimes(){
            primes[0] = false;
            primes[1] = false;
            for(int i=2; i<=MAX_N; i++){
                if(primes[i]){
                    int multiple = 2;
                    while(i*multiple <= MAX_N){
                        primes[i*multiple] = false;
                        multiple++;
                    }
                }
            }
        }

        vector<int> primesInRange(vector<vector<int>>& queries){
            //your code goes here
            findPrimes();
            vector<int> prefixPrimeCount(MAX_N+1, 0);
            int cnt = 0;
            for(int i=0; i<=MAX_N; i++){
                if(primes[i]) cnt++;
                prefixPrimeCount[i] = cnt;
            }

            // for each queries we already have the prefixPrimeCount
            // so return simplly prefixPrimeCount[q[1]] - prefixPrimeCount[q[0]]
            // prefixPrimeCount[i] means = no. of prime number untill i (including it)
            vector<int> ans;
            for(auto q: queries){
                // cout << "--------" << endl;
                // cout << q[1] << " : " << prefixPrimeCount[q[1]] << endl;
                // cout << q[0] << " : " << prefixPrimeCount[q[0]] << endl;
                // cout << q[0]-1 << " : " << prefixPrimeCount[q[0]-1] << endl;
                ans.push_back(prefixPrimeCount[q[1]] - prefixPrimeCount[q[0]-1]);
            }
            return ans;
        }
};
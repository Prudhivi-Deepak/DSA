#define MAX_N 100000

vector<int> primes(MAX_N+1, 1);

class Solution{
    public:
        vector<vector<int>> primeFactors(vector<int>& queries){
            //your code goes here
            primes[0] = false;
            primes[1] = false;
            
            for(int i=2; i<=MAX_N; i++){
                if(primes[i]){
                    int multiple = 2;
                    while(i*multiple<=MAX_N){
                        primes[i*multiple] = false;
                        multiple++;
                    }
                }
            }

            vector<vector<int>> prime_factors;
            for(int q : queries){
                vector<int> prime_factor;
                int num = q;
                for(int j=2; j<=MAX_N; j++){
                    if(primes[j]){
                        while(num%j==0) {
                            prime_factor.push_back(j);
                            num = num/j;
                        }
                    }
                    if(num==1) break;
                }
                prime_factors.push_back(prime_factor);
            }
            return prime_factors;
        }
};

#include <bits/stdc++.h>
using namespace std;



class Solution {
    public:
        vector<int> findMissingRepeatingNumbers(vector<int> nums) {
            int Xor = 0;
    
            for(int i=0; i<nums.size(); i++){
                Xor ^= nums[i];
                Xor ^= (i+1);
            }
    
            int first_bit = (Xor & ~(Xor-1));
    
            int zero_number = 0, one_number = 0;
    
            for(int i=0; i<nums.size(); i++){
                if((nums[i]&first_bit) != 0) one_number ^= nums[i];
                else zero_number ^= nums[i];
    
                if(((i+1)&first_bit) != 0 ) one_number ^= (i+1);
                else zero_number ^= (i+1);
            }
    
            int cnt = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==zero_number) cnt++;
                if(cnt>1) return {zero_number, one_number};
            }
    
            return {one_number, zero_number};
    
    
        }
        vector<int> findMissingRepeatingNumbers1(vector<int> nums) {
            long long n = nums.size();
            long long sum = 0;
            long long sum_of_n_natural_num = n*(n+1)/2;
            long long sum_of_squares = 0;
            long long sum_of_n_natural_squares = n*(n+1)*(2*n+1)/6;
    
            for(int i=0; i<n; i++){
                sum += nums[i];
                sum_of_squares += ((long long)nums[i]*nums[i]);
            }
    
            // x - y = s - sn, x^2 - y^2 = s^2 - sn^2 => x+y = (s^2 - sn^2)/(x-y);
            // x-y + x+y = s-sn + s^2 - sn^2;
    
            long long x_minus_y = (long long)sum - sum_of_n_natural_num;
            long long x_plus_y = ((long long)sum_of_squares - sum_of_n_natural_squares)/x_minus_y;
    
            long long x = (x_minus_y + x_plus_y)/2;
            long long y = x_plus_y - x;        
    
            return {(int)x,(int)y};
        }
    };
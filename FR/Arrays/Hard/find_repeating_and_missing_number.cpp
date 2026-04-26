class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        // xor of all given numebr and 1 to n numbers gives us duplicate^missing number xor
        // so we already know how to find 2 numbers of a xor --> find right most bit difference

        int Xor = 0;
        for(int i=0; i<nums.size(); i++){
            Xor ^= (i+1);
            Xor ^= nums[i];
        }

        int rightMostBit = Xor & -Xor;

        int zero = 0, ones = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]&rightMostBit){
                ones ^= nums[i];
            }
            else zero ^= nums[i];

            if((i+1)&rightMostBit){
                ones ^= (i+1);
            }
            else zero ^= (i+1);
        }

        int zeroCnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==zero) zeroCnt++;
            if(zeroCnt > 1) return {zero, ones};
        }

        return {ones, zero};








        // 1 to n numbers 
        // a number will be repeated 2 times 
        // and one number is missed

        // 1 to n sum = n*(n+1)/2

        // exps sum - actual sum = duplicate num - missing diff

        // sort --> duplicated
        // exp sum, act sum, duplicate 
        // act sum - duplicate = +missing
        // exp sum - (acutsum-duplicate) = missing 

        // 1 to n 
        // 1 to n 2 missing number

        // sum of squares of 1 to n number = n*(n+1)*(2n+1)/6

        // 7 = 7*(7+1)*(14+1)/6 =  140

        // 1 4 9 36 49 49 25 = 174














    }
};
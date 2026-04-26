class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			//your code goes here

            int all_xor = 0;
            for(int x : nums){
                all_xor ^= x;
            }

            int rightMostbit = all_xor & -all_xor;

            int zero = 0, one = 0;
            for(int i : nums){
                if(rightMostbit & i){
                    one ^= i;
                }
                else{
                    zero ^= i;
                }
            }
            if(one < zero) return {one, zero};
            return {zero, one};

        //     1 2 1 3 5 2

        //     so we need to return 2 intergers
            
        //     1^2^1^3^5^2
        //     1 = 0001 --> 1 zero
        //     2 = 0010 --> 2 one
        //     ^ = 0011
        //     1 = 0001 --> 1 zero
        //     ^ = 0010
        //     3 = 0011 --> 3 one
        //     ^ = 0001
        //     5 = 0101 --> 5 zero
        //     ^ = 0100
        //     2 = 0010 --> 2 one
        //     ^ = 0110 = 6 final xor is something xor of unique digits

        //     i know xor of any 2 digits  = for sure one bit has difference
        //     so we find that bit difference and 


        //     6 = 0110 -- n
        // 1's 6 = 1001
        // 2's 6 = 1010 -- (-n)
        //     6 = 0110
        // --------------
        //     & = 0010 -- (n & -n)
        //     ----------

        //     to get right most bit we can do (n & (n-1))^n or (n & -n) 

        //     one = 2^3^2 = 3
        //     zero = 1^1^5 = 5



            

        

        
            



		}
};
class Solution{	
	public:
        int xorRangeN(int num){
            if(num %4 == 0) return num;
            else if(num % 4 == 1) return 1;
            else if(num % 4 == 2) return num+1;
            return 0;
        }
		int findRangeXOR(int l,int r){
			//your code goes here
            
            // 1 2 3 4 5
            // 1 3 0 4 1 --> this pattern repeats
            // so 
            // 1, 5 --> 1 1  so num%4 == 1
            // 2 --> 3 (num+1) so num%4 == 2
            // 3 --> 0 (0)     so num%4 == 3
            // 4 --> 4 (num)   so num%4 == 0

            return xorRangeN(r)^xorRangeN(l-1);
		}
};
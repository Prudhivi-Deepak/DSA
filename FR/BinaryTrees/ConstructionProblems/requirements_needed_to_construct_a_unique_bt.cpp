class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			//your code goes here

            return ((a==2) || (b==2)) && (a!=b);

		}
};
class Solution{    
  public:    
    bool lemonadeChange(vector<int>& bills){
        //your code goes here
        int five = 0, ten = 0;
        // 5 5 10 10 20
        // five = 0
        // ten = 2

        for(int b : bills){

            if(b==5) five++;
            else if(b==10){
                if(five>0) {
                    five--;
                    ten++;
                }
                else return false;
            }
            else{
                if(ten>0 && five>0){
                    ten--;
                    five--;
                }
                else if(five > 2){
                    five-=3;
                }
                else return false;
            }
            // cout << five << " : "<< ten << endl;
        }
        return true;
    }
};
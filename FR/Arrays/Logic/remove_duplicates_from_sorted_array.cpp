class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // 0 3 5 6 5 6
        //           i
        //       j
        // we have to fill first k positions with k unique numbers in array
        // start i=1 and index = 0
        // compare if equal --> i++
        // else we do index++ then do nums[index] = nums[i];i++;
        // okay until end of the array done

        int index = 0, i = 1;

        while(i < nums.size()){
            if(nums[i]!=nums[index]){
                nums[++index] = nums[i];
            }
            i++;
        }

        return index+1;
    }
};
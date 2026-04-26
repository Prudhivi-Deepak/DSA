class Solution {
public:
    int studentsAssigned(vector<int> &nums, int pages){

        int students = 0, currPages = 0;

        for(int p : nums){
            currPages += p;
            if(currPages>pages){
                students++;
                currPages=p;
            }
        }

        if(currPages!=0 && currPages<= pages) students++;

        // cout << pages << " : " << students << endl;
        
        return students;
    }

    int findSum(vector<int> &nums){
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        return sum;
    }

    int findMax(vector<int> &nums){
        int maxi = INT_MIN;
        for(int i : nums){
            maxi = max(maxi, i);
        }
        return maxi;
    }

    int findPages(vector<int> &nums, int m)  {

        // nums[i] represent ith book page 
        // m is the number of students
        // each student should get atleast one book
        // each book is allocated to only one student

        // we have to minimize the maximum pages assigned to student
        // return the minimized maximum pages value

        // so this return value can be in range of min pages, sum of all pages
        // so try all pages and take the maximum value each time, --> take over all minimum value and return

        // so instead of trying all one by one, we do BS --> done

        if (m > nums.size()) return -1;

        int l = findMax(nums), r = findSum(nums), miniPages = INT_MAX;

        while(l<=r){
            int mid = l+(r-l)/2;

            int students = studentsAssigned(nums, mid);

            if(students<=m){
                // students are assigned proprely, we have to minimize the maximum value
                // so first go to minimum
                miniPages = min(miniPages, mid);
                r = mid-1;
            }
            else l = mid+1;
        }
        if(miniPages == INT_MAX) return -1;
        return miniPages;        
    }
};
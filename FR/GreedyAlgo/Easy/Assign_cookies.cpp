class Solution{    
    public:
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
        //your code goes here

        // students = 1, 2, 3
        // cookie = 1, 1

        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        int l = 0, r = 0, n = Student.size(), m = Cookie.size(), count=0;

        while(l<n && r<m){
            if(Cookie[r] >= Student[l]){
                r++;l++; count++;
            }
            else{
                r++;
            }
        }
        return count;
    }
};
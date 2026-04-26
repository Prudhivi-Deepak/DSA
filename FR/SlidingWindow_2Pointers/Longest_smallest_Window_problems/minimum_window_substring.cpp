class Solution {
public:
    string minWindow(string s, string t) {
        // //your code goes here
        // the first thought is like first maintain a umap of t 
        // t = {A:1, B:1, C: 1}
        // 0 1 2 3 4 5 6 7 8 9 10 11 12
        // A D O B E C O D E B  A  N  C
        //           l          r
        // t = {A:0, B:0, C: 0, D: -1, O: -1, E: -1 }
        // zeroCnt = 3 --> done 3 right save the length and try to shrink it currLen = 5-0+1 = 6 (start index = l)
        // zeroCnt = 2 --> try to increase
        // zeroCnt = 3 --> currLen = 10-1+1 = 10 (startIndex = 1(l)) --> try to shrink it
        // still zeroCnt = 3 so edit currLen = 10-5+1=6 (starIndex = (5)l)
        // like that carry on to get the currLen and startIndex
        // at last return s.substr(starIndex, currLen);

        // if a number changes to +ve that means we have one char less, we need it again
        // count no. of zeroes we got --> positive to 0 means we got all possible count for that character

        // unordered_map<char,int> umap;
        
        int umap[256] = {0};
        for(char c : t) umap[c]++;

        int l = 0, r = 0, maxLength = 0, n = s.size(), currLen = n+1, m = t.size(), zeroCnt = 0, startIndex = -1;
        // cout << n << " : " << m << endl;
        while(r < n){
            if(umap[s[r]]>0) zeroCnt++;
            umap[s[r]]--;
            
            // try to shrink it because we have all chars
            while(zeroCnt == m){
                if(r-l+1 < currLen){
                    currLen = r-l+1;
                    startIndex = l;
                }

                umap[s[l]]++;
                if(umap[s[l]]>0) zeroCnt--;
                l++;
            }
            r++;
        }
        // cout <<startIndex << ": " << currLen <<endl;
        if(startIndex == -1) return "";
        return s.substr(startIndex, currLen);
    }
};
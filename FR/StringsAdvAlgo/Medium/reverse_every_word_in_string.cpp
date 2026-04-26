class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int index = 0, i = 0, n = s.size();
        while(i<n){
            // skip initial empty spaces
            while(i<n && s[i]==' ') i++;

            // now fill index with characters
            while(i<n && s[i]!=' '){
                s[index++] = s[i++];
            }
            if(i<n) s[index++] = ' ';
            // cout << index << " : " << i << endl;
        }
         // remove trailing space if present
        if (index > 0 && s[index - 1] == ' ') index--;
        s.resize(index);

        // 3. Reverse each word
        i = 0;
        int start = 0;

        while (i <= index) {
            if (i == index || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
            i++;
        }

        return s;
    } 
};
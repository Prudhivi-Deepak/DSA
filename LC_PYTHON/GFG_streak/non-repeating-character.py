#User function Template for python3

class Solution:
    
    #Function to find the first non-repeating character in a string.
    def nonRepeatingChar(self,s):
        #code here
        allpos = 0
        duplicatepos = 0
        for i in range(len(s)):
            pos = 1 << ord(s[i])-97 
            if(pos & allpos):
                if(not(duplicatepos & pos)):
                    duplicatepos = duplicatepos | pos
            else:
                allpos = allpos | pos

        for i in range(len(s)):
            pos = 1 << ord(s[i])-97
            if(not(pos & duplicatepos)):
                return s[i]
        return '$'
    
    


#: 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = str(input())
        obj = Solution()
        ans = obj.nonRepeatingChar(s)
        if (ans != '$'):
            print(ans)
        else:
            print(-1)

        print("~")

#  Driver Code Ends
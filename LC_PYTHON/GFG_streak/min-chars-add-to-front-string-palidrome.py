class Solution:
    def minChar(self, s):
        #Write your code here
        n = len(s)
        s = s + '*' + s[::-1]
        lps_n = len(s)
        lps = [0]*lps_n
        i = 1
        match = 0
        while i < lps_n:
            if s[i] == s[match]:
                match+=1
                lps[i] = match
                i+=1
            else:
                if match != 0:
                    match = lps[match-1]
                else:
                    i+=1
        return n-lps[lps_n-1]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        s = input()
        obj = Solution()
        ans = obj.minChar(s)
        print(ans)
        print("~")

# } Driver Code Ends
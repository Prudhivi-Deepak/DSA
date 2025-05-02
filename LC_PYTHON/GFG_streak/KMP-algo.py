#User function Template for python3

class Solution:
    def ComputeLPS(self, pat):
        lps = [0]*len(pat)
        i = 1
        match = 0
        while i < len(pat):
            if pat[i] == pat[match] :
                lps[i] = match+1
                i+=1
                match+=1
            else:
                if match !=0:
                    match-=1
                else:
                    i+=1
        return lps
                    
    def search(self, pat, txt):
        # code here
        lps = self.ComputeLPS(pat)
        ans = []
        i = 0
        j = 0
        while i < len(txt):
            if txt[i] == pat[j]:
                i+=1
                j+=1
            else:
                if j!=0:
                    j = lps[j-1]
                else:
                    i+=1
            if j==len(pat):
                ans.append(i-j)
                j = lps[j-1]
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        patt = input().strip()
        ob = Solution()
        ans = ob.search(patt, s)
        if len(ans) == 0:
            print("[]", end="")
        for value in ans:
            print(value, end=' ')
        print()

# } Driver Code Ends
#User function Template for python3
class Solution:
    # Function to find hIndex
    def hIndex(self, citations):
        #code here
        n = len(citations)
        buckets = [0]*(n+1)
        
        for c in citations:
            if (c >= n):
                buckets[n]+=1
            else:
                buckets[c]+=1

        total = 0
        for i in range(n,-1,-1):
            total += buckets[i]
            if (total >= i):
                return i
        return 0


#{ 
 # Driver Code Starts
# Initial Template for Python 3

# Main
if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        arr = [int(x) for x in input().strip().split()]

        ob = Solution()
        result = ob.hIndex(arr)

        print(result)
        print("~")

# } Driver Code Ends
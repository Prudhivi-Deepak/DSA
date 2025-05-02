#User function Template for python3

import heapq

class Solution:

    def kthSmallest(self, arr,k):
        arr1 = []
        for i in arr:
            if len(arr1) == k:
                if heapq.nlargest(1, arr1)[0] > i:
                    heapq.heappop(arr1)                    
                    heapq.heappush(arr1, i)
                    heapq._heapify_max(arr1)
            else:
                heapq.heappush(arr1, i)
                heapq._heapify_max(arr1)
        return heapq.nlargest(1, arr1)[0]
        

#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__':
    import random
    t = int(input())
    for tcs in range(t):
        # n = int(input())
        arr = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.kthSmallest(arr, k))

# } Driver Code Ends
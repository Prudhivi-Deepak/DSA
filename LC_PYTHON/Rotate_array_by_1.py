#User function Template for python3

class Solution:
    def rotate(self, arr):
        prev = arr[-1]
        for i in range(len(arr)):
            arr[i], prev = prev, arr[i]
    



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        ob.rotate(arr)
        print(" ".join(map(str, arr)))
        print("~")
        t -= 1

# } Driver Code Ends
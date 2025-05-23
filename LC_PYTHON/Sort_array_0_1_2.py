class Solution:
    # Function to sort an array of 0s, 1s, and 2s
    def sort012(self, arr):
        # code here
        p0 = p1 = 0
        p2 = len(arr) - 1
        while p1 <= p2:
            if arr[p1] == 1:
                p1+=1
            elif arr[p1] == 0:
                arr[p1], arr[p0] = arr[p0], arr[p1]
                p0+=1
                p1+=1
            elif arr[p1] == 2:
                arr[p1], arr[p2] = arr[p2], arr[p1];
                p2-=1
         

#{ 
 # Driver Code Starts
def main():
    t = int(input().strip())  # Read the number of test cases
    ob = Solution()

    while t > 0:
        t -= 1
        arr = list(map(int,
                       input().strip().split())
                   )  # Read the array as space-separated integers
        ob.sort012(arr)  # Sort the array

        print(' '.join(map(str, arr)))  # Print the sorted array


if __name__ == "__main__":
    main()

# } Driver Code Ends
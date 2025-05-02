#{ 
 # Driver Code Starts

# } Driver Code Ends
class Solution:
    # Function to sort an array of 0s, 1s, and 2s
    def sort012(self, arr):
        # code here
        i = 0
        f = 0
        b = len(arr)-1
        while f<=b:
            if arr[f] == 0:
                if i==f:
                    i+=1
                    f+=1
                else:
                    arr[i], arr[f] = arr[f], arr[i]
                    i+=1
            elif arr[f] == 1:
                f+=1
            else:
                arr[b], arr[f] = arr[f], arr[b]
                b-=1

#{ 
 # Driver Code Starts.
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
        print("~")
        
if __name__ == "__main__":
    main()

# } Driver Code Ends
class Solution
{
public:
    int trap(vector<int> &height){
        int l = 0, r = height.size()-1, lmax = height[l], rmax = height[r], total = 0;

        while(l<r){

            while(l<r && height[l] <= height[r]){
                lmax = max(lmax, height[l]);
                total += (lmax-height[l]);
                l++;
            }

            while(l<r && height[r] < height[l]){
                rmax = max(rmax, height[r]);
                total += (rmax-height[r]);
                r--;
            }
        }
        return total;
    }

    int trap1(vector<int> &height){
        int n = height.size();
        vector<int> PrefixMax(n, -1);
        int maxi = height[0];
        for(int i=0; i<n; i++){
            if(height[i] > maxi) maxi = height[i];
            PrefixMax[i] = maxi;
        }

        maxi = height[n-1];
        int sum = 0;

        for(int i=n-1; i>=0; i--){
            if(height[i] > maxi) maxi = height[i];
            PrefixMax[i] = min(maxi, PrefixMax[i]);
            sum +=  (PrefixMax[i]-height[i]);
        }
        return sum;
    }
};
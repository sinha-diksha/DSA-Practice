class Solution {
public:

    int function(vector<int>& nums, int k){
        int n=nums.size();
        int l=0;
        int r=0;
        int oddCount=0;
        int ans=0;
        while(r<n){
            int value=nums[r]%2;
            oddCount+=value;
            while(oddCount>k ){
                oddCount-=(nums[l]%2);
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return function(nums,k) - function(nums,k-1);
    }
};
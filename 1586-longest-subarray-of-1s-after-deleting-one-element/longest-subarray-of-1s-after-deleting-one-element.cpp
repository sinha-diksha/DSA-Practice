class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int zeroCount=0;
        int ans=0;
        while(r<n){
            if(nums[r]==0){
                zeroCount++;
            }
            while(zeroCount>1){
                if(nums[l]==0){
                    zeroCount--;
                }
                l++;
            }
            ans=max(ans,r-l+1 );
            r++;
        }
        return ans-1;
    }
};
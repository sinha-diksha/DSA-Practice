class Solution {
public:
    bool function(vector<int>& nums, int n, int sum, vector<vector<int>>& t){
        if(sum==0) return true;
        if(n==0) return false;
        if(t[n][sum]!=-1) return t[n][sum];

        if(nums[n-1]<=sum){
            return t[n][sum]=function(nums,n-1, sum-nums[n-1], t) || function(nums, n-1, sum, t);
        }
        return t[n][sum]=function(nums, n-1, sum, t);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2==1) return false;
        
        int n=nums.size();
        vector<vector<int>> t(n+1, vector<int>(sum+1, -1));
        return function(nums,n,sum/2, t);
    }
};
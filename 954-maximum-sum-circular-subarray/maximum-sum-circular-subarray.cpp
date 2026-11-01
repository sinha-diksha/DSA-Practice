class Solution {
public:
    int kadanes(vector<int>& nums, int n){
        int sum=0;
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            ans=max(ans, sum);
            if(sum<0)  sum=0;
        }
        return ans;
    }
    int kadanesMin(vector<int>& nums, int n){
        int sum=nums[0];
        int ans=nums[0];
        for(int i=1; i<n; i++){
            sum=min(nums[i], sum+nums[i]);
            ans=min(sum, ans);

        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans1=kadanes(nums, n);
        int ans2=kadanesMin(nums, n);
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum==ans2) return ans1;
        int val2=sum-ans2;
        return max(ans1, val2);
    }
};
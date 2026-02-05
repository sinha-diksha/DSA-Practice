class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                int newI=(i+nums[i])%n;
                ans[i]=nums[newI];
            }else if(nums[i]<0){
                
                int val= abs(nums[i])/n;
                val = nums[i] + (val*n);
                int newI=(i-abs(val) + n)%n;
                ans[i]=nums[newI];
            }else{
                ans[i]=nums[i];
            }
        }
        return ans;
    }
};
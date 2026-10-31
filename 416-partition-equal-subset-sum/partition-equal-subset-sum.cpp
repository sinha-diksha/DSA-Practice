class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2==1) return false;
        sum/=2;
        int n=nums.size();
        vector<vector<bool>> t(n+1, vector<bool>(sum+1, false));
        for(int i=0; i<=sum; i++){
            t[0][sum]=false;
        }
        for(int i=0; i<=n; i++){
            t[i][0]=true;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }

                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};
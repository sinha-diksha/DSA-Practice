class Solution {
public:
    int lis(vector<int>& nums, int n, int next, vector<vector<int>>& t){
        if(n==0 || next==0) return 0;
        if(t[n][next]!=-1) return t[n][next];
        if(next>nums.size() || nums[n-1]<nums[next-1]){
            return t[n][next] = max(1+lis(nums,n-1,n,t),lis(nums,n-1,next,t));
        }else{
            return t[n][next] = lis(nums,n-1,next,t);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int next=n+1;
        vector<vector<int>> t(n+1, vector<int>(next+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=next; j++){
                if(j>n || nums[i-1]<nums[j-1]){
                    t[i][j]=max(1+t[i-1][i], t[i-1][j]);
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][next];
    }
};
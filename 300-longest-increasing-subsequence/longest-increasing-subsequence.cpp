class Solution {
public:
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
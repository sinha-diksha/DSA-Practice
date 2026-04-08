class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long ans=0;
        int n=queries.size();
        int m=nums.size();
        int mod=(1e9+7);
        for(int i=0; i<n; i++){
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];
            int idx=queries[i][0];
            while(idx<=r){
                nums[idx]=((long)nums[idx] * v)%mod;;
                idx+=k;
            }
        }


        for(int i=0; i<m; i++){
            ans^=nums[i];
        }
        return ans;
    }
};
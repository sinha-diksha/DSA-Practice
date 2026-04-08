class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long ans=0;
        int n=queries.size();
        int m=nums.size();
        int mod=(1e9+7);
        for(int i=0; i<n; i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];
            int idx=l;
            while(idx<=r){
               
                long  c=((long)nums[idx] * v)%mod;
                nums[idx]=c;
                idx+=k;
            }
        }


        for(int i=0; i<m; i++){
            ans^=nums[i];
        }
        return ans;
    }
};
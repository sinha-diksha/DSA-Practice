class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=0;
        int n=queries.size();
        int m=nums.size();
        for(int i=0; i<n; i++){
            int k=queries[i][2];
            int v=queries[i][3];
            int idx=queries[i][0];
            while(idx<=queries[i][1]){
                nums[idx]=((long)nums[idx] * v)%((long)1e9+7);
                idx+=k;
            }
        }


        for(int i=0; i<m; i++){
            ans^=nums[i];
        }
        return ans;
    }
};
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=0;
        int n=queries.size();
        int m=nums.size();
        for(int i=0; i<n; i++){
            int idx=queries[i][0];
            while(idx<=queries[i][1]){
                nums[idx]=((long)nums[idx] * queries[i][3])%((long)1e9+7);
                idx+=queries[i][2];
            }
        }


        for(int i=0; i<m; i++){
            ans^=nums[i];
        }
        return ans;
    }
};
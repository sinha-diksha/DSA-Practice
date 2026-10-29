class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int prefSum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        int ans=0;
        for(int i=0; i<n; i++){
            prefSum+=nums[i];
            int find = prefSum - k;

            ans+=mp[find];
            mp[prefSum]++;
        }

        return ans;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int prefSum=0;
        int ans=0;
        for(auto it:nums){
            prefSum+=it;
            int find = prefSum - k;
            ans += mp[find];
            mp[prefSum]++;
        }
        return ans;
    }
};
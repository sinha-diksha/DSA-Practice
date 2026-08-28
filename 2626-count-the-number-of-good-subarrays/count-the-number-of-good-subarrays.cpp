class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        int l=0;
        int r=0;
        unordered_map<int,int> mp;
        long long countPair=0;
        while(r<n){
            countPair += mp[nums[r]];
            mp[nums[r]]++;
            while(countPair>=k){
                ans+=(n-r);
                countPair-=(mp[nums[l]]-1);
                mp[nums[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
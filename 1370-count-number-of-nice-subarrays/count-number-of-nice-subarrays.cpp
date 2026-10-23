class Solution {
public:

    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            nums[i]=nums[i]%2;
        }

        int ans=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        int prefSum=0;
        for(auto it:nums){
            prefSum+=it;
            int find=prefSum-k;
            ans+=mp[find];
            mp[prefSum]++;
        }

        return ans;
    }
};
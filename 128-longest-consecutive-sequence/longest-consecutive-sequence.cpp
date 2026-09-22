class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]=1;
        }
        int ans=0;
        for(auto it:mp){
            int val = it.first;
            int count=1;
            int value = val+1;
            while(mp.count(value)>0){
                count+=mp[value];
                mp.erase(value);
                value++;
            }
            mp[val]=count;
            ans=max(ans, count);
        }
        return ans;
    }
};
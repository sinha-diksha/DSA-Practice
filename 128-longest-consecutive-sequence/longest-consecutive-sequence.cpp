class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]=1;
        }
        int ans=0;
        for(auto it:mp){
            if(mp.count(it.first - 1)>0){
                continue;
            }
            int val = it.first;
            int count=1;
            while(mp.count(val+1)>0){
                count++;
                val++;
            }
            ans=max(ans, count);
        }
        return ans;
    }
};
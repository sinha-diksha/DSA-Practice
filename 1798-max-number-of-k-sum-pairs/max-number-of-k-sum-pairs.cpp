class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto it:nums){
        
            int target= k-it;
            if(mp[target]>0){
                ans++;
                mp[target]--;
            }else{
                mp[it]++;
            }
        }
        return ans;
    }
};
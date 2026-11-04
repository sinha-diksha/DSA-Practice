class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int sum=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            sum+=(nums[i]==0?-1:1);
            int find = sum;
            if(mp.count(sum)){
                ans=max(ans, i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
        return ans;
    }
};
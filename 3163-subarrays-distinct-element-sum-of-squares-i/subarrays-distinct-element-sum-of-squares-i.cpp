class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            unordered_map<int,int> mp;
            for(int j=i; j<n; j++){
                mp[nums[j]]++;
                int size = mp.size();
                ans+=(size*size);
            }
        }

        return ans;
    }
};
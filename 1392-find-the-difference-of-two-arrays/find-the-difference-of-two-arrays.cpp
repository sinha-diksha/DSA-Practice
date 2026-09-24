class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for(auto it:nums1){
            mp[it]=1;
        }

        unordered_map<int,int> mp2;
        for(auto it:nums2){
            mp2[it]=1;
        }

        vector<int> v1;
        vector<int> v2;

        for(auto it:mp){
            if(mp2.count(it.first)==0){
                v1.push_back(it.first);
            }
        }

        for(auto it:mp2){
            if(mp.count(it.first)==0){
                v2.push_back(it.first);
            }
        }
    
        return {v1, v2};
    
    }
};
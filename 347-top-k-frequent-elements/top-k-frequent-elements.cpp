class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, unordered_map<int,int>> mp;
        int count=0;
        unordered_map<int,int> mp2;
        for(auto it:nums){
            mp2[it]++;
            int val = mp2[it];
            count=max(count, val);
            if(val>1){
                mp[val-1].erase(it);
                mp[val][it]=1;
            }else{
                mp[1][it]=1;
            }
        }

        vector<int> v;
        while(count>0 && k){
            for(auto it:mp[count]){
                if(k>0) v.push_back(it.first);
                k--;
                if(k<1) break;
            }
            count--;
        }
        return v;
    }
};
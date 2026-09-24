class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:t){
            mp[it]--;
            if(mp[it]==0){
                mp.erase(it);
            }
        }

        return mp.size()==0;
    }
};
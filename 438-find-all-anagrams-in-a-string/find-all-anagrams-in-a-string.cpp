class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> mp;
        for(auto it:p){
            mp[it]++;
        }
        int k=p.length();
        for(int i=0; i<s.length(); i++){
            mp[s[i]]--;
            if(mp[s[i]]==0) mp.erase(s[i]);
            if(i>=k){
                mp[s[i-k]]++;
                if(mp[s[i-k]]==0) mp.erase(s[i-k]);
            }
            if(i>=k-1){
                if(mp.size()==0){
                    ans.push_back(i-k+1);
                }
            }
        }

        return ans;
    }
};
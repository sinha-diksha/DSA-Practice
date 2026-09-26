class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it:arr){
            if(mp.count(it*2)) return true;
            if(it%2==0 && mp.count(it/2)) return true;
            mp[it]++;
        }
        return false;
    }
};
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it: arr){
            mp[it]++;
        }
        for(auto it:mp){
            int val=it.first;
            if(val==0 && mp[val]>1) return true;
            if(val!=0 && mp.count(2*val)){
                return true;
            }
        }
        return false;
    }
};
// TC: O(2n)
//SC: O(N)
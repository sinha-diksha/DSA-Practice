class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans=0;
        for(auto& it:mp){
            int val =it.first;
            int times= it.second;
            int target = k - val;
            if(mp.count(target)){
                if(val!=target){
                    int v=min(times, mp[target]);
                    it.second-=v;
                    mp[target]-=v;
                    ans+=v;
                }else{
                    int v=mp[target]/2;
                    ans+=v;
                    mp[target]-=(v*2);
                }

            }
            cout<<val<<" "<<ans<<endl;
        }


        return ans;
    }
};
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
       
        int ans=0;
        for(auto& it:nums){
            mp[it]++;
            int val =it;
            int times= mp[it];
            int target = k - val;
            if(mp.count(target)){
                if(val!=target){
                    int v=min(times, mp[target]);
                    mp[it]-=v;
                    mp[target]-=v;
                    ans+=v;
                }else{
                    int v=mp[target]/2;
                    ans+=v;
                    mp[target]-=(2*v);
                }
            }

            cout<<val<<" "<<ans<<endl;
        }


        return ans;
    }
};
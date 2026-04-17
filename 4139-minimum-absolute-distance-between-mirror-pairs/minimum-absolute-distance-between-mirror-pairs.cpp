class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans=INT_MAX;
        unordered_map<int, vector<int>> mp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }

        for(int i=0; i<n; i++){
            int rev=0;
            int n=nums[i];
            while(n>0){
                int d=n%10;
                n=n/10;
                rev=rev*10+d;
            }

            if(mp.count(rev)>0){
                int m=mp[rev].size();
                int lower_bound=upper_bound(mp[rev].begin(), mp[rev].end(), i)-mp[rev].begin();
                if(lower_bound<m){
                    ans=min(ans, abs(i-mp[rev][lower_bound]));
                }
            }
        }


        return ans==INT_MAX?-1:ans;
    }
};
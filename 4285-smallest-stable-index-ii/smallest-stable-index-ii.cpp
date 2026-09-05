class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        vector<int> mini(n, INT_MAX);
        mini[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            mini[i]=min(mini[i+1], nums[i]);
        }
        int ans=INT_MAX;
        int index=INT_MAX;

        for(int i=0; i<n; i++){
            maxi=max(maxi, nums[i]);
            int val=maxi-mini[i];
            if(val<=k){
                index=min(index, i);
            }
        }

        return index==INT_MAX?-1:index;
    }
};
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>> v;
        for(auto it: nums){
            int sum=0;
            int x=it;
            while(x>0){
                int d=x%10;
                x/=10;
                sum+=d;
            }
            v.push_back({sum, it});
        }
            sort(v.begin(), v.end());
            int swaps=0;
            unordered_map<int,int> mp;
            int i=0;
            for(auto it:nums){
                mp[it]=i;
                i++;
            }

            int n=nums.size();
            for(int i=0; i<n; i++){
                if(v[i].second != nums[i]){
                    swaps++;
                    int swapNumber=nums[i];
                    int swapPos=mp[nums[i]];
                    int secondSwapNumber=v[i].second;
                    int secondSwapPos=mp[v[i].second];
                    swap(nums[i], nums[secondSwapPos]);
                    mp[secondSwapNumber]=swapPos;
                    mp[swapNumber]=secondSwapPos;
                    
                }
            }

            return swaps;
        
    }
};
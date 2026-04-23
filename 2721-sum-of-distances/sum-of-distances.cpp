class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        
        int n=nums.size();
        vector<long long> ans(n);
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        unordered_map<int,vector<long long>> prefSum;
        for(auto it:mp){
            vector<int> second=it.second;
            long long sum=0;
            int size=second.size();
            vector<long long> prefixSum(size);
            prefixSum[0]=second[0];
            for(int i=1; i<size; i++){
                prefixSum[i]=prefixSum[i-1]+second[i];
            }
            prefSum[it.first]=prefixSum;
        }
        for(int i=0; i<n; i++){
            int vecSize=mp[nums[i]].size();
            if(vecSize==1){
                ans[i]=0;
            }else{
                int index=lower_bound(mp[nums[i]].begin(), mp[nums[i]].end(), i)-mp[nums[i]].begin();
                int leftLen=index;
                
                long long leftSum= leftLen >0?prefSum[nums[i]][leftLen-1]:0;
                long long rightSum=prefSum[nums[i]][vecSize-1]-leftSum-i;
                long long val=(((long long)i*leftLen)-leftSum) + (rightSum - ((vecSize-leftLen-1) * (long long)i));
                ans[i]=val;
            }
        }

        return ans;
    }
};
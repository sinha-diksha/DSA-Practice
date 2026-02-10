class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            unordered_map<int,int> mp;
            int evenCount=0;
            int oddCount=0;
            for(int j=i; j<n; j++){
                if(mp.count(nums[j])==0){
                    if(nums[j]%2==0){
                        evenCount++;
                    }else{
                        oddCount++;
                    }
                }
                mp[nums[j]]++;
                if(evenCount==oddCount){
                    ans=max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};
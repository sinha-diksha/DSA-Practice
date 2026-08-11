class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int maxLen=0;
        int count=0;
        int startIndex=0;
        int endIndex=0;
        while(r<=n){
            if(r==n){
                int val=r-l;
                if(maxLen<val){
                        maxLen=val;
                        startIndex=l;
                        endIndex=r-1;
                    }
                    l=r;
                break;
            }
            else if(l==r){
                r++;
            }else{
                if(nums[r]==nums[r-1]+1){
                    r++;
                }else{
                    int val=r-l;
                    if(maxLen<val){
                        maxLen=val;
                        startIndex=l;
                        endIndex=r-1;
                    }
                    l=r;
                    break;
                }
            }
        }
        int sum=0;
        for(int i=startIndex; i<=endIndex; i++){
            sum+=nums[i];
        }
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int i=sum;
        while(true){
            if(mp.count(i)==0){
                return i;
            }
            i++;
        }
        return maxLen;            
    }
};
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xorVal=0;
        int zeroCount=0;
        for(auto it:nums){
            xorVal^=it;
            if(it==0) zeroCount++;
        }
        if(xorVal>0) return n;
        if(zeroCount==n) return 0;
        return n-1;
    }
};
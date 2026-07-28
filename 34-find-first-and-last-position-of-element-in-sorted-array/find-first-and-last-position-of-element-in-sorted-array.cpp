class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowerBound= lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int n=nums.size();
        if(lowerBound>=n || nums[lowerBound]!=target){
            return {-1,-1};
        }
        int upperBound = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        return {lowerBound, upperBound-1};
    }
};
class Solution {
public:
    int solve(vector<int>& nums, int n, int low, int high, int target){
        if(low>high){
            return -1;
        }
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(target > nums[mid]){
            return solve(nums, n, mid+1, high, target);
        }
        return solve(nums, n, low, mid-1, target);
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums,n,0,n-1, target);
    }
};
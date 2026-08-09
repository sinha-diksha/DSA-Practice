class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n=nums.size();
        int l=1;
        int h=n-2;
        while(l<h){
            int mid = l + (h-l)/2;
            if(nums[mid]<nums[mid+1]){
                l=mid+1;
            }else{
                h=mid;
            }
        }
        return l;
    }
};
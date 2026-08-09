/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int l=0;
        int h=n-1;
        while(l<h){
            int mid = l + (h-l)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
            }else{
                h=mid;
            }
        }
        cout<<l<<endl;
        int l1=0;
        int h1=l;
        int ans1=INT_MAX;

        while(l1<=h1){
            int mid = l1 + (h1 - l1)/2;
            if(mountainArr.get(mid)>=target){
                ans1=mid;
                h1=mid-1;
            }else{
                l1=mid+1;
            }
        }

        int l2=n-1;
        int h2=l+1;
        int ans2=INT_MAX;
        while(h2<=l2){
            int mid = h2 + (l2 - h2)/2;
            if(mountainArr.get(mid)>=target){
                ans2=mid;
                h2=mid+1;
            }else{
                l2=mid-1;
            }
        }

        ans1 = ans1 == INT_MAX || mountainArr.get(ans1)!=target ? INT_MAX: ans1;
        ans2 = ans2 == INT_MAX || mountainArr.get(ans2)!=target ? INT_MAX: ans2;
        int ans3 = mountainArr.get(l)==target ? l : INT_MAX;
        if(ans1 ==INT_MAX && ans3 ==INT_MAX && ans2==INT_MAX){
            return -1;
        }
        

        return min(ans1, min(ans2, ans3));

    }
};
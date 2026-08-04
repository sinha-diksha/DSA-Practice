class Solution {
public:
    bool isPossible(int mid, vector<int>& weights, int days){
        int count=1;
        int sum=0;
        for(int i=0; i<weights.size(); i++){
            if(sum + weights[i] <=mid)sum+=weights[i];
            else{
                count++;
                sum=weights[i];
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans=high;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, weights, days)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
    }
};
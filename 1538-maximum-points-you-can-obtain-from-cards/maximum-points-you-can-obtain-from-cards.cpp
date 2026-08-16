class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0; i<k; i++){
            sum+=cardPoints[i];
        }
        int ans=sum;
        int n=cardPoints.size();
        if(k==n){
            return ans;
        }
        int r=n-1;
        int l=k-1;
        while(l>=0){
            sum-=cardPoints[l];
            sum+=cardPoints[r];
            ans=max(ans, sum);
            l--;
            r--;
        }
        return ans;
    }
};
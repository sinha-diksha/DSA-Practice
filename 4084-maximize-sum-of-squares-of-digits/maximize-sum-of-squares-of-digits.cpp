class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        int count=0;
        for(int i=0; i<num; i++){
            for(int j=9; j>=0; j--){
                if(sum>=j){
                    sum-=j;
                    ans+=to_string(j);
                    count++;
                    break;
                }
            }
        }
        if(count==num && sum!=0) return "";
        return ans;
    }
};
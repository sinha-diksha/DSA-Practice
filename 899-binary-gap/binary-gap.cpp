class Solution {
public:
    int binaryGap(int n) {
        int firstBit=-1;
        int ans=0;
        int secondBit=-1;
        for(int i=31; i>=0; i--){
            if((n & (1<<i))!=0){
                if(firstBit==-1){
                    firstBit=i;
                }else{
                    secondBit=i;
                    ans=max(ans, firstBit-secondBit);
                    firstBit=secondBit;
                }
            }
        }
        if(firstBit==-1 || secondBit==-1){
            return 0;
        }
        return ans;
    }
};
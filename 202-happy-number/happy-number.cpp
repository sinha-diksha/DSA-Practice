class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>mp;
        while(n!=1){
            if(mp.count(n)>0){
                return false;
            }
            mp[n]=1;
            int x=n;
            int sum=0;
            while(x>0){
                int d = x%10;
                sum+=(d*d);
                x/=10;
            }
            n=sum;
        }
        return true;
    }
};
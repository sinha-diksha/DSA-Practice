class Solution {
public:
    typedef long long ll;
    long long isLeftPossible(ll mid, vector<int>& coins, int k){
        ll count=0;
        int n = coins.size();
        for(int expression=1;expression<=(1<<n)-1; expression++){
            ll order=0;
            ll lcm=0;
            for(int i=0; i<n; i++){
                // is bit set
                if(expression & (1<<i)){
                    order++;

                    if(lcm==0){
                        lcm = coins[i];

                    }else{
                        lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                    }
                }
            }

            if(order%2==0){
                count -= mid/lcm;
            }else{
                count+=mid/lcm;
            }
        }

        return count;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll l=1;
        ll h=*max_element(coins.begin(), coins.end()) * (ll)k;
        ll ans=-1;
        while(l<=h){
            ll mid = l + (h-l)/2;
            if(isLeftPossible(mid, coins, k) >= k){
                ans = mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;
    }
};
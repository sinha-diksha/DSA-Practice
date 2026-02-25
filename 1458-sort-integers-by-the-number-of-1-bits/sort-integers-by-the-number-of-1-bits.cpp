class Solution {
    static bool cmp(pair<int,int>a, pair<int,int> b){
        if(a.first!=b.first) return a.first<b.first;
        return a.second<b.second;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> val(n);
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=31; j>=0; j--){
                if((arr[i] & (1<<j))!=0){count++;
                }
            }
            val[i]={count, arr[i]};
        }

        sort(val.begin(), val.end(), cmp);
        vector<int> ans;
        for(auto it:val){
            ans.push_back(it.second);
        }
        return ans;
    };
};
class Solution {
public:
    string smallestPalindrome(string s) {
       map<char,int> mp;
       for(auto it:s){
        mp[it]++;
       }
       string ans=s;
       int n=s.length();
       int l=0;
       int r=n-1;
       for(auto it:mp){
        char ch = it.first;
        int count = it.second;
        while(count>=2){
            ans[l] = ch;
            ans[r]=ch;
            l++; r--;
            count-=2;
        }

        if(count==1){
            ans[n/2]=ch;
            count-=1;
        }
       }


       return ans;
    }
};
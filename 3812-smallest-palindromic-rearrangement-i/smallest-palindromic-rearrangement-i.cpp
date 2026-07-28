class Solution {
public:
    string smallestPalindrome(string s) {
       int n = s.length();
       int l=0;
       int r=n-1;
       int mid=n/2;
       string ans=s;
       sort(s.begin(), s.end());
       int i=0;
       while(i<n){
        if(s[i]==s[i+1]){
            ans[l]=s[i];
            ans[r]=s[i];
            i+=2;
            l++;
            r--;
        }else{
            ans[mid]=s[i];
            i++;
        }
       }


       return ans;
    }
};
class Solution {
public:
    string smallestPalindrome(string s) {
       int n = s.length();
       int l=0;
       int r=n-1;
       int mid=n/2;
       string ans=s;
       vector<int> countChar(26);
       for(auto it:s){
        countChar[it-'a']++;
       }

       for(int i=0; i<26; i++){
        char ch='a'+i;
        int count=countChar[i];
        while(count>=2){
            ans[l]=ch;
            ans[r]=ch;
            l++;
            r--;
            count-=2;
        }

        if(count==1){
            ans[mid]=ch;
            count=0;
        }
       }

       return ans;
    }
};
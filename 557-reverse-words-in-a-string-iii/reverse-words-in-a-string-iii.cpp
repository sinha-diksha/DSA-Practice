class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i=0;
        int j=0;
        string ans="";
        while(j<=n){
            if(s[j]==' ' || j==n){
                reverse(s.begin()+i, s.begin()+j);
                i=j+1;
            }    
            j++;
        }
        return s;
    }
};
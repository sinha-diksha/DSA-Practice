class Solution {
public:
    int f(string s, int i){
        int skip=0;
        while(i>=0){
            if(s[i]=='#'){
                i--;
                skip++;
            }else if(skip>0){
                skip--;
                i--;
            }else{
                break;
            }
        }
        return i;
    }
    bool backspaceCompare(string s, string t) {
       int n=s.length();
       int m=t.length();
       int i=n-1;
       int j=m-1;
       while(i>=0 || j>=0){
            i = f(s, i);
            j=f(t,j);
            char val1= i >=0 ? s[i] : '$';
            char val2= j >=0 ? t[j] : '$';
            if(val1!=val2) return false;
            
            i--; j--;
       }
       return true;
    }
};
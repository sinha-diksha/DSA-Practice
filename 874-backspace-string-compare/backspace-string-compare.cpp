class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.length();
        int m=t.length();
        int sCountHash=0;
        int tCountHash=0;
        int i=n-1;
        int j=m-1;
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    sCountHash++;
                    i--;
                }else if(sCountHash>0){
                    sCountHash--;
                    i--;
                }else{
                    break;
                }
            }
            while(j>=0){
                if(t[j]=='#'){
                    tCountHash++;
                    j--;
                }else if(tCountHash>0){
                    tCountHash--;
                    j--;
                }else{
                    break;
                }
            }
            sCountHash=0;
            tCountHash=0;
            if(i<0 && j<0) return true;
            if(i<0 || j<0) return false;
            if(s[i]!=t[j]) return false;
            i--; j--;
        }
        return true;
    }
};
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n=name.length();
        int m=typed.length();
        int i=0; int j=0;
        while(i<n && j<m){
            if(name[i]==typed[j]){

                i++;
                j++;
            }else if(j>0 && typed[j]==typed[j-1]){
                j++;
            }else{
                return false;
            }
        }
        while(j<m){
            if(typed[j]!=typed[j-1]){
                return false;
            }
            j++;
        }
        if(i==n) return true;
        return false;
    }
};
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool ans=true;
        int n=s.length();
        if(n==1) return true;
        int nosegment=0;
        int l=0;
        int r=0;
        while(r<n){
            if(r==n-1 && s[r]=='1'){
                nosegment++;
                break;
            }
            if(s[r]=='1'){
                r++;
            }
            else{
                nosegment++;
                while(r<n && s[r]!='1'){
                    r++;
                }
                l=r;
            }
        }
        cout<<nosegment<<endl;
        return nosegment==1 || nosegment==0;
    }
};
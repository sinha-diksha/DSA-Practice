class Solution {
public:
    int minFlips(string s) {
        int ans=INT_MAX;
        int n=s.length();
        string s2=s+s;
        string alt1="";
        string alt2="";
        char parity='0';
        for(int i=0; i<s2.length(); i++){
            alt1+=parity;
            alt2+=(parity=='0')?'1':'0';
            parity=parity=='0'?'1':'0';
        }
        int dif1=0;
        int dif2=0;
        for(int i=0; i<n; i++){
            if(s2[i]!=alt1[i]) dif1++;
            if(s2[i]!=alt2[i]) dif2++;
        }
        ans=min(dif1, dif2);
        int v=2*n;
        for(int i=n; i<v; i++){
            int leave=i-n;
            if(s2[leave]!=alt1[leave]) dif1--;
            if(s2[leave]!=alt2[leave]) dif2--;
            if(s2[i]!=alt1[i]) dif1++;
            if(s2[i]!=alt2[i]) dif2++;
            ans=min(ans,min(dif1, dif2));
        }
        return ans;
    }
};
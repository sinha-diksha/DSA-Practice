class Solution {
public:
    int firstMinOperation(string s){
        string r=s;
        sort(r.begin(), r.end());
        if(s==r) return 0;
        int ans=0;
        int n=s.length();
        if(n==2 && s[0]!=s[1]) return -1;
        if(n==1) return 0;
        
        string s1=s.substr(1);
        sort(s.begin()+1, s.end());
        string s2=s.substr(1);
        if(s1!=s2) ans++;
        if(s[0]<=s[1]) return ans;
        string str1=s.substr(0, n-1);
        sort(s.begin(), s.end()-1);
        string str2=s.substr(0, n-1);
        if(str1!=str2) ans++;
        if(s[n-1]>=s[n-2]){
            return ans;
        }
        ans++;
        return ans;
    }

    int secondMinOperation(string s){
        string r=s;
        int n=s.length();
        sort(r.begin(), r.end());
        if(s==r) return 0;
        if(n==2 && s[0]!=s[1]) return -1;
        if(n==1) return 0;
        
        int ans=0;
        string s1=s.substr(0, n-1);
        sort(s.begin(), s.end()-1);
        string s2=s.substr(0, n-1);
        if(s1!=s2) ans++;
        if(s[n-2]<=s[n-1]) return ans;
        string str1=s.substr(1);
        sort(s.begin()+1, s.end());
        string str2=s.substr(1);
        if(str1!=str2) ans++;
        if(s[1]>=s[0]){
            return ans;
        }
        ans++;
        return ans;
    }
    int minOperations(string s) {
        int first=firstMinOperation(s);
        int second=secondMinOperation(s);
        cout<<first<<" "<<second<<endl;
        return min(first, second);
    }
};
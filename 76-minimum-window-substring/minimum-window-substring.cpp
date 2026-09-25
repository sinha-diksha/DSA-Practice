class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        for(auto it:t){
            mp[it]++;
            mp2[it]=1;
        }

        int i=0;
        int j=0;
        int minLen=INT_MAX;
        int start=-1;
        int end=-1;
        string ans="";
        int count=0;
        while(j<n){
            if(mp2.count(s[j])){
                if(mp[s[j]]>0) count++;
                mp[s[j]]--;
                
            }
            
            while(count==m){
                if(j-i+1<minLen){
                    minLen = j-i+1;
                    start = i;
                    end = j;
                }
                if(mp2.count(s[i])){
                    mp[s[i]]++;
                    if(mp[s[i]]>0) count--;
                }
                i++;
            }


            j++;
        }

        if(start!=-1) return s.substr(start, minLen);
        return "";
    }
};
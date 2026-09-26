class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.length();
        string ans="";
        unordered_map<string, string> mp;
        for(auto it: knowledge){
            // cout<<it[0]<<" "<<it[1]<<endl;
            mp[it[0]]=it[1];
            
        }
        int i=0;
        int j=0;
        while(j<n){
            if(s[i]!='(' && s[i]!=')'){
                ans+=s[i];
                i++;
                j++;
            }else{
                while(s[j]!=')'){
                    j++;
                }
                string a = s.substr(i+1, j-1-i);
                if(mp.count(a)){
                    ans+=mp[a];
                }else{
                    ans+='?';
                }
                j++;
                i=j;
            }
        }

        return ans;
    }
};
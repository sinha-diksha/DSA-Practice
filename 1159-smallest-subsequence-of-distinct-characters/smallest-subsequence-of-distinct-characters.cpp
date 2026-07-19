class Solution {
public:
    string smallestSubsequence(string s) {
        string result = "";
        int n=s.length();
        vector<int> lastIndex(26);
        for(int i=0; i<n; i++){
            lastIndex[s[i]-'a']=i;
        }

        vector<bool> target(26, false);
        for(int i=0; i<n; i++){
            char ch=s[i];
            int idx=ch-'a';
            if(target[idx]){
                continue;
            }

            while(result.length()> 0 && result.back()>ch && lastIndex[result.back()-'a']>i){
                target[result.back()-'a']=false;
                result.pop_back();
            }

            result.push_back(ch);
            target[idx]=true;
        }


        return result;
    }
};
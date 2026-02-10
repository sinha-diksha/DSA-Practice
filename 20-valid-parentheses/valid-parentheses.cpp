class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        unordered_map<char,char> mp;
        mp[']']='[';
        mp['}']='{';
        mp[')']='(';
        stack<char> st;
        for(int i=0; i<n; i++){
            if(mp.count(s[i])>0){
                if(!st.empty() && st.top()==mp[s[i]]){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};
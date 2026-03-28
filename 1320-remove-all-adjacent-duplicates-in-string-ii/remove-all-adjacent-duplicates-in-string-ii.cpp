class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        string ans="";
        for(auto ch: s){
            if(st.empty() || st.top().first!=ch){
                st.push({ch, 1});
                ans.push_back(ch);
            }else{
                if(st.top().second==k-1){
                    while(!st.empty() && st.top().first==ch){
                        st.pop();
                        ans.pop_back();
                    }
                }else{
                    st.push({ch, st.top().second+1});
                    ans.push_back(ch);
                }
            }
        }

        return ans;
    }
};
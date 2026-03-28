class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>>st;
        string ans="";
        for(auto ch: s){
            if(!st.empty() && st.back().first==ch){
                st.back().second++;
            }else{
                st.push_back({ch ,1});
            }
            if(st.back().second==k){
                st.pop_back();
            }
        }

        for(auto &p:st){
            ans.append(p.second, p.first);
        }

        return ans;
    }
};
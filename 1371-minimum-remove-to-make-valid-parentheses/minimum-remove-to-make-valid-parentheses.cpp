class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<pair<char,int>> st;
        for(int i=0; i<s.length(); i++){
            char ch=s[i];
            if(ch=='('){
                st.push_back({ch, i});
            }else if(ch==')'){
                
                if(!st.empty()&&st.back().first=='('){
                    st.pop_back();
                }else{
                    st.push_back({ch,i});                        
                }
            }
        }

        for(auto ch: st){
            cout<<ch.first<<" "<<ch.second<<endl;
        }
        string ans="";
        int j=0;
        for(int i=0; i<s.length(); i++){
            char ch=s[i];
            if(ch!='(' && ch!=')'){
                ans+=ch;
            }else if(j<st.size() && i==st[j].second){
                j++;
            }else{
                ans+=ch;
            }
        }

        return ans;
    }
};
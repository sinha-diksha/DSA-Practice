class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int n=s.length();
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(s[i]);
            }else{
                if(!st.empty()){
                    if((s[i]==')' && st.top()=='(')){
                        st.pop();
                    }else{
                        st.push(s[i]);
                    }
                }else{
                    st.push(s[i]);
                }
            }
        }

        return st.size();
    }
};
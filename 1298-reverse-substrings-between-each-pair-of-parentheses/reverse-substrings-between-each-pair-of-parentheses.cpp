class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<char> st;
        for(auto it:s){
            if(it!=')'){
                st.push(it);
            }else{
                string val="";
                while(st.top()!='('){
                    val+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto t:val){
                    st.push(t);
                }
            }
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
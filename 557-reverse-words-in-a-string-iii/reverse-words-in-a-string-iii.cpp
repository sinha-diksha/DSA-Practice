class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans="";
        int n=s.length();
        for(int i=0; i<n; i++){
            char it=s[i];
            if(it!=' '){
                st.push(it);
            }else{
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                    
                }
                ans+=" ";
            }
            if(i==n-1){
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                    
                }
            }
        }

        return ans;
    }
};
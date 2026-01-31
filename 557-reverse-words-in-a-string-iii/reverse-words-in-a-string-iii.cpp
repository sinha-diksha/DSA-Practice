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
            }
            if(it==' ' || i==n-1){
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                    
                }
            }
            if(it==' '){
                ans+=it;
            }
            
        }

        return ans;
    }
};
class Solution {
public:
    string finalString(string s){
        string temp="";
        int n=s.length();
        for(int i=0; i<n; i++){
            if(s[i]!='#') temp.push_back(s[i]);
            else if(temp.size()){
                 temp.pop_back();
            }
        }
        return temp;
    }
    bool backspaceCompare(string s, string t) {
       string temp1 = finalString(s);
       string temp2 = finalString(t);
       return temp1==temp2;
    }
};
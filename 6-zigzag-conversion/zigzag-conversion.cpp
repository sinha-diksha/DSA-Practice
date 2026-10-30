class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        if(numRows==1) return s;
        vector<vector<char>> v(numRows);
        int i;
        for(i=0; i<min(n, numRows); i++){
            v[i].push_back(s[i]);
        }
        int zeroToEnd=false;
        while(i<n){
            if(!zeroToEnd){
                int j=numRows-2;
                while(i<n && j>=0){
                    v[j].push_back(s[i]);
                    i++;
                    j--;
                }
            }else{
                int j=1;
                while(i<n && j<=numRows-1){
                    v[j].push_back(s[i]);
                    i++;
                    j++;
                }
            }


            zeroToEnd=!zeroToEnd;
        }

        string ans="";
        for(auto it:v){
            for(auto q:it){
                ans+=q;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int compress(vector<char>& chars) {

        int i=0;
        int j=0;
        int n=chars.size();
        string str="";
        while(j<=n){
            if(j==n || chars[j]!=chars[i]){
                int val=j-i;
                cout<<j<<endl;
                int d=0;
                
                str+=chars[i] + ((val>1) ? to_string(val):"");
                i=j;
            
            }
            j++;
        }
        cout<<str<<endl;
        int ans=str.length();
        for(int i=0; i<ans; i++){
           chars[i]=str[i]; 
        }
        return ans;
    }
};
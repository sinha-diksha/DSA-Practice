class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n=queries.size();
        int n2=dictionary.size();
        int m=queries[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n2; j++){
                int dis=0;
                for(int k=0; k<m; k++){
                    if(queries[i][k]!=dictionary[j][k]){
                        dis++;
                    }
                }

                if(dis<=2){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
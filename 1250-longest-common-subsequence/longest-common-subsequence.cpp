class Solution {
public:
    int lcs(string text1, string text2, int n, int m, vector<vector<int>>& t){
        if(n==0 || m==0) return 0;
        if(t[n][m]!=-1) return t[n][m];
        if(text1[n-1]==text2[m-1]){
            return t[n][m]=1 + lcs(text1, text2, n-1, m-1,t);
        }
        return t[n][m]=max(lcs(text1, text2, n-1, m,t) , lcs(text1, text2, n, m-1,t));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1]==text2[j-1]){
                    t[i][j]=1 + t[i-1][j-1];
                }
                else {
                    t[i][j]= max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
};
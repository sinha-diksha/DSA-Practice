class Solution {
public:
    int func(int m, int n, vector<vector<int>>& t){
        if(m==1 && n==1) return 1;
        if(m<=0 || n<=0) return 0;
        if(t[m][n]!=-1) return t[m][n];
        int a = func(m-1, n,t);
        int b = func(m, n-1,t);

        return t[m][n]=a+b;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1, -1));
        return func(m,n,t);
    }
};
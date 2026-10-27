class Solution {
public:
    void bfs(int i, int j, int& count, vector<vector<int>>& grid, int n, int m, int k, vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        long long val=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int r=node.first;
            int c=node.second;
            val+=grid[r][c];
            for(int i=0; i<4; i++){
                int nR=r+dr[i];
                int nC=c+dc[i];
                if(nR>=0 && nR<n && nC>=0 && nC<m && grid[nR][nC]!=0 && !vis[nR][nC]){
                    q.push({nR, nC});
                    vis[nR][nC]=1;
                }
            }
        }
        if(val%k==0) count++;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]>0){
                    bfs(i,j, count, grid, n, m, k, vis);
                }
            }
        }
        return count;
    }
};
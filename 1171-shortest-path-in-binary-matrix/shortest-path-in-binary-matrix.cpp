class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0]=1;
        queue<pair<int, pair<int,int>>>q;
        if(mat[0][0]) return -1;
        q.push({1, {0,0}});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int dist=node.first;
            int r=node.second.first;
            int c=node.second.second;
            if(r==n-1 && c==n-1) return dist;
            for(int i=r-1; i<=r+1; i++){
                for(int j=c-1; j<=c+1; j++){
                    int nR=i;
                    int nC=j;
                    if(nR>=0 && nC>=0 && nR<n && nC<m && mat[nR][nC]==0 && dist+1 < dis[nR][nC]){
                        q.push({dist+1, {nR, nC}});
                        dis[nR][nC]=dist+1;
                    }
                }
                
            }
        }
        
        return -1;
    }
};
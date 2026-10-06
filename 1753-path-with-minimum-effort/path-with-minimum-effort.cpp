class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, 
        greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        pq.push({0, {0,0}});
        dis[0][0]=0;
        vector<int> dr={-1, 0, 1, 0};
        vector<int> dc={0, 1, 0, -1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int r=it.second.first;
            int c=it.second.second;
            int val=it.first;
            for(int i=0; i<4; i++){
                int nR=r+dr[i];
                int nC=c+dc[i];
                if(nR>=0 && nR<n && nC>=0 && nC<m){
                    int maxValue=max(val, abs(heights[r][c]-heights[nR][nC]));
                    if(dis[nR][nC]>maxValue){
                        dis[nR][nC]=maxValue;
                        pq.push({maxValue, {nR, nC}});
                    }
                }
            }
        }

        return dis[n-1][m-1];
    }
};
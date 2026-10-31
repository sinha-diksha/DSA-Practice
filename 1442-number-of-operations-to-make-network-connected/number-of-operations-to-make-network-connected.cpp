class Solution {
public:
    void bfs(int i, vector<vector<int>>& adjList, int n, vector<int>& vis){
        vis[i]=1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adjList[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]++;
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalComponents=0;
        vector<int> vis(n,0);
        int numEdges=connections.size();
        vector<vector<int>> adjList(n);
        for(int i=0; i<connections.size(); i++){
            int u=connections[i][0];
            int v=connections[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                bfs(i, adjList, n, vis);
                totalComponents++;
            }
        }
        if(numEdges>=n-1){
            return totalComponents-1;
        }
        return -1;
    }
};
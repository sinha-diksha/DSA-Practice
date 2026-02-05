class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adjList[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int size=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            size++;
            for(auto it:adjList[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return size==numCourses;
    }
};
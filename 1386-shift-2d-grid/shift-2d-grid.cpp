class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row=grid.size();
        int col=grid[0].size();
        int n = row * col;
        vector<int> v;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                v.push_back(grid[i][j]);            
            }
        }

        k = k%n;
        cout<<k<<endl;
        
        reverse(v.begin()+n-k, v.end());
        reverse(v.begin(), v.begin()+n-k);
        reverse(v.begin(), v.end());
        for(int i=0; i<n; i++){
            int c = i%col;
            int r = i/col;
            grid[r][c]=v[i];
        }

        return grid;
    }
};
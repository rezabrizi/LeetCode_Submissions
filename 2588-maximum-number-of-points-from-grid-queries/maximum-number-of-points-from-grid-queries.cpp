class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < queries.size(); i++){
            pq.push({queries[i], i});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> cells; 
        cells.push({grid[0][0], 0, 0});

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size())); 
        visited[0][0] = true; 
        vector<int> ans (queries.size()); 
        int curr_size = 0; 

        while (!pq.empty()){
            auto [q, qidx] = pq.top(); pq.pop(); 

            while(!cells.empty() && cells.top()[0] < q){
                vector<int> curr_cell = cells.top(); cells.pop();
                int x = curr_cell[1], y = curr_cell[2]; 
                curr_size++; 

                for (const auto& [dx, dy]: dirs){
                    int nx = dx + x, ny = dy + y; 
                    if (nx >= 0 && nx < grid.size() && ny >=0 && ny < grid[0].size() && visited[nx][ny] == false){
                        cells.push({grid[nx][ny], nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }

            ans[qidx] = curr_size;
        }   
        return ans;
    }
};
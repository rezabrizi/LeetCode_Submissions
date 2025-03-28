struct UnionFind {
    vector<int> rank, parents, size; 

    UnionFind (int n): rank(n, 0), parents(n), size(n, 1){
        for (int i = 0; i < n; i++) parents[i] = i;
    }

    int find(int i){
        if (parents[i] != i){
            parents[i] = find(parents[i]);
        }
        return parents[i]; 
    }

    bool unite(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x != parent_y){
            if (rank[parent_x] < rank[parent_y]){
                parents[parent_x] = parent_y;
                size[parent_y] += size[parent_x]; 
            }else{
                parents[parent_y] = parent_x;
                size[parent_x] += size[parent_y]; 
            }

            return false;
        }

        return true; 
    }
    
    int getSize(int x) {
        return size[find(x)];
    }
};


class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        UnionFind uf (grid.size() * grid[0].size());
        vector<pair<int, int>> queries_idx;
        for (int i = 0; i < queries.size(); i++){
            queries_idx.emplace_back(queries[i], i); 
        }

        sort(queries_idx.begin(), queries_idx.end(), [](const auto& a , const auto& b){
            return a.first < b.first; 
        }); 

        vector<vector<int>> grid_vals; 

        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                grid_vals.push_back({grid[i][j], i, j}); 
            }
        }

        sort(grid_vals.begin(), grid_vals.end());

        vector<int> ans (queries.size());
        unordered_set<int> visited; 
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int cell_idx = 0; 

        for (const auto& [q, q_idx]: queries_idx){
            while (cell_idx < grid_vals.size() && grid_vals[cell_idx][0] < q){
                vector<int> cell = grid_vals[cell_idx++]; 
                int id = cell[1] * grid[0].size() + cell[2]; 
                visited.insert(id);

                for (const auto& [dx, dy]: dirs){
                    int nx = cell[1] + dx; 
                    int ny = cell[2] + dy; 
                    int nid = nx * grid[0].size() + ny;
                    if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && visited.find(nid) != visited.end()){
                        uf.unite(id, nid); 
                    }
                }
            }
            ans[q_idx] =  (visited.count(0)) ? uf.getSize(0) : 0; 
        }
        return ans;
    }


};
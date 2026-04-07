#include "../../include/algorithms/BFS.h"
#include <queue>     
#include <map>      
#include <algorithm> 


BFS::BFS(int r, int c) {
    this->rows = r;
    this->cols = c;
}


std::vector<std::pair<int, int>> BFS::solve(
    const std::vector<std::vector<int>>& grid,
    std::pair<int,int> start,
    std::pair<int, int> target) {
        

    std::vector<std::pair<int, int>> final_path;

    if (start.first < 0 || start.first >= rows || 
        start.second < 0 || start.second >= cols || 
        grid[start.first][start.second] == -1) {
        return final_path; 
    }
    std::queue<std::pair<int,int>>q;
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::map<std::pair<int, int>, std::pair<int, int>> parent;

    q.push(start);
    visited[start.first][start.second] = true;

    int dr[] = {-1, 1, 0, 0}; 
    int dc[] = {0, 0, -1, 1};
    bool found = false;


    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (curr == target){
            found = true;
            break;
        }
        for(int i = 0; i < 4; i++) {
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && 
                grid[nr][nc] != -1 && !visited[nr][nc]) {
                
                visited[nr][nc] = true;
                parent[{nr, nc}] = curr; 
                q.push({nr, nc});
            }
        }


    }


    if (found) {
        auto curr = target;
        while (curr != start) {
            final_path.push_back(curr);
            curr = parent[curr];
        }
        final_path.push_back(start);
        std::reverse(final_path.begin(), final_path.end());
    }

    return final_path;
}



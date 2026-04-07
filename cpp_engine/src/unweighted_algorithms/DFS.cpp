#include "../../include/unweighted_algorithms/DFS.h"

DFS::DFS(int r, int c) {
    this->rows = r;
    this->cols = c;
}

bool DFS::find_path(int r, int c, std::pair<int,int> target,
                    const std::vector<std::vector<int>>& grid,
                    std::vector<std::vector<bool>>& visited,
                    std::vector<std::pair<int,int>>& path) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) return false;

    if ((grid[r][c] != -1) && !visited[r][c])
    {
        path.push_back({r,c});
        visited[r][c] = true;

        if (r == target.first && c == target.second) return true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            if (find_path(r+dr[i], c+dc[i], target, grid, visited, path))
            {
                return true;
            }
        }

        path.pop_back();
    }

    return false;
}

std::vector<std::pair<int,int>> DFS::solve(
    const std::vector<std::vector<int>>& grid,
    std::pair<int,int> start,
    std::pair<int,int> target)
{
    std::vector<std::pair<int,int>> path;
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    if (find_path(start.first, start.second, target, grid, visited, path))
    {
       return path;
    }

    return { start };
}
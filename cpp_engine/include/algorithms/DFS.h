#pragma once
#include <vector>
#include <utility>
#include "../PathSolver.h" 


class DFS : public PathSolver{
public:
    DFS(int r, int c);

    std::vector<std::pair<int,int>> solve(
        const std::vector<std::vector<int>>& grid,
        std::pair<int,int> start,
        std::pair<int,int> target
    ) override;


private:
    int rows, cols;

    bool find_path(
            int r, int c, 
            std::pair<int,int> target,
            const std::vector<std::vector<int>>& grid,
            std::vector<std::vector<bool>>& visited,
            std::vector<std::pair<int,int>>& path
        );
};
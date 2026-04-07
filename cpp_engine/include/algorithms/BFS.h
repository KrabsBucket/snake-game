#pragma once
#include <utility>
#include <vector>
#include "../PathSolver.h"

class BFS : public PathSolver{
public:
    BFS(int r, int c);


    std::vector<std::pair<int, int>> solve (
        const std::vector<std::vector<int>>& grid,
        std::pair<int,int> start,
        std::pair<int, int> target
    ) override;



private:
    int rows, cols;

    
};
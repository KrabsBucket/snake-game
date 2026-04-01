#pragma once
#include <vector>
#include <utility>

class PathSolver {
public:
    virtual std::vector<std::pair<int,int>> solve(
        const std::vector<std::vector<int>>& grid,
        std::pair<int,int> start,
        std::pair<int,int> target
    ) = 0;

    virtual ~PathSolver() = default;
};
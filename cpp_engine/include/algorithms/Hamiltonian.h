#pragma once
#include <vector>
#include <utility>
#include "../PathSolver.h" 

class Hamiltonian : public PathSolver {
public:
    Hamiltonian(int r, int c); 
    
    std::vector<std::pair<int,int>> solve(
        const std::vector<std::vector<int>>& grid,
        std::pair<int,int> start,
        std::pair<int,int> target
    ) override;

private:
    void generate(int r, int c);
    int rows, cols;
    std::vector<std::pair<int,int>> cycle;
};
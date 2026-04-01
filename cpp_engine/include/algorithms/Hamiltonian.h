#pragma once
#include <vector>
#include <utility>

class Hamiltonian {
public:
    void generate(int rows, int cols);
    std::pair<int,int> next(int r, int c);

private:
    int rows, cols;
    std::vector<std::pair<int,int>> cycle;
};
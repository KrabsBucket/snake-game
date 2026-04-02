#pragma once
#include <vector>
#include "Snake.h"

class Grid{
public:
    Grid(int r, int c);
    void bake(const Snake& snake);
    const std::vector<std::vector<int>>& get_data() const;

private:
    int rows, cols;
    std::vector<std::vector<int>> data;
};
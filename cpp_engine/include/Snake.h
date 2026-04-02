#pragma once
#include <vector>
#include <utility>


class Snake{
public:
    Snake(int start_r, int start_c);
    void move(int dr, int dc, bool grow);
    bool check_collision(int rows, int cols);

    std::vector<std::pair<int, int>> body;

};
#pragma once
#include <vector>
#include <utility>


class Game {
public:
    Game(int rows, int cols);
    void render();
    void move(char input);
    void step();

private:
    int rows;
    int cols;
    int dir_r;
    int dir_c;
    std::vector <std::pair<int,int>> snake ;
    int food_r;
    int food_c;
    std::vector<std::vector<int>> grid;
};
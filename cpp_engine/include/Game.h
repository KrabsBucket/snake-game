#pragma once
#include <vector>
#include <memory>
#include <utility>
#include "PathSolver.h"
#include "Grid.h"
#include "Snake.h"

class Game {
public:
    Game(int rows, int cols, std::shared_ptr<PathSolver> solver);

    void render();
    void move(char input);
    void solver_move();
    void step();


private:
    int rows;
    int cols;

    int dir_r;
    int dir_c;

    int food_r;
    int food_c;

    std::shared_ptr<PathSolver> path_solver;

    Snake snake;
    Grid grid_obj;
};
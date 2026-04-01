#pragma once
#include <vector>
#include <memory>
#include <utility>
#include "PathSolver.h"

class Game {
public:
    Game(int rows, int cols, std::shared_ptr<PathSolver> solver);
    void render();
    void move(char input);
    void hamiltonian_move();   
    void step();
    void toggle_pathsolver();
    bool is_solver_active();
    bool is_hamiltonian();

private:
    int rows;
    int cols;
    int dir_r;
    int dir_c;
    std::vector<std::pair<int,int>> snake;
    int food_r;
    int food_c;
    std::shared_ptr<PathSolver> path_solver;
    std::vector<std::vector<int>> grid;
    bool solver_active;
};
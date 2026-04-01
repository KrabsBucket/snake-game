#pragma once
#include <vector>
#include <utility>
#include "algorithms/Hamiltonian.h"

class Game {
public:
    Game(int rows, int cols, bool use_ham);
    void render();
    void move(char input);
    void hamiltonian_move();   
    void step();
    bool is_hamiltonian();     

private:
    int rows;
    int cols;
    int dir_r;
    int dir_c;
    std::vector <std::pair<int,int>> snake ;
    int food_r;
    int food_c;
    Hamiltonian hamiltonian;
    std::vector<std::vector<int>> grid;
    bool hamiltonian_enabled;  
};
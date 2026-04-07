#include "../include/Game.h"
#include "../include/algorithms/Hamiltonian.h"
#include "../include/algorithms/DFS.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <memory>

int main()
{
    std::cout << "\x1B[?25l";
    


    enum Mode {
        MANUAL,
        HAMILTONIAN_MODE,
        DFS_MODE
    };
    const int ROWS = 10;
    const int COLS = 10;
    const int speed = 150;
    Mode mode = DFS_MODE;   

    std::shared_ptr<PathSolver> solver = nullptr;

    if (mode == HAMILTONIAN_MODE)
        solver = std::make_shared<Hamiltonian>(ROWS,COLS);
    else if (mode == DFS_MODE)
        solver = std::make_shared<DFS>(ROWS, COLS);

    Game game(ROWS, COLS, solver);

    while(true)
    {
        if (_kbhit())
        {
            char ch = _getch();

            if (solver == nullptr)
            {
                game.move(ch);
            }
        }

        if (solver != nullptr)
        {
            game.solver_move(); 
        }

        game.step();

        std::cout << "\x1B[H\x1B[J";
        game.render();

        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }

    std::cout << "\x1B[?25h";
    return 0;
}
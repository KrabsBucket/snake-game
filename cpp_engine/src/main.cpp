#include "../include/Game.h"
#include "../include/algorithms/Hamiltonian.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <memory>

int main()
{
    std::cout << "\x1B[?25l"; 

    bool USE_HAMILTONIAN = true; 

    std::shared_ptr<PathSolver> solver = nullptr;
    if (USE_HAMILTONIAN)
    {
        solver = std::make_shared<Hamiltonian>(10, 10);
    }

    Game game(10, 10, solver);

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
            game.hamiltonian_move();
        }

        game.step();
        std::cout << "\x1B[H\x1B[J";
        game.render();   
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    std::cout << "\x1B[?25h";
    return 0;
}
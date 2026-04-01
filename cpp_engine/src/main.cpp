#include "../include/Game.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cctype>
#include <conio.h>

int main()
{
    std::cout << "\x1B[?25l"; // hide cursor
    bool Run_Hamiltonian = true;
    Game game(10, 10, Run_Hamiltonian);


    while(true)
    {
        char ch;
        if (_kbhit())
        {
            char ch = _getch();
            
            if(!game.is_hamiltonian())
            {
                game.move(ch);
            }
        }


        if (game.is_hamiltonian())
        {
            game.hamiltonian_move();
        }
        game.step();
        std::cout << "\x1B[H\x1B[J";
        game.render() ;   
        std::this_thread::sleep_for(std::chrono::milliseconds(1));


    }
    std::cout << "\x1B[?25h";

}

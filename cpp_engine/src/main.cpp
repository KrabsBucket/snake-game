#include "../include/Game.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cctype>
#include <conio.h>

int main()
{


    Game game(20, 20);
    game.render();

    while(true)
    {
        char ch;
        if (_kbhit())
        {
            char ch = _getch();
            game.move(ch);
        }
        game.step();
        std::cout << "\x1B[2J\x1B[H";
        game.render() ;   
        std::this_thread::sleep_for(std::chrono::milliseconds(150));


    }

}

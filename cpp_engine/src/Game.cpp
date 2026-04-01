#include "../include/Game.h"
#include <iostream>
#include <cstdlib>
#include <thread>



Game::Game(int rows, int cols, std::shared_ptr<PathSolver> solver)
{
    this->rows = rows;
    this->cols = cols;
    this->path_solver = solver;
    this->solver_active = true;
    snake =  {{rows/2, cols/2}};
    food_r = rand()%rows;
    food_c = rand()%cols;
    dir_r = 0;
    dir_c = 1;

    grid.resize(rows, std::vector<int>(cols, 0));

}

void Game::toggle_pathsolver() { solver_active = !solver_active; }
bool Game::is_solver_active() { return solver_active && path_solver != nullptr; }

bool Game::is_hamiltonian() {
    return path_solver != nullptr; 
}

void Game::hamiltonian_move()
{
    if (path_solver == nullptr) 
    {
        return;
    }

    int current_r = snake[0].first;
    int current_c = snake[0].second;

    std::vector<std::pair<int, int>> path = path_solver->solve(grid, {current_r, current_c}, {food_r, food_c});

    if (!path.empty())
    {
        dir_r = path[0].first - current_r;
        dir_c = path[0].second - current_c;
    }
}


void Game::render()
{


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            bool flag = false;
            if (i == snake[0].first && j == snake[0].second)
                    {
                        std::cout << "H ";
                        flag = true;
                    }
            else if (i == snake.back().first && j == snake.back().second && snake.size()>1)
                    {   std::cout << "T ";
                        flag = true;

                    }

            else 
            {
                for (int k = 1; k < snake.size()-1 ; k++)
                {    

                    if ( i == snake[k].first && j == snake[k].second)
                    {   
                        std::cout << "B "; 
                        flag = true; 
                        break; 
                    }
                        
                }
            }
            if (!flag)
            {    if ( i == food_r && j == food_c)
                    std::cout << "F ";
                        
                else
                    std::cout << ". ";}
           
            }
        std::cout << "\n";
    }
}







void Game::step()
{
    snake.insert(snake.begin(), {snake[0].first + dir_r, snake[0].second +dir_c});

    
    bool gameover = false;
    
    if (snake[0].first  < 0 || snake[0].first  >= rows || snake[0].second < 0 || snake[0].second >= cols)
        gameover = true;

    for (int i = 1; i < snake.size(); i++)
    {
        if (snake[i].first == snake[0].first && snake[i].second == snake[0].second)
            gameover = true;

    }

    if (gameover)
        {
            std::cout << "GAME OVER\n";
            exit(0);
        }

    
    if (snake[0].first == food_r && snake[0].second == food_c)
        {
            food_r = rand() % rows;
            food_c = rand() % cols;
        }

    else
        {
            snake.pop_back();
        }


}



void Game::move(char input)
{


    


    input = std::tolower(input);
    if (input == 'w' && dir_r != 1)
        {
            dir_r = -1;
            dir_c = 0;
        }
    else if ( input == 's' && dir_r != -1 )
        {
            dir_r = 1;
            dir_c = 0;
        }

    else if ( input == 'a' && dir_c != 1 )
        {
            dir_r = 0;
            dir_c = -1;
        }


    else if ( input == 'd' && dir_c != -1 )
        {
            dir_r = 0;
            dir_c = 1;
        }

   
        


}
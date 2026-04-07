#include "../include/Game.h"
#include <iostream>
#include <cstdlib>
#include <thread>

Game::Game(int rows, int cols, std::shared_ptr<PathSolver> solver)
    : rows(rows),
      cols(cols),
      path_solver(solver),
      snake(rows/2, cols/2),
      grid_obj(rows, cols)
{
    food_r = rand() % rows;
    food_c = rand() % cols;

    dir_r = 0;
    dir_c = 1;
}

void Game::solver_move()
{
    if (!path_solver) return;

    static std::vector<std::pair<int, int>> saved_path;
    static std::pair<int, int> last_target = {-1, -1};

    auto head = snake.body[0];
    std::pair<int, int> current_target = {food_r, food_c};


    if (saved_path.empty() || last_target != current_target)
    {
        grid_obj.bake(snake);
        saved_path = path_solver->solve(grid_obj.get_data(), head, current_target);
        last_target = current_target;

        
        if (!saved_path.empty() && saved_path.front() == head) {
            saved_path.erase(saved_path.begin());
        }
    }

    if (!saved_path.empty())
    {
        auto next_step = saved_path.front(); 
        saved_path.erase(saved_path.begin()); 

        dir_r = next_step.first - head.first;
        dir_c = next_step.second - head.second;
    }
}

void Game::render()
{
    const auto& body = snake.body;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            bool flag = false;

            if (i == body[0].first && j == body[0].second)
            {
                std::cout << "H ";
                flag = true;
            }
            else if (body.size() > 1 &&
                     i == body.back().first &&
                     j == body.back().second)
            {
                std::cout << "T ";
                flag = true;
            }
            else
            {
                for (size_t k = 1; k < body.size() - 1; k++)
                {
                    if (i == body[k].first && j == body[k].second)
                    {
                        std::cout << "B ";
                        flag = true;
                        break;
                    }
                }
            }

            if (!flag)
            {
                if (i == food_r && j == food_c)
                    std::cout << "F ";
                else
                    std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
}

void Game::step()
{
    auto head = snake.body[0];
    int new_r = head.first + dir_r;
    int new_c = head.second + dir_c;

    bool grow = (new_r == food_r && new_c == food_c);

    snake.move(dir_r, dir_c, grow);

    head = snake.body[0];

    bool gameover = false;

    if (head.first < 0 || head.first >= rows ||
        head.second < 0 || head.second >= cols)
        gameover = true;

    for (size_t i = 1; i < snake.body.size(); i++)
    {
        if (snake.body[i] == head)
            gameover = true;
    }

    if (gameover)
    {
        std::cout << "GAME OVER\n";
        exit(0);
    }

    if (grow)
    {
        food_r = rand() % rows;
        food_c = rand() % cols;
    }
}

void Game::move(char input)
{
    input = std::tolower(input);

    if (input == 'w' && dir_r != 1)
    {
        dir_r = -1; dir_c = 0;
    }
    else if (input == 's' && dir_r != -1)
    {
        dir_r = 1; dir_c = 0;
    }
    else if (input == 'a' && dir_c != 1)
    {
        dir_r = 0; dir_c = -1;
    }
    else if (input == 'd' && dir_c != -1)
    {
        dir_r = 0; dir_c = 1;
    }
}
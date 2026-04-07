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

    auto head = snake.body[0];
    std::pair<int, int> current_target = {food_r, food_c};

    grid_obj.bake(snake);
    auto grid_data = grid_obj.get_data();

    std::vector<std::pair<int, int>> path = path_solver->solve(grid_data, head, current_target);

    if (!path.empty())
    {
        std::pair<int, int> next_step = (path[0] == head && path.size() > 1) ? path[1] : path[0];
        dir_r = next_step.first - head.first;
        dir_c = next_step.second - head.second;
    }
    else
    {
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nr = head.first + dr[i];
            int nc = head.second + dc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid_data[nr][nc] != -1)
            {
                dir_r = dr[i];
                dir_c = dc[i];
                break;
            }
        }
    }
}

void Game::render()
{
    grid_obj.bake(snake);
    const auto& grid_data = grid_obj.get_data();
    auto head = snake.body.front();
    auto tail = snake.body.back();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == head.first && j == head.second)
            {
                std::cout << "H ";
            }
            else if (i == tail.first && j == tail.second)
            {
                std::cout << "T ";
            }
            else if (grid_data[i][j] == -1)
            {
                std::cout << "B ";
            }
            else if (i == food_r && j == food_c)
            {
                std::cout << "F ";
            }
            else
            {
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

    if (head.first < 0 || head.first >= rows || head.second < 0 || head.second >= cols)
    {
        gameover = true;
    }

    for (size_t i = 1; i < snake.body.size(); i++)
    {
        if (snake.body[i] == head) gameover = true;
    }

    if (gameover)
    {
        std::cout << "GAME OVER\n";
        exit(0);
    }

    if (grow)
    {
        grid_obj.bake(snake);
        auto grid_data = grid_obj.get_data();
        bool valid_spawn = false;
        while (!valid_spawn)
        {
            food_r = rand() % rows;
            food_c = rand() % cols;
            if (grid_data[food_r][food_c] != -1)
            {
                valid_spawn = true;
            }
        }
    }
}

void Game::move(char input)
{
    input = std::tolower(input);
    if (input == 'w' && dir_r != 1) { dir_r = -1; dir_c = 0; }
    else if (input == 's' && dir_r != -1) { dir_r = 1; dir_c = 0; }
    else if (input == 'a' && dir_c != 1) { dir_r = 0; dir_c = -1; }
    else if (input == 'd' && dir_c != -1) { dir_r = 0; dir_c = 1; }
}
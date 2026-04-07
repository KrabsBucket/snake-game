#include "../include/Grid.h"


Grid::Grid(int r, int c) : rows(r), cols(c){
    data.resize(rows, std::vector<int>(cols, 0));

}

void Grid::bake(const Snake& snake){

    for(int r =0; r < rows; r++ ){
        for (int c= 0; c < cols; c++){
            data[r][c] = 0;
        }
    }


    for(size_t i = 1; i < snake.body.size(); i++)
    {
        int r = snake.body[i].first;
        int c = snake.body[i].second;
        if(r >= 0 && r < rows && c >= 0 && c < cols)
        {
            data[r][c] = -1;
        }
    }
}


const std::vector<std::vector<int>>& Grid::get_data() const {
    return data;
}
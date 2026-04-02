#include "../include/Snake.h"

Snake::Snake(int start_r, int start_c){
    body.push_back({start_r, start_c});
}


void Snake::move(int dr, int dc, bool grow){

    int new_r = body[0].first + dr;
    int new_c = body[0].second + dc;

    body.insert(body.begin(), {new_r, new_c});

    if (!grow)
        body.pop_back();

}
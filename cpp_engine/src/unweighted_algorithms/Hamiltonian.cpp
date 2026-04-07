#include "../../include/unweighted_algorithms/Hamiltonian.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <math.h>
Hamiltonian::Hamiltonian(int r, int c) {
    generate(r, c); 
}

void Hamiltonian::generate(int r, int c)
{ // HAMILTONIAN IS ASSUMING THAT r = c, i.e it's a perfect square grid as well as both are even
    rows = r;
    cols = c;

    cycle.clear();

    for (int i = 0; i < (r); i++)
    {
        cycle.push_back({i, 0});
    }

    for (int i = 1 ; i < (c); i++)
    {
        cycle.push_back({r-1, i});
    }
    cols = c- 1;

    for ( int i = 1; i < r ; i++)
    {
        rows = r-1 -i;
        cycle.push_back({rows, cols});
        for (int j = 1; j < c-1; j++)
        {
            cols += (i %2 == 0 ? 1 :-1) ;
            cycle.push_back({rows, cols });
        }
    }
}
std::vector<std::pair<int,int>> Hamiltonian::solve(
    const std::vector<std::vector<int>>& grid, 
    std::pair<int,int> start, 
    std::pair<int,int> target)
{
    for (size_t i = 0; i < cycle.size(); i++)
    {
        if (cycle[i].first == start.first && cycle[i].second == start.second)
        {
            size_t next_index = (i + 1) % cycle.size();
            return { cycle[next_index] };
        }
    }

    return { start }; 
}






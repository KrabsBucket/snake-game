#include "algorithms/Hamiltonian.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <math.h>


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
            cols += pow(-1,i);
            cycle.push_back({rows, cols });
        }
    }
}
    std::pair<int, int> Hamiltonian::next(int r, int c)
{
    for (int i = 0; i < cycle.size(); i++)
    {
        if (cycle[i].first == r && cycle[i].second == c)
        {
            int next_index = (i + 1) % cycle.size();
            return cycle[next_index];
        }
    }

    return {r, c}; 
}






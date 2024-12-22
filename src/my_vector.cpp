#ifndef MY_VECTOR_CPP
#define MY_VECTOR_CPP

#include "../includes/my_vector.h"

std::vector<int> print_vector(std::vector<int> &v)
{
    for (auto it : v)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

#endif
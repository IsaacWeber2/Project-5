#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <string>

class MinPath {
    public:
        MinPath(int max_size, int **d_array);
        ~MinPath();
        void Print(std::string city[]);
        void FindPath();

    private:
    int size;
    int **Weight;
    int *SmallestWeight;
    int *LastVisit;
    int hold;
};
#endif
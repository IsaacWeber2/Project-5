#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include "functions.hpp"

MinPath::MinPath(int max_size, int **d_array){
    size = max_size;

    Weight = new int *[size];
    for(int i = 0; i < size; i++)
    {
        Weight[i] = new int[size];
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            Weight[i][j] = d_array[i][j];
        }
    }

    SmallestWeight = new int [size];
    for (int i = 0; i < size; i++)
    {
        SmallestWeight[i] = std::numeric_limits<int>::max();
    }

    LastVisit = new int [size];
    for (int i = 0; i < size; i++)
    {
        LastVisit[i] = 0;
    }
}

MinPath::~MinPath(){
    for (int i = 0; i < size; i++)
    {
        delete[] Weight[i];
    }
    delete[] Weight;
    delete[] SmallestWeight;
    delete[] LastVisit;
}

void MinPath::FindPath(){

    for(int i = 1; i < size; i ++){
        if(Weight[0][i] != 0){
            SmallestWeight[i] = Weight[0][i];

        }
    }

    bool *weightFound;
    weightFound = new bool[size];
    for(int i = 0; i < size; i++)
    {
        weightFound[i] = false;
    }
    weightFound[0] = true;
    SmallestWeight[0] = 0;

    for( int i = 0; i < size - 1; i++){
        int min_num = std::numeric_limits<int>::max();
        int v = 0;

        for( int h = 0; h < size; h++){
            if(!weightFound[h]){
                if(SmallestWeight[h] < min_num)
                {
                    v = h;
                    min_num = SmallestWeight[h];
                }
            }
        }
        weightFound[v] = true;
        for( int j = 0; j < size; j++){
            if(!weightFound[j])
            {
                if(min_num + Weight[v][j] == SmallestWeight[j])
                {
                    SmallestWeight[j] = Weight[v][j] + min_num;
                    LastVisit[j] = v;
                }
            }
        }
    }
    hold = size;
}

void MinPath::Print(std::string city[]){
    std::vector<int> num;
    while(0 < hold)
    {
        num.push_back(hold);
        hold = LastVisit[hold];
    }
    num.push_back(hold);

    for(int i = num.size() - 1; i >= 0; i--)
    {
        std::cout << city[num[i]] << " -> ";
    }
    std::cout << city[0] << std::endl;

}
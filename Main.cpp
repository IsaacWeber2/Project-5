#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <string>


#include "functions.hpp"


int main(){
    
    int num_runs;
    std::cin >> num_runs;
    int ar_size;
    for(int i =0; i < num_runs; i++)
    {

        std::cin >> ar_size;

        std::string city;
        std::string city_ar[ar_size];
        for(int j =0; j < ar_size; j++)
        {
            std::cin >> city;
            city_ar[j] = city;
        }

        int** city_dist = new int*[ar_size];
        for(int h = 0; h < ar_size; h++)
        {
            city_dist[h] = new int[ar_size];
            for(int g = 0; g < ar_size; g++)
            {
                std::cin >> city_dist[h][g];
            }
        }
        MinPath Min(ar_size, city_dist);
        Min.FindPath();
        Min.Print(city_ar);
    }
    
    return 0;
}
#include "MovAverage.h"
#include <iostream>

void MovAverage(std::vector<float>& vals, int& window)
{
    if (vals.size() >= window && window > 0)
    {
        std::vector<float>::iterator it;
        it = vals.begin();
        std::advance(it, window - 1);
        float buff = 0;
        std::vector<float> buff_vals;
        for (int i = 1; i < vals.size(); i++)
        {
            for (int j = 1; j <= window; j++)
            {
                buff += *it;
                if (j == window) break;
                std::advance(it, -1);
            }
            buff = buff / window;
            buff_vals.push_back(buff);
            buff = 0;
            if (it < (vals.end() - (window)))
            {
                std::advance(it, window);
            }
            else break;
        }
    }
    else if (window) std::cout << "Error! Large window size!" << std::endl;
    else std::cout << "Error!Size of the window equal 0!" << std::endl;
}

void MovAverage(std::vector<double>& vals, int& window)
{
    if (vals.size() >= window && window > 0)
    {
        std::vector<double>::iterator it;
        it = vals.begin();
        std::advance(it, window - 1);
        double buff = 0;
        std::vector<double> buff_vals;
        for (int i = 1; i < vals.size(); i++)
        {
            for (int j = 1; j <= window; j++)
            {
                buff += *it;
                if (j == window) break;
                std::advance(it, -1);
            }
            buff = buff / window;
            buff_vals.push_back(buff);
            buff = 0;
            if (it < (vals.end() - (window)))
            {
                std::advance(it, window);
            }
            else break;
        }
    }
    else if (window) std::cout << "Error! Large window size!" << std::endl;
    else std::cout << "Error!Size of the window equal 0!" << std::endl;
}
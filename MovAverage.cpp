#include "MovAverage.h"
#include <iostream>

using namespace std;

void MovAverage(std::vector<float>& vals, int window)
{
    if (vals.size() >= window && window > 0)
    {
        std::vector<float> buff_vals;
        float sum = 0;

        for (int i = 0; i < vals.size(); i++)
        {
            sum += vals[i];
            if (i >= window)
            {
                buff_vals.push_back(sum / window);
                sum -= vals[i - window + 1];
            }
        }
    }
    else if (window > 0)
    {
        cout << "Error! Large window size!" << endl;
    }
    else
    {
        cout << "Error! Size of the window equals 0!" << endl;
    }
}

void MovAverage(std::vector<double>& vals, int window)
{
    if (vals.size() >= window && window > 0)
    {
        std::vector<double> buff_vals;
        double sum = 0;

        for (int i = 0; i < vals.size(); i++)
        {
            sum += vals[i];
            if (i >= window)
            {
                buff_vals.push_back(sum / window);
                sum -= vals[i - window + 1];
            }
        }
    }
    else if (window > 0)
    {
        cout << "Error! Large window size!" << endl;
    }
    else
    {
        cout << "Error! Size of the window equals 0!" << endl;
    }
}
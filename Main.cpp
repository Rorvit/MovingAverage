#include "MovAverage.h"
#include <iostream>
#include <vector>
#include <chrono>


using namespace std;
#define WINDOW_STP 7


void show_result(vector<double>& D_double, vector<float>& D_float)
{
    int window_sz = 4;

    for (int count = 1; count < WINDOW_STP; count++)
    {
        cout << window_sz << endl;
        auto start_f = chrono::high_resolution_clock::now();

        MovAverage(D_float, window_sz);
        auto end_f = chrono::high_resolution_clock::now();

        chrono::duration<float> duration_f = end_f - start_f;

        cout << "Exec time float: " << duration_f.count() << "sec" << endl;


        auto start_d = chrono::high_resolution_clock::now();

        MovAverage(D_double, window_sz);
        auto end_d = chrono::high_resolution_clock::now();

        chrono::duration<float> duration_d = end_d - start_d;

        cout << "Exec time double: " << duration_d.count() << "sec" << endl;

        window_sz *= 2;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    std::vector <float> D_float;
    std::vector <double> D_double;

    int vals = 1000000;

    for (int i = 1; i <= vals; i++)
    {
        D_float.push_back(rand() % 100);
        D_double.push_back(rand() % 100);
    }

    show_result(D_double, D_float);

    return 0;
}
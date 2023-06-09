// N09_HW01_Task02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include<vector>
#include <windows.h>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

vector<int> addVectors(const vector<int>& vec1, const vector<int>& vec2)
{
    // Check if the vectors have the same size  
    //auto start = chrono::high_resolution_clock::now();

    if (vec1.size() != vec2.size())
    {
        std::cout << "Error: Vectors must have the same size to add them." << std::endl;
        return vector<int>();
    }

    // Create a vector to store the result  
    vector<int> result(vec1.size());

    // Add the elements of vec1 and vec2 and store the result in result  
    for (int i = 0; i < vec1.size(); i++)
    {
        result[i] = vec1[i] + vec2[i];
    }
    //auto end = chrono::high_resolution_clock::now();
    //chrono::duration<double, milli> time = end - start;
    //cout << " time = " << time.count() << endl;

    return result;
}
void addVectors_time(const vector<int>& vec1, const vector<int>& vec2, int thread_count)
{
    // Check if the vectors have the same size  
    auto start = chrono::high_resolution_clock::now();
    vector<thread> TV;
    for (int i = 0; i < thread_count; i++)
    {
        TV.push_back(thread(addVectors, vec1, vec2));
    }
    for (auto& t : TV)
    {
        t.join();
    }
    //cout << endl;/**/
    
    addVectors(vec1, vec2);
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> time = end - start;
    cout << time.count() ;
}

int main()
{
    //std::cout << "Hello World!\n";

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    //------------------

    vector<int> a_1000(1'000);
    mt19937 gen1;
    uniform_int_distribution<int> dis1(0, 1'000);
    auto rand_num1([=]() mutable {return dis1(gen1); });
    generate(a_1000.begin(), a_1000.end(), rand_num1);

    vector<int> b_1000(1'000);
    mt19937 gen2;
    uniform_int_distribution<int> dis2(0, 1'000);
    auto rand_num2([=]() mutable {return dis2(gen2); });
    generate(b_1000.begin(), b_1000.end(), rand_num2);

    vector<int> a_10000(10'000);
    mt19937 gen3;
    uniform_int_distribution<int> dis3(0, 10'000);
    auto rand_num3([=]() mutable {return dis3(gen3); });
    generate(a_10000.begin(), a_10000.end(), rand_num3);

    vector<int> b_10000(10'000);
    mt19937 gen4;
    uniform_int_distribution<int> dis4(0, 10'000);
    auto rand_num4([=]() mutable {return dis4(gen4); });
    generate(b_10000.begin(), b_10000.end(), rand_num4);

    //------------------

    vector<int> a_100000(100'000);
    mt19937 gen5;
    uniform_int_distribution<int> dis5(0, 100'000);
    auto rand_num5([=]() mutable {return dis5(gen5); });
    generate(a_100000.begin(), a_100000.end(), rand_num5);

    vector<int> b_100000(100'000);
    mt19937 gen6;
    uniform_int_distribution<int> dis6(0, 100'000);
    auto rand_num6([=]() mutable {return dis6(gen6); });
    generate(b_100000.begin(), b_100000.end(), rand_num6);

    //------------------

    vector<int> a_1000000(1'000'000);
    mt19937 gen7;
    uniform_int_distribution<int> dis7(0, 1'000'000);
    auto rand_num7([=]() mutable {return dis7(gen7); });
    generate(a_1000000.begin(), a_1000000.end(), rand_num7);

    vector<int> b_1000000(1'000'000);
    mt19937 gen8;
    uniform_int_distribution<int> dis8(0, 1'000'000);
    auto rand_num8([=]() mutable {return dis8(gen8); });
    generate(b_1000000.begin(), b_1000000.end(), rand_num8);
    
    cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << endl;
    cout << "           1000           10000           100000           1000000" << endl;
    cout << "1 поток   " ;

    addVectors_time(a_1000, b_1000, 1);
    cout << "           " ;
    addVectors_time(a_10000, b_10000, 1);
    cout << "           " ;
    addVectors_time(a_100000, b_100000, 1);
    cout << "           " ;
    addVectors_time(a_1000000, b_1000000, 1);
    cout << "           " << endl;
    
    cout << "2 потока  " ;
    addVectors_time(a_1000, b_1000, 2);
    cout << "           " ;
    addVectors_time(a_10000, b_10000, 2);
    cout << "           " ;
    addVectors_time(a_100000, b_100000, 1);
    cout << "           " ;
    addVectors_time(a_1000000, b_1000000, 1);
    cout << "           " << endl;

    cout << "4 потока  " ;
    addVectors_time(a_1000, b_1000, 4);
    cout << "           " ;
    addVectors_time(a_10000, b_10000, 4);
    cout << "           " ;
    addVectors_time(a_100000, b_100000, 1);
    cout << "           " ;
    addVectors_time(a_1000000, b_1000000, 1);
    cout << "           " << endl;

    cout << "8 потока  ";
    addVectors_time(a_1000, b_1000, 8);
    cout << "           " ;
    addVectors_time(a_10000, b_10000, 8);
    cout << "           " ;
    addVectors_time(a_100000, b_100000, 1);
    cout << "           " ;
    addVectors_time(a_1000000, b_1000000, 1);
    cout << "           " << endl;

    cout << "16 потока ";
    addVectors_time(a_1000, b_1000, 16);
    cout << "           " ;
    addVectors_time(a_10000, b_10000, 16);
    cout << "           " ;
    addVectors_time(a_100000, b_100000, 1);
    cout << "           "  ;
    addVectors_time(a_1000000, b_1000000, 1);
    cout << "           " << endl;
    
}

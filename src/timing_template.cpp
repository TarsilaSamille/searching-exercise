/*!
 * This is a template code to demonstrate how to measure runtime of part of your code.
 * I'm using the chrono C++ library.
 * @date September 8th, 2020.
 * @author Selan
 *
 * Para compilar: g++ -Wall -std=c++11 timing_template.cpp searchin.cpp -o timing_search
 */

#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <math.h>
#include "searching.h"

using namespace sa;
using namespace std;

constexpr unsigned long long LIMIT{1000000000};

int main( void )
{
    value_type *A = new value_type[LIMIT];

    std::cout << ">>> Generating array for testing, please wait...\n";
    for( auto i{0ull} ; i < LIMIT ; ++i )
        A[i]  = i;
    std::cout << "    Done!\n\n";

    unsigned long tamanho_array = 100000000ul;

    while(tamanho_array <= LIMIT + 1){


    std::cout << ">>> STARTING linear search with " << tamanho_array << " that needs timing, please WAIT.... <<<\n";
    auto start = std::chrono::steady_clock::now();
    //================================================================================

    auto result = lsearch(&A[0], &A[tamanho_array], -1 );

    //================================================================================

    std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
    std::cout << ">>> ENDING computation that needs timing <<<\n";
    if (result != &A[tamanho_array])
        std::cout << "Located element at " << std::distance(&A[0], result) << "\n";
    else
        std::cout << "Target not found!\n";

    // Store the time difference between start and end
    std::chrono::duration<double> diff = end - start;

    // Milliseconds (10^-3)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count()
        << " ms" << std::endl;

    // Nanoseconds (10^-9)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::nano> (diff).count()
        << " ns" << std::endl;

    // Seconds
    auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    std::cout << "\t\t>>> " << diff_sec.count() << " s" << std::endl;


    std::cout << ">>> STARTING binary search with " << tamanho_array << " that needs timing, please WAIT.... <<<\n";
    start = std::chrono::steady_clock::now();
    //================================================================================

    result = bsearch( &A[0], &A[tamanho_array], -1 ); // -1 não está presente.

    //================================================================================
    end = std::chrono::steady_clock::now();
    std::cout << ">>> ENDING computation that needs timing <<<\n";

    if (result != &A[tamanho_array])
        std::cout << "Located element at " << std::distance(&A[0], result) << "\n";
    else
        std::cout << "Target not found!\n";
    // Store the time difference between start and end
    diff = end - start;

    // Milliseconds (10^-3)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count()
        << " ms" << std::endl;

    // Nanoseconds (10^-9)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::nano> (diff).count()
        << " ns" << std::endl;

    // Seconds
    diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    std::cout << "\t\t>>> " << diff_sec.count() << " s" << std::endl;

    tamanho_array = tamanho_array + 18000000;

    }
    delete [] A;

    return EXIT_SUCCESS;
}

#ifndef __time_Manager_h__
#define __time_Manager_h__

#include <iostream>
#include <chrono>


using namespace std;

chrono::duration<double> get_time();

chrono::time_point<chrono::system_clock> end_timer();

chrono::time_point<chrono::system_clock> start_timer();


#endif // __time_Manager_h__

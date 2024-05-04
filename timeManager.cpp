#include <chrono>

#include "headers/timeManager.h"

using namespace std;

chrono::duration<double> elapsed_seconds;

chrono::time_point<chrono::system_clock> timer_start;
chrono::time_point<chrono::system_clock> timer_end;

chrono::time_point<chrono::system_clock> start_timer() {
    timer_start = chrono::system_clock::now();
    return timer_start;
}


chrono::time_point<chrono::system_clock> end_timer() {
    timer_end = chrono::system_clock::now();
    return timer_end;
}

chrono::duration<double> get_time() {
    elapsed_seconds = timer_end-timer_start;
    return elapsed_seconds; 
}
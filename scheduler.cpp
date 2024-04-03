#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <string>
#include <thread>
#include <mutex>

#include "algos.cpp"

using namespace std;

string running;

long total_workload = 0; //keeps track of total work done
chrono::microseconds elapsed;
vector<Job*> jobs;

void print_elapsed(chrono::steady_clock::time_point begin){
    auto now = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(now-begin);
    elapsed = duration;
    std::cout << elapsed.count() << " microseconds have passed.\n";
}

void interrupt(){

    for(int i = 0; i<algosLibrary.size(); ++i){
        if(algosLibrary[i] == running){

        }
    }

}

void interrupter(chrono::steady_clock::time_point begin){
    while (elapsed < chrono::microseconds(10000))
    {
        this_thread::sleep_for(chrono::milliseconds(5000));
        print_elapsed(begin);
    }
}

void produceJobs(int num_jobs, vector<Job*>& jobs){
    //generate random jobs and add them to the list of incoming jobs
    for (int i = 0; i < num_jobs; ++i){
        srand(time(NULL));
        long length = rand() % 10000000 + 1000;
        int m = rand() % 3 + 1;
        int k = rand() % 7 + m;
        Job* j = new Job(m, k, length, i);
        
        jobs.push_back(j);
        total_workload += length;
    }
}

void allocAlgo(void* algo, string algo_name, vector<Job*> jobs){
    if (algo_name == "FCFS") algo = new FCFS(jobs);
}

int main(int argc, char* argv[]){

    auto begin = chrono::high_resolution_clock::now();
    int num_jobs = 10; //default number of jobs is 10
    string algo_name = (argc > 1) ? argv[1] : "FCFS"; //default algo is FCFS; otherwise, use provided
    algorithm* algo;
    produceJobs(num_jobs, jobs);
    allocAlgo(algo, algo_name, jobs);
    cout << "Produced " << jobs.size() << " jobs" << endl;
    std::thread t(interrupter, begin);
    algo->run();
    t.join();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end-begin);
    cout << "Jobs ran in " << duration.count() << " seconds." << endl;
    cout << "Total workload: " << total_workload << endl;

    return 0;
}
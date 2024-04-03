#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <string>
#include <thread>
#include <mutex>

#include "algos.cpp"

using namespace std;

long total_workload = 0; //keeps track of total work done

void print_elapsed(){
    chrono::steady_clock::time_point now = chrono::high_resolution_clock:now();

}
void interrupter(){

    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "good morning" << endl;
    }

}
void produceJobs(int num_jobs, vector<Job*>& jobs){
    //generate random jobs and add them to the list of incoming jobs
    for (int i = 0; i < num_jobs; ++i){
        long length = rand() % 1000000 + 1000;
        int m = rand() % 3 + 1;
        int k = rand() % 7 + m;
        Job* j = new Job(m, k, length, i);
        
        jobs.push_back(j);
        total_workload += length;
    }
}

void runJobs(int num_jobs, vector<Job*>& jobs){
    for(auto& i: jobs){
        i->Run();
    }
}

void schedule_jobs(int num_jobs, vector<Job*>& jobs, string algo){

    if(algo == "FCFS"){
        FCFS(num_jobs, jobs);
    }
}

int main(int argc, char* argv[]){

    auto begin = chrono::high_resolution_clock::now();
    vector<Job*> jobs;
    int num_jobs = 10; //default number of jobs is 10
    string algo = (argc > 1) ? argv[1] : "FCFS"; //default algo is FCFS; otherwise, use provided
    produceJobs(num_jobs, jobs);
    cout << "Produced " << jobs.size() << " jobs" << endl;
    schedule_jobs(num_jobs, jobs, algo);
    thread t(interrupter);
    runJobs(num_jobs, jobs);
    t.join();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-begin);
    cout << "Jobs ran in " << duration.count() << " microseconds." << endl;
    cout << "Total workload: " << total_workload << endl;

    return 0;
}
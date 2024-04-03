#include <iostream>
#include <vector>
#include <algorithm>

#include "job.cpp"


//run jobs in order of lowest id to highest id
void FCFS(int num_jobs, std::vector<Job*>& jobs){
    sort(jobs.begin(), jobs.end());
}
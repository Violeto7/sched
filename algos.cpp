#include <iostream>
#include <vector>
#include <algorithm>

#include "job.cpp"

//enum algos {FCFS,};
vector<string> algosLibrary = {"FCFS"};

class algorithm {
    private:
        vector<Job*> jobs;
    
    public: 
        //if this function was not overridden then the interrupt occured but did not change anything
        virtual void interrupt(){
            cout << "Interrupt did not affect anything.\n";
        }
        virtual void setJobs(vector<Job*> incoming){
            jobs = incoming;
        }
        virtual void run();
};

class FCFS : public algorithm {
    private:
        vector<Job*> jobs;
    public: 
        void run(){
            sort(jobs.begin(), jobs.end());
            for(auto& i: jobs){
                i->Run();
                cout << "Job # " << i->id << " has finished";
            }
        }
        FCFS(vector<Job*> jobs) {jobs = jobs;}
};
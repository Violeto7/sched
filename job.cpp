class Job {
    private: 
        int M, K; //weakly-hard parameters
        long Length; //how long to run our job (i.e. how much processing time does this job need)
        long work_done; //how much work has already been done on this job
        bool deadline_missed;

    public:

        int id;

        void Run(){
            for( int i = 0; i<Length-work_done; ++i){}
        }
        Job(int m, int k, int length, int i){
            M = m;
            K = k;
            Length = length;
            work_done = 0;
            id = i;
            deadline_missed = false;
        }
        long get_length(){return Length;}
        
        bool dl_missed(){return deadline_missed;}
        void set_missed(bool b){deadline_missed = b;}
        
        //overloaded to allow sorting
        bool operator < (const Job& j) const{
            return id < j.id;
        }
};
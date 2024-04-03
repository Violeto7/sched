class Job {
    private: 
        int M, K; //weakly-hard parameters
        long Length; //how long to run our job (i.e. how much processing time does this job need)
        long work_done; //how much work has already been done on this job
        bool deadline_missed;

    public:

        int id;

        void Run(){
            int i = 0;
            while(i < Length - work_done && !is_done()){
                ++i;
                ++work_done;
            }
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
        bool is_done(){return work_done == Length;}
        bool dl_missed(){return deadline_missed;}
        void set_missed(bool b){deadline_missed = b;}
        
        //overloaded to allow sorting
        bool operator < (const Job& j) const{
            return id < j.id;
        }
};
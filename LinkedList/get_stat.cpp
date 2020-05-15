#include <unistd.h>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void mem_usage(double& vm_usage, double& resident_set) {
   vm_usage = 0.0;
   resident_set = 0.0;
   ifstream stat_stream("/proc/self/stat",ios_base::in); //get info from proc
   //create some variables to get info
   string pid, comm, state, ppid, pgrp, session, tty_nr;
   string tpgid, flags, minflt, cminflt, majflt, cmajflt;
   string utime, stime, cutime, cstime, priority, nice;
   string O, itrealvalue, starttime;
   unsigned long vsize;
   long rss;
   stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
   >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
   >> utime >> stime >> cutime >> cstime >> priority >> nice
   >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care
   stat_stream.close();
   long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // for x86-64 is configured

   vm_usage = vsize / 1024.0;
   resident_set = rss * page_size_kb;
}
int main() {
   double vm, rss;
   
   //int n = 1000000;
   //int *A = new int[n];

   //for (int i=1; i<n; i++) A[i]++;




   mem_usage(vm, rss);
   cout << "Virtual Memory: " << vm << "\nResident set size: " << rss << endl;

   //delete[] A;

   return 0;
}

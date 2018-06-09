#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class Heap{
public:	

	vector<std::pair<long long, long long> >threads;
	long long size;
	Heap(long long num_workers_){
		size = num_workers_;
		threads.resize(num_workers_,make_pair(0,0));
		for(long long i = 0;i<num_workers_;i++)
			threads[i].first = i;
	}
	
	void ShiftDown(long long i){
		long long maxIndex = i;
		long long l = 2*i+1;
		if(l<size && (threads[l].second<threads[maxIndex].second || (threads[l].second==threads[maxIndex].second && threads[l].first<threads[maxIndex].first) ))
			maxIndex = l;
		long long r = 2*i+2;	
		if(r<size && (threads[r].second<threads[maxIndex].second|| (threads[r].second==threads[maxIndex].second && threads[r].first<threads[maxIndex].first) )   )
			maxIndex = r;
		
		if(i!=maxIndex){
            //if(threads[r].second == threads[l].second && threads[l].first> threads[r].first)
              //  maxIndex = r;
			swap(threads[i], threads[maxIndex]);
			ShiftDown(maxIndex);
		}
	
    }
	long long Parent(long long i){
		return ((i-1)/2);
	}
	
	void ShiftUp(long long i){
		while(i>1 && (threads[Parent(i)].second>threads[i].second || (threads[Parent(i)].second==threads[i].second && threads[Parent(i)].first>threads[i].first))){
			swap(threads[i], threads[Parent(i)]);
			i = Parent(i);
		}
	}
	
	void ChangePriority(long long i,long long p){
		long long old_priority = threads[i].second;
		threads[i].second= p;
		
		if(p<old_priority)
			ShiftUp(i);
		else if(p>old_priority)
			ShiftDown(i);
		ShiftDown(i);
	}	
};


class JobQueue {
 private:
  long long num_workers_;
  vector<long long> jobs_;

  vector<long long> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (long long i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    long long m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(long long i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    Heap heap(num_workers_);
	for (long long i = 0; i < jobs_.size(); ++i) {
		assigned_workers_[i]= heap.threads[0].first;
		start_times_[i] =  heap.threads[0].second;
		heap.ChangePriority(0,heap.threads[0].second+jobs_[i]);
	}
	
	
	/*vector<long long> next_free_time(num_workers_, 0);
    for (long long i = 0; i < jobs_.size(); ++i) {
      long long duration = jobs_[i];
      long long next_worker = 0;
      for (long long j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }*/
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}

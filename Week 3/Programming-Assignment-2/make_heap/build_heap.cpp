#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  
  void ShiftDown(int i,int size){
	int minIndex = i;
	int l = 2*i+1;
	if(l<size && data_[l]<data_[minIndex])
		minIndex = l;
	int r = 2*i+2;	
	if(r<size && data_[r]<data_[minIndex])
		minIndex = r;
	
	if(i!=minIndex){
		swap(data_[i], data_[minIndex]);
        swaps_.push_back(make_pair(i, minIndex));
		ShiftDown(minIndex,size);
	}
    
  }
  void BuildHeap(){
	int size = data_.size();
	for(int i =size/2-1;i>=0;i--){
		ShiftDown(i,size);
	}
	//for(int i = 0;i<size;i++)
		//std::cout<<data_[i]<<" ";
  }
  
  
  void GenerateSwaps() {
    swaps_.clear();
    
    BuildHeap();
	int size = data_.size();
    //for(int i = 0;i<data_.size();i++)
      //  std::cout<<data_[i]<<" ";
      
    //swaps_.clear();
      
      /*while(size>=1){
        swap(data_[0], data_[size-1]);
		
        size = size-1;
        
		ShiftDown(0,size);
      }*/

    /*  for(int i =0;i<data_.size();i++){
		swap(data_[i], data_[size-1]);
		
        //size = size-1;
        
		ShiftDown(i,size);
	}
	for(int i = 0;i<data_.size();i++)
        std::cout<<data_[i]<<" ";
	
	*/
	
	// for (int i = 0; i < data_.size(); ++i)
      // for (int j = i + 1; j < data_.size(); ++j) {
        // if (data_[i] > data_[j]) {
          // swap(data_[i], data_[j]);
          // swaps_.push_back(make_pair(i, j));
        // }
      // }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}

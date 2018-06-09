#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;


/*class Node{
	int key;
	Node *left;
	Node *right;
	Node() {
      this->left = NULL;
	  this->right = NULL;
    }
}
*/
class TreeOrders {
  
  vector <int> key;
  vector <int> left;
  vector <int> right;
  //vector<Node> tree;
public:
  int n;
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
	//tree.resize(n);
    for (int i = 0; i < n; i++) {
		cin >> key[i] >> left[i] >> right[i];
		//Node temp;
		//temp.key = key[i];
		//tree.push_back(temp);
    }
	/*
	for(int i=0;i<n;i++){
		for (int j=1;j<n;j++){
			if(left[i]!=-1 && left[i]==tree[j].key)
				tree[i].left = &tree[j];
			else if(right[i]!=-1 && right[i]==tree[j].key)
				tree[i].right = &tree[j];
		}
	}
	*/
  }

  void InOrder(int t){
	if(left[t] != -1)
		InOrder(left[t]);
	cout<<key[t]<<" ";
	if(right[t] != -1)
		InOrder(right[t]);
  }

  vector <int> in_order() {
    vector<int> result;
	InOrder(0);	

    return result;
  }
  
  void PreOrder(int t){
	cout<<key[t]<<" ";
	if(left[t] != -1)
		PreOrder(left[t]);
	if(right[t] != -1)
		PreOrder(right[t]);
  }
  
  vector <int> pre_order() {
    vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
    
    return result;
  }

  void PostOrder(int t){
	if(left[t] != -1)
		PostOrder(left[t]);
	if(right[t] != -1)
		PostOrder(right[t]);
	cout<<key[t]<<" ";
  }
  
  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  
  t.InOrder(0);
  cout<<'\n';
  t.PreOrder(0);
  cout<<'\n';
  t.PostOrder(0);
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}


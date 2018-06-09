#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};


bool InOrder(const vector<Node>& tree,int t,int low,int high){
	Node temp = tree[t];
	//if(temp.left == -1 && temp.right == -1)
		//return true;
	
	if(low<temp.key && temp.key<high)
	{
		//cout<<t<<" "<<temp.left<<" "<<low<<" "<<high<<"\n";
		return (temp.left!=-1?InOrder(tree,temp.left,low,temp.key):true) && (temp.right!=-1?InOrder(tree,temp.right,temp.key,high):true);
	}
	else
		return false;
	
	
	// if(temp.left != -1){
		// Node left = tree[temp.left];
		// /*if(temp.key > left.key)
			// return InOrder(tree,left.left);
		// else
			// return false;*/
		// if(temp.key < left.key)
			// return false;
	// }
		
	// if(temp.right != -1){
		// Node right = tree[temp.right];
		// /*if(temp.key < right.key)
			// return InOrder(tree,right.right);
		// else
			// return false;
		// */
		// if(temp.key>right.key)
			// return false;
	// }
	
	// return (temp.left!=-1?InOrder(tree, temp.left):true) && (temp.right!=-1?InOrder(tree, temp.right):true);
  }

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if(tree.size()==0)
	return true;
//cout<<INT_MIN<<" "<<INT_MAX;
  return InOrder(tree,0,INT_MIN,INT_MAX);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
/*
	if(InOrder(tree,temp.left,low)){
		if(temp.key>low){
			low = temp.key;
			return 
		}
	}
	*/
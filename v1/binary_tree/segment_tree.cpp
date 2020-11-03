/*seegment tree: sum of range query */

#include<iostream>
#include<vector>
using namespace std;


struct Node{
	int data;
	Node * left, *right;
	Node(int data) : data(data), left(NULL), right(NULL) {};
};

Node * segment_tree(vector<int> arr, int l, int r){
	if(l==r){
		return new Node(arr[l]);
	}
	Node * root = new Node(0);
	int mid = (l+r)/2;
	root->left = segment_tree(arr,l,mid);
	root->right = segment_tree(arr,mid+1,r);
	root->data = root->left->data+root->right->data;
	return root;
}


int query_segment_tree(Node * node, int l, int r, int ql, int qr){

	if(( r<ql) || (l>qr)){ // disjoint
		return 0;
	}
	if(l>=ql && r<=qr){ // inside the range
		return node->data;
	}

	int mid = (l+r)/2;
	int l_sum = query_segment_tree(node->left,l,mid,ql,qr);		
	int r_sum = query_segment_tree(node->right,mid+1,r,ql,qr);
	return l_sum + r_sum;
}

int main(){
	vector<int> arr = {1,2,3,4,5,6};
	Node * root = segment_tree(arr, 0, arr.size()-1);
	cout<< query_segment_tree(root,0,arr.size()-1,2,5);
	return 0;
}

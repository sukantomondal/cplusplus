/* Reevrse alternate level of a perfect binary tree */
/*Given a Perfect Binary Tree, reverse the alternate level nodes of the binary tree. 

Given tree: 
               a
            /     \
           b       c
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
       h  i j  k l  m  n  o 

Modified tree:
               a
            /     \
           c       b
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
      o  n m  l k  j  i  h 

Another is to do two inorder traversals. The following are the steps to be followed. 
1) Traverse the given tree in inorder fashion and store all odd level nodes in an auxiliary array. For the above example given tree, contents of array become {h, i, b, j, k, l, m, c, n, o}
2) Reverse the array. The array now becomes {o, n, c, m, l, k, j, b, i, h}
3) Traverse the tree again inorder fashion. While traversing the tree, one by one take elements from array and store elements from an array to every odd level traversed node. 
For the above example, we traverse ‘h’ first in the above array and replace ‘h’ with ‘o’. Then we traverse ‘i’ and replace it with n. 

*/

#include<iostream>
#include<vector>
using namespace std;

struct Node {
	char data;
	Node * left;
	Node * right;
};

Node * newNode (char data) {
	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}


void reverse_alternate_level (Node * node, vector<char> &arr, int &index,  int level, bool update) {
	if (node == NULL){
		return; 
	}

	reverse_alternate_level(node->left, arr, index, level+1,  update);
	if(!update) {
		arr[index++] = node->data;
		//cout << node->data << "\n";
	}else if(update && level%2 !=0) {
		node->data = arr[index++];
	}
	reverse_alternate_level(node->right, arr, index, level+1, update);
}


void reverse_array (vector<char> &arr) {
	int l = 0, r = arr.size()-1;
	while(l<r) {
		swap(arr[l++], arr[r--]);
	}
}


int main () {


	Node * root = newNode('a');
	root->left = newNode('b');
	root->right = newNode('c');
	root->left->left = newNode('d');
	root->left->right = newNode('e');
	root->right->left = newNode('f');
	root->right->right = newNode('g');

	vector<char> arr(7);
	int index = 0;

	reverse_alternate_level(root, arr, index, 1, false);

	cout << "Inorder traversal befor alternate \n";
	for(auto &it : arr) {
		cout << it << " ";
	}
	cout << "\n";

	cout << "After alternate reverse \n";
	reverse_array(arr);
	index = 0;
	reverse_alternate_level(root, arr, index, 1, true);
	index = 0;
	reverse_alternate_level(root, arr, index, 1, false);

	for(auto &it : arr) {
		cout << it << " ";
	}
	cout << "\n";

	return 0;
}

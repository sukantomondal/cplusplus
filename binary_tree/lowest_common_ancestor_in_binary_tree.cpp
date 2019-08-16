/* lowest common ancestor in binary tree */

#include<iostream>
#include<vector>

using namespace std;

struct Node {

	int data;
	Node * left, * right;
};

Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}


// another way
//

bool find_path(Node * root, Node * dnode, vector<int> &path){

	if(root == NULL)
		return false;

	path.push_back(root->data);

	cout << root->data << "\n";

	if(root->data == dnode->data)
		return true;

	if ((root->left && find_path(root->left,dnode,path)) || (root->right && find_path(root->right,dnode,path))){
		return true;
	}

	path.pop_back();

	return false;

}


void get_path(Node * root, Node *dnode , vector<int> path, vector<int> &result_path){

	if(root == NULL)
		return;
	path.push_back(root->data);

	cout << root->data << "\n";

	if(root->data == dnode->data){
		result_path=path;
		return;
	}

	get_path(root->left, dnode, path, result_path);
	get_path(root->right, dnode, path,result_path);
	
	path.pop_back();
}



void lsa(Node * root, Node * d1, Node * d2){

	vector<int> pathd1;
	vector<int> pathd2;
	find_path(root,d1,pathd1);
	find_path(root,d2,pathd2);
	//get_path(root,d1,pathd1,pathd1);
	//get_path(root,d2,pathd2,pathd2);

	for(auto x : pathd1){

		cout << x << " ";
	}
	cout << "\n";

	for(auto x : pathd2){

		cout << x << " ";
	}
	cout << "\n";


	cout << "Common ancestor: ";
	for(int i = 0 ; i < pathd1.size() && i< pathd2.size(); i++){

		if(pathd1[i] != pathd2 [i]){
			cout << pathd1[i-1] << "\n";
			break;
		}
	}
}

int main(){

	Node * root = get_node(1);
	root->left = get_node(2);
	root->right = get_node(3);
	root->left->left = get_node(4);
	root->left->right = get_node(5);
	root->right->left = get_node(6);
	root->right->right = get_node(7);

	lsa(root,root->left->left, root->right->right);

	return 0;
}

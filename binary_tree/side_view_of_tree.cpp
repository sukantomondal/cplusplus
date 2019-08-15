/*side view of tree */


#include<iostream>
#include<queue>
#include<map>
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

void level_traversal(Node * root){

	queue<Node *> q;

	q.push(root);
	q.push(NULL);

	map<int,vector<int>> levels;
	int level = 0;

	while(q.size()){
		Node *tmp = q.front();
		q.pop();
		if(tmp == NULL){
			level++;
			cout << "\n"; // end of level;
			if(q.size())
				q.push(NULL);
		}else{
			cout << tmp->data << " ";
			levels[level].push_back(tmp->data);
			if(tmp->left != NULL){
				q.push(tmp->left);
			}
			if(tmp->right != NULL){
				q.push(tmp->right);
			}
		}
	}

	cout << "left view :";

	for(auto x : levels){
		cout << x.second.front() << " ";
	}
	cout << "\n";

	cout << "right view :";
	for(auto x: levels){
		cout << x.second.back() << " ";
	}	
	cout << "\n";
}

int main(){

	Node * root = get_node(1);
	root->left = get_node(2);
	root->right = get_node(3);
	root->left->left = get_node(4);
	root->left->right = get_node(5);
	root->right->left = get_node(6);
	root->right->right = get_node(7);

	level_traversal(root);

	return 0;
}

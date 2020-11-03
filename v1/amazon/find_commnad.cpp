/* find command */


#include<iostream>
#include<vector>
using namespace std;

struct File{
	string file_type;
	string file_name;
	float size;
};

struct Dir{
	string dir_name;
	vector<File> files;
	vector<Dir*> sub_dirs;
};


void find(Dir *root, string ext, float size, vector<string> &result){

	if(root == NULL)
		return;
	for(int i = 0; i < root->files.size(); i++){
		if(root->files[i].file_type == ext){
			result.push_back(root->files[i].file_name);
		}
	}

	for(int i = 0; i < root->sub_dirs.size(); i++){
		find(root->sub_dirs[i], ext, size, result);
	}	
}


int main(){


	Dir * root = new Dir();
	root->dir_name = "root";
	root->files = {{"xml", "a.xml", 5.0}, {"pdf", "a.pdf", 3.0}};
	
	Dir * sub11 = new Dir;
	sub11->dir_name = "sub11";
	sub11->files = {{"xml", "a11.xml", 5.0}, {"pdf", "a11.pdf", 3.0}};

	root->sub_dirs.push_back(sub11);

	vector<string> result;
	find(root, "pdf", 1.0, result);

	for(auto x: result){
		cout << x << "\n";
	}

	return 0;
}

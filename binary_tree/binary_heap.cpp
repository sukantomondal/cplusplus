/* create a binary Min heap form */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Heap{

	vector<int> heap_arr;
	unordered_map<int,int> position;

	int parent(int i){return (i-1)/2;}
	int left (int i) {return 2*i + 1;}
	int right(int i) {return 2*i + 2;}

	public:
	Heap(){};
	int size(){return heap_arr.size();}
	int get_min();
	int extract_min();
	void update_key(int index, int new_val);
	void delete_key(int index);
	void push_key(int value);
	void heapify(int index);
	void fix_heap(int index);
	int key_exists(int key);
	vector<int> contents();
};

vector<int> Heap::contents(){

	for(auto x : position){
		cout << x.first << "   " << x.second << "\n";
	}
	return heap_arr;
}

int Heap::key_exists(int key){
	if(position.find(key) != position.end()){
		return position[key];
	}
	return -1;
}

int Heap::get_min(){
	if(size()==0)
		return -1;
	return heap_arr[0];
}

int Heap::extract_min(){
	if(size()== 0)
		return -1;
	int value = heap_arr[0];

	
	position.erase(heap_arr[0]); // remove first element

	int last_element = heap_arr[size()-1];
	heap_arr[0] = last_element;
	heap_arr.pop_back();

	position[heap_arr[0]] = 0;

	for(auto x : heap_arr){
                  cout << x << " ";
          }
          cout << "\n";

	heapify(0);
}

void Heap :: push_key(int value){

	heap_arr.push_back(value);
	int index = size()-1;
	position[heap_arr[index]] = index;
	fix_heap(index);
}

void Heap :: update_key(int index, int value){
	
	if(index>=size() || index < 0)
		return;
	heap_arr[index] = value;
	position[heap_arr[index]] = index;
	fix_heap(index);
}

void Heap::delete_key(int index){
	if(index >= size() || index < 0)
		return;
	
	position.erase(heap_arr[index]);
	update_key(index, INT8_MIN);
	extract_min();
}

void Heap::fix_heap(int index){

	while(index!=0 && heap_arr[index] < heap_arr[parent(index)]){

		position[heap_arr[index]] = parent(index);
		position[heap_arr[parent(index)]] = index;

		swap(heap_arr[index],heap_arr[parent(index)]);
		index = parent(index);
	}
}

void Heap::heapify(int index){

	int root = index;
	int l = left(root);
	int r = right(root);

	int smallest = root;

	if(l< size() && heap_arr[l] < heap_arr[root]){
		smallest = l;
	}
	if( r < size() && heap_arr[r] < heap_arr[root]){

		if(heap_arr[smallest] > heap_arr[r])
			smallest = r;
	}


	if(smallest != root){

		position[heap_arr[smallest]] = root;
		position[heap_arr[root]] = smallest;

		swap(heap_arr[root],heap_arr[smallest]);

		heapify(smallest);
	}
}


int main(){

	Heap min_heap;
	cout << min_heap.size() << "\n";

	min_heap.push_key(5);
	min_heap.push_key(10);
	min_heap.push_key(-1);
	min_heap.push_key(100);

	cout <<"size " <<min_heap.size() <<" min: "<< min_heap.get_min() << "\n";

	for (auto x : min_heap.contents()){
		cout << x << " ";
	}
	cout << "\n";

	//min_heap.delete_key(3);
	
	
	int index = min_heap.key_exists(10);
	cout << index << "\n";
	min_heap.delete_key(index);

	min_heap.push_key(-90);

	cout <<"size " <<min_heap.size() << " min: " << min_heap.get_min() << "\n";
	for (auto x : min_heap.contents()){
		cout << x << " ";
	}
	cout << "\n";


	return 0;
}

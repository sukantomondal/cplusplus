/* Sum of subset problem */


#include<iostream>
#include<vector>
using namespace std;


void sum_of_subset(vector<int>set, int level, vector<int>result, int sum_so_far, int remaining_sum, int expected_sum){

	
	if(level >= set.size())
		return;
	
	if(sum_so_far == expected_sum){

		cout<< "Got the subset \n";
		for(int i=0; i<result.size(); i++){
			if(result[i] !=-1)
				cout << set[i]<< " ";
		}

		cout << "\n";
		return;
	}

	for(int i = 1 ; i< 3; i++){
		
		if(i==1){ // include the current value

	       		int tmp_sum_so_far = sum_so_far + set[level];
			int tmp_remaining_sum = remaining_sum - set[level];

			if(tmp_sum_so_far + tmp_remaining_sum >= expected_sum && tmp_sum_so_far <= expected_sum){  // bounding function

				result[level] = 1;
		       		sum_of_subset(set, level+1, result, tmp_sum_so_far, tmp_remaining_sum, expected_sum);
			}
		}
		else{ // exclude current element

			int tmp_remaining_sum = remaining_sum - set[level];
			if(sum_so_far + tmp_remaining_sum >= expected_sum && sum_so_far <= expected_sum){
				result[level] = -1;
				sum_of_subset(set, level+1, result, sum_so_far, tmp_remaining_sum, expected_sum);
			}
		}
	}
}


int main(){


	vector<int> set = {5,10,12,13,15,18};

	vector<int> result (set.size(),-1);

	int remaining_sum = 0;
	for(int x : set){
		remaining_sum += x;
	}

	int expected_sum = 30;
	cout << "The given set is : \n";
       	for(int x : set){
		cout << x << " ";
	}
	cout << "\n";

	cout << "The expected sum is : " << expected_sum << "\n";	

	sum_of_subset(set, 0, result, 0, remaining_sum,expected_sum);

	return 0;
}

/*Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.
 
 https://www.geeksforgeeks.org/job-assignment-problem-using-branch-and-bound/

Here I am doing using backtarcting

    // x-cordinate represents a Worker
    // y-cordinate represents a Job
    int costMatrix[N][N] =
    {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };



 */

#include<iostream>
#include<vector>
using namespace std;

void find_min_cost(vector<vector<int>>cost_matrix, int level, vector<int> index, vector<int> jobs_assaign, vector<int> &sol_jobs_assaign,int curr_cost,int &min_cost){

		if(level == cost_matrix.size()){
			
			if(curr_cost < min_cost)
			{
				min_cost = curr_cost;
				sol_jobs_assaign = jobs_assaign;

			}
	 		

		      	return;
		}

		for(int i = 0; i < cost_matrix[level].size(); i++){

			if(curr_cost + cost_matrix[level][i] < min_cost && index[i] == 0 ){

				index[i]=1;
				int tmp_curr_cost = curr_cost + cost_matrix[level][i];
				jobs_assaign[level] = i;

				find_min_cost(cost_matrix, level+1, index, jobs_assaign,sol_jobs_assaign,tmp_curr_cost,min_cost);
				index[i] = 0; // backtrack
			}
		}
}


int main(){


	vector<vector<int>> cost_matrix = { {9, 2, 7, 8}, 
		                            {6, 4, 3, 7}, 
					    {5, 8, 1, 8}, 
					    {7, 6, 9, 4} };
	vector<int> index(4,0);
	vector<int>jobs_assaign(4,0);
	vector<int>sol_jobs_assaign(4,0);
	
	int min_cost = INT8_MAX;
	find_min_cost (cost_matrix,0,index,jobs_assaign,sol_jobs_assaign,0,min_cost);

	cout<< "Min Cost : " << min_cost << "\n";
	
	for(int w = 0; w <jobs_assaign.size(); w++){
		cout << "Worker : " << w << " " << "Job : " << jobs_assaign[w] << "\n";
	}
	
	return 0;
}

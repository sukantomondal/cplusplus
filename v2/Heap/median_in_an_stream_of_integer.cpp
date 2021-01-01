/* Median in a stream of integer */

/*Similar to balancing BST in Method 2 above, we can use a max heap on left side to represent elements that are less than effective median, and a min heap on right side to represent elements that are greater than effective median.

After processing an incoming element, the number of elements in heaps differ utmost by 1 element. When both heaps contain same number of elements, we pick average of heaps root data as effective median. When the heaps are not balanced, we select effective median from the root of heap containing more elements.
*/

#include<iostream>
#include<queue>
using namespace std;

class Stream {

	priority_queue<int> leftMaxQ; // hold values less than median // max heap
	priority_queue<int, vector<int>, greater<int> > rightMinQ; // holds values gereater than median // min heap
	double median;

	public:

	Stream() {
		median = 0;
	}

	double addNum(int num) {

		if (leftMaxQ.size() == rightMinQ.size()) {

			if(num > median) {
				rightMinQ.push(num);
				median = rightMinQ.top();
			} else {
				leftMaxQ.push(num);
				median = leftMaxQ.top();
			}
		}

		else if (leftMaxQ.size() > rightMinQ.size()) {

			if (num > median) { // can be placed in right side
				rightMinQ.push(num);
			} else {

				rightMinQ.push(leftMaxQ.top());
				leftMaxQ.pop();
				leftMaxQ.push(num);
			}
			median = (leftMaxQ.top() + rightMinQ.top())/2;

		}
		else if (leftMaxQ.size() < rightMinQ.size()) {

			if (num < median) {
				leftMaxQ.push(num);
			} else {

				leftMaxQ.push(rightMinQ.top());
				rightMinQ.pop();
				rightMinQ.push(num);
			}
			median = (leftMaxQ.top() + rightMinQ.top())/2;
		}

		return median;
	}

	double get_median() {
		return median;
	}
};




int main() {

	Stream st = Stream();

	//cout << st.get_median();

	vector <int> num = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};

	for (auto &n : num )
		cout << st.addNum(n) << " ";

	return 0;
}



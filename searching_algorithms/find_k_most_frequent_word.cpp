/* Author : Sukanto Mondal */


/*Find the k most frequent words  
 A simple solution is to use Hashing. Hash all words one by one in a hash table. If a word is already present, then increment its count. Finally, traverse through the hash table and return the k words with maximum counts.
*/


#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

typedef pair<int, string> whc; /// word heap content 

void print_array(vector<string> arr){

	for(int i = 0; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}


void print_k_most_frequent_word(vector<string> words, int k){

	priority_queue<whc> wc; // word count

	unordered_map<string, int> hcontainer;

	unordered_map<string,int> :: iterator it;

	for(int i = 0; i < words.size(); i++){	
		it = hcontainer.find(words[i]);

		if(it == hcontainer.end()){ // not found then insert			
			hcontainer.insert({words[i],1});
		}else{
			int w_occurence = ++(it->second);
			hcontainer.insert({words[i],w_occurence});
		}	
	}

	for (it = hcontainer.begin() ; it != hcontainer.end() ; ++it){
		//cout << it->first << " " << it->second << "\n";
		wc.push({it->second,it->first});
	}


	int count = 0;
	while(!wc.empty() && count < k){
		whc temp = wc.top();
		wc.pop();
		count ++;
		cout << temp.first << " " << temp.second << "\n";
	}
}
int main (){
	vector<string> words = {"Welcome","to","the","world","of","Geeks","This","portal","has","been","created","to","provide","well","written","well","thought","and","well","explained","solutions","for","selected","questions","If","you","like","Geeks","for","Geeks","and","would","like","to","contribute","here","is","your","chance","You","can","write","article","and","mail","your","article","to","contribute","at","geeksforgeeks","org","See","your","article","appearing","on","the","Geeks","for","Geeks","main","page","and","help","thousands","of","other","Geeks"};
	print_array(words);
	cout << "\n\nThe 7 most occuring words in the paragraph are: \n";
	print_k_most_frequent_word(words,7);
	return 0;

}

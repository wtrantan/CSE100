#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[9999], rev[9999], sequence;
vector< vector<int> > SCC;
bool visit[9999] = {false};


void DFS(vector<int> matrix[], vector<int> &sequence, int i){
	visit[i] = true;
	for(int j = 0; j < matrix[i].size(); j++){
		if(visit[matrix[i][j]]){ 
            int hi = 0;
        }else{
			DFS(matrix, sequence, matrix[i][j]);
		}
	}
	sequence.push_back(i);
}

void setFalse(int num){
	for(int i = 0; i < num; i++){
		visit[i] = false; 
	}
		
}

void graphing(int edges){
	int u;
    int v;
	for(int i = 0; i < edges; i++){
        std::cin >> u;
        std::cin >> v;  
		adj[u].push_back(v);
	}
}

void traverse(int num){
	for(int i = 0; i < num; i++){
		for(int j = 0; j < adj[i].size(); j++){
			rev[adj[i][j]].push_back(i);
		}
	}
}

void reverseTraverse(){
	for(int i = 0; i < sequence.size(); i++){
		if(!visit[sequence[i]]) {
			vector<int> component;
			DFS(rev, component, sequence[i]);
			SCC.push_back(component);
		}
	}
}

void output(int arr[],int num){
	for(int i = 0; i < num; i++){
		std::cout << arr[i] <<endl;
	}
}

int main(){
	int num;
    int edge; 
    int compare;

    std::cin >> num;
    std::cin >> edge;

	int arr[num];

	for(int i = 0; i < num; i++){
		arr[i] = i;
	}

	graphing(edge);

	for(int i = 0; i < num; i++){ 
		if(!visit[i]){
			DFS(adj, sequence, i);
		}
	}

	traverse(num);

	setFalse(num);

	reverse(sequence.begin(), sequence.end()); 
	
	reverseTraverse(); 

	for(int i = 0; i < SCC.size(); i++){
		for(int j = 0; j < SCC[i].size(); j++){
			compare = SCC[i][j];
			for(int k = 0; k < num; k++){
				if(arr[k] == compare){
					arr[k] = *min_element(SCC[i].begin(), SCC[i].end());
				}
			}
		}
	}

	output(arr, num);
	
	return 0;
}
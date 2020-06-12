#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>
#include <list>

using namespace std;

template<typename T>
class Graph{
	unordered_map<T,list<T>> adjList;
public:
	void addEdge(T u, T v, bool bidir){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void display() {

		for (auto node : adjList) {

			auto u = node.first;
			cout << u << "->";
			for (T val : node.second) {
				cout << val << " ,";
			}
			cout << endl;
		}
		cout << "**********************" << endl;
	}

	void bfs(T src){
		queue<T> q;
		unordered_map<T,bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty()){

			T node = q.front();
			q.pop();
			cout<<node<<",";

			for(T nbr:adjList[node]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
		cout<<endl;
	}	

	void bfsShortestPath(T src) {
		queue<T> q;
		unordered_map<T, int> dist;

		for (auto node : adjList) {

			T val = node.first;

			dist[val] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			for (T neighbor : adjList[node]) {
				if (dist[neighbor] == INT_MAX) {
					dist[neighbor] = 1 + dist[node];
					q.push(neighbor);
				}
			}
		}

		for (auto val : dist) {
			cout << val.first << " -> " << val.second << endl;
		}
	}

	int snakesAndLadders(T src, T dest) {
		
		queue<T> q;
		unordered_map<T, int> dist;
		unordered_map<T,T> parent;

		for (auto node : adjList) {

			T val = node.first;

			dist[val] = INT_MAX;
		}

		dist[src] = 0;
		parent[src] = src;
		q.push(src);

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			for (T neighbor : adjList[node]) {
				if (dist[neighbor] == INT_MAX) {
					dist[neighbor] = 1 + dist[node];
					parent[neighbor] = node;
					q.push(neighbor);
				}
			}
		}

		T temp = dest;
		while(temp != src){
			cout<<temp<<"<--";
			temp = parent[temp];
		}
		cout<<src<<endl;

		return dist[dest];
	}

	void dfsHelper(T src, unordered_map<T,bool> &visited){
		//Recursive function that will traverse the graph

		cout<<src<<" ";
		visited[src] = true;

		for(auto nbr:adjList[src]){
			if(!visited[nbr]){
				dfsHelper(nbr,visited);
			}
		}
	}

	void dfs(T src){
		unordered_map<T,bool> visited;
		for(auto val:adjList){
			int node = val.first;
			visited[node] = false;
		}
		dfsHelper(src,visited);
	}

	void allComponents(){
		unordered_map<T,bool> visited;

		for(auto val:adjList){
			int node = val.first;
			visited[node] = false;
		}

		int count = 0;

		for(auto val:adjList){
			int node = val.first;
			if(!visited[node]){
				dfsHelper(node,visited);
				count++;
			}
		}

		cout<<"Number of components: "<<count<<endl;
	}

	void topologicalSort(){

		unordered_map<T,int> indegree;
		queue<T> q;

		for(auto val:adjList){
			T node = val.first;
			indegree[node] = 0;
		}

		for(auto node:adjList){
			for(auto neighbor:node.second){
				indegree[neighbor]++;
			}
		}
		
		for(auto val:indegree){
			T node = val.first;
			int deg = val.second;

			if(deg == 0){
				q.push(node);
			}
		}

		while(!q.empty()){

			T node = q.front();
			cout<<node<<" ";
			q.pop();

			for(auto neighbor:adjList[node]){
				indegree[neighbor]--;
				if(indegree[neighbor] == 0){
					q.push(neighbor);
				}
			}
		}

		cout<<endl;
	}
};

int main(){

	// Graph<int> G;

	// G.addEdge(0,1,true);
	// G.addEdge(1,2,true);
	// G.addEdge(2,3,true);
	// G.addEdge(3,4,true);
	// G.addEdge(4,5,true);

	// G.bfs(0);

	// G.bfsShortestPath(0);

	// int board[50] = {0};

	// board[2] = 13;
	// board[5] = 2;
	// board[9] = 18;
	// board[18] = 11;
	// board[17] = -13;
	// board[20] = -14;
	// board[24] = -8;
	// board[25] = -10;
	// board[32] = -2;
	// board[34] = -22;

	// for(int i=0;i<=36;i++){
	// 	for(int dice=0;dice<=6;dice++){

	// 		int j = i + dice + board[i + dice];

	// 		if(j<=36){
	// 			G.addEdge(i,j,false);
	// 		}
	// 	}
	// }

	// cout<<"Min Dice Throws: "<<G.snakesAndLadders(0,36)<<endl;

	// G.dfs(0);

	// G.addEdge(1, 2,true);
	// G.addEdge(1, 4,true);
	// G.addEdge(3, 2,true);
	// G.addEdge(4, 3,true);
	// G.addEdge(3, 5,true);
	// G.addEdge(4, 5,true);

	// G.addEdge(6, 7,true);

	// G.addEdge(9, 10,true);
	// G.addEdge(8, 9,true);

	// G.allComponents();

	// Graph<string> G;

	// G.addEdge("English", "Programming", false);
	// G.addEdge("Maths", "Programming", false);
	// G.addEdge("Programming", "Java", false);
	// G.addEdge("Programming", "Python", false);
	// G.addEdge("Java", "Web", false);
	// G.addEdge("Python", "Web", false);

	// G.topologicalSort();

	return 0;
}
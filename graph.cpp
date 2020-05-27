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
	void addEdge(T u, T v){
		adjList[u].push_back(v);
		adjList[v].push_back(u);
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

	
};

int main(){

	Graph<int> G;

	G.addEdge(0,1);
	G.addEdge(1,2);
	G.addEdge(2,3);
	G.addEdge(3,4);
	G.addEdge(4,5);

	G.bfs(0);

	return 0;
}
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
	unordered_map<T, list<pair<T,int>>> m;
public:
	void addEdge(T u, T v,int dist,bool bidir=true){
		m[u].push_back({v,dist});
		if(bidir){
			m[v].push_back({u,dist});
		}
	}

	void printAdj(){
		for(auto val:m){
			cout<<val.first<<" -> ";

			for(auto val2:val.second){
				cout<<"("<<val2.first<<","<<val2.second<<")";
			}

			cout<<endl;
		}
	}

	void dijkstraSSSP(T src){
		unordered_map<T,int> dist;

		for(auto val:m){
			dist[val.first] = INT_MAX;
		}

		dist[src] = 0;

		set<pair<int,T>> s;

		s.insert({0,src});

		while(!s.empty()){

			auto p = *(s.begin());
			T node = p.second;
			int nodeDist = p.first;

			s.erase(s.begin());

			for(auto childPair:m[node]){

				if(nodeDist + childPair.second < dist[childPair.first]){

					T dest = childPair.first;
					auto f = s.find({dist[dest],dest});

					if(f != s.end()){
						s.erase(f);
					}

					dist[dest] = nodeDist + childPair.second;
					s.insert({dist[dest],dest});
				}
			}
		}

		for(auto d:dist){
			cout<<d.first<<" is located at a distance of "<<d.second<<endl;
		}
	}
};

int main(){

	Graph<string> india;
	india.addEdge("Amritsar","Delhi",1);
	india.addEdge("Amritsar","Jaipur",4);
	india.addEdge("Jaipur","Delhi",2);
	india.addEdge("Jaipur","Mumbai",8);
	india.addEdge("Bhopal","Agra",2);
	india.addEdge("Mumbai","Bhopal",3);
	india.addEdge("Agra","Delhi",1);
	// india.printAdj();
	india.dijkstraSSSP("Amritsar");


	return 0;
}
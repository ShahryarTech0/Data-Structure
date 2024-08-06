#include<iostream>
#include<list>
#include <queue>
#include<unordered_map>
using namespace std;
class Graph{
	int vertex;
	unordered_map<int,list<int>> adj;
	public:
		Graph(int vertex){
			this->vertex=vertex;
		}
		void AddEdges(int u,int v){
			adj[u].push_back(v);
		}
		void BFS(int startingvertex){
			unordered_map<int,bool> visited;
			for(int i=0;i<vertex;i++){
				visited[i]=false;
			}
			queue<int> q;
			visited[startingvertex]=true;
			q.push(startingvertex);
			while(!q.empty()){
				int currentvertex=q.front();
				cout<<currentvertex<<" ";
				q.pop();
				for(int adjacentvertex : adj[currentvertex]){
					if(!visited[adjacentvertex]){
						visited[adjacentvertex]=true;
						q.push(adjacentvertex);
					}
				}
			}
		}
};
int main(){
	int vertex,edges;
	cout<<"Enter the number of vertex: ";
	cin>>vertex;
	cout<<"Enter the number of edges: ";
	cin>>edges;
	
	Graph g(vertex);
	cout<<"Enter the edges format(u v): ";
	for(int i=0;i<edges;i++){
		int u,v;
		cin>>u >>v;
		g.AddEdges(u,v);
	}
	int startingvertex;
	cout<<"Enter the starting vertex of BFS: ";
	cin>>startingvertex;
	cout<<"The starting vertex of BFS is: ";
	g.BFS(startingvertex);
	return 0;
}

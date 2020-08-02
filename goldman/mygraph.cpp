#include<bits/stdc++.h>//adjecent list 
using namespace std;
//for edge directed
void oneway(vector <int> adj[], int a, int b){//a is source and b is destination
    adj[a].push_back(b);
}
//if not edge directed
void join(vector <int> adj[], int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
//weighted and one directed
void weight(vector <pair<int,int>> adj[N], int a, int b, int w){
    adj[a].push_back({b,w});
}
int main(){
    int N;//number of nodes
    vector <int> adj[N];//adjecent list 
    //for weighted graph
    vector <pair<int,int>> adj[N];
    //process node u
    for(auto u: adj[s]){//0<s<=N
        //this loop goes from all nodes which we can move from node s.
    }
    return 0;
}
//Graph implementation using adjacency matrix
#include <iostream>
using namespace std;
void join(int* adj[], int a, int b){
    adj[a][b]=1;
    return 0;
}
// for weighted
void wjoin(int* adj[], int a, int b, int w){
    adj[a][b]=w;
    return 0;
}
int main() {
    int adj[N][N];
    //input
	return 0;
}
// can not be used if graph is large
// space complexity is n^2


//Graph implementation using edge list
#include <iostream>
using namespace std;
void makedge(vector<pair<int, int>> edges, int a, int b){
    edges.push_back({a,b});
    return 0;
}
// for weighted
void makewedge(vector<tuple<int, int>> edges, int a, int b, int w){
    edges.push_back({a,b,w});
    return 0;
}
int main() {
    vector<pair<int, int>> edges;
    vector<tuple<int, int>> edges;
    //input
	return 0;
}
// --------------continue----------
#include <iostream>
using namespace std;

int main() 
{
    int w=INF;
    queue<int> q;
    // Weight (or distance) is used used as first item  of pair
	// as first item is by default used to compare two pairs
    queue.push(adj[0][0]);
    adj[0][0]=0;
    //Insert source vertex into pq and make its distance as 0.
    while(!q.empty()){
    // While either pq doesn't become empty
    // a) Extract minimum distance vertex from pq. 
    // Let the extracted vertex be u.
        queue.push()
    }
	return 0;
}

// void Graph::addEdge(int u, int v, int w) 
// { 
// 	adj[u].push_back(make_pair(v, w)); 
// 	adj[v].push_back(make_pair(u, w)); 
// } 

class Graph 
{ 
	int V; // No. of vertices 

	// In a weighted graph, we need to store vertex 
	// and weight pair for every edge 
	list< pair<int, int> > *adj; 

public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int u, int v, int w); 

	// prints shortest path from s 
	void shortestPath(int s); 
}; 

// Allocates memory for adjacency list 
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<iPair> [V]; 
} 

// Prints shortest paths from src to all other vertices 
void Graph::shortestPath(int src) 
{ 
	// Create a priority queue to store vertices that 
	// are being preprocessed. This is weird syntax in C++. 
	// Refer below link for details of this syntax 
	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/ 
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

	// Create a vector for distances and initialize all 
	// distances as infinite (INF) 
	vector<int> dist(V, INF); 

	// Insert source itself in priority queue and initialize 
	// its distance as 0. 
	pq.push(make_pair(0, src)); 
	dist[src] = 0; 

	/* Looping till priority queue becomes empty (or all 
	distances are not finalized) */
	while (!pq.empty()) 
	{ 
		// The first vertex in pair is the minimum distance 
		// vertex, extract it from priority queue. 
		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted distance (distance must be first item 
		// in pair) 
		int u = pq.top().second; 
		pq.pop(); 

		// 'i' is used to get all adjacent vertices of a vertex 
		list< pair<int, int> >::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
		{ 
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = (*i).first; 
			int weight = (*i).second; 

			// If there is shorted path to v through u. 
			if (dist[v] > dist[u] + weight) 
			{ 
				// Updating distance of v 
				dist[v] = dist[u] + weight; 
				pq.push(make_pair(dist[v], v)); 
			}
		}
	}
}
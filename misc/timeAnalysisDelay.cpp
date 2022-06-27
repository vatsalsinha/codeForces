// A C++ program to find single source longest distances
// in a DAG
#include <iostream>
#include <limits.h>
#include <list>
#include <stack>
#include<bits/stdc++.h>
#define NINF INT_MIN
using namespace std;

// Graph is represented using adjacency list. Every
// node of adjacency list contains vertex number of
// the vertex to which edge connects. It also
// contains weight of the edge
class AdjListNode {
	int v;
	float weight;

public:
	AdjListNode(int _v, float _w)
	{
		v = _v;
		weight = _w;
	}
	int getV() { return v; }
	float getWeight() { return weight; }
};

// Class to represent a graph using adjacency list
// representation
class Graph {
	int V; // No. of vertices'

	// Pointer to an array containing adjacency lists
	list<AdjListNode>* adj;

	// A function used by longestPath
	void topologicalSortUtil(int v, bool visited[],
							stack<int>& Stack);

public:
	Graph(int V); // Constructor
	~Graph(); // Destructor

	// function to add an edge to graph
	void addEdge(int u, int v, float weight);

	// Finds longest distances from given source vertex
	void longestPath(int s, double &max_distance, int &end, int &source);
	void dfs(int curNode, int lastNode, vector<int>& res, vector<vector<int>> & ans);
	double sumWeights(vector<int> vec);
	float getWt(int s, int e);
};

Graph::Graph(int V) // Constructor
{
	this->V = V;
	adj = new list<AdjListNode>[V];
}

Graph::~Graph() // Destructor
{
	delete [] adj;
}


void Graph::addEdge(int u, int v, float weight)
{
	AdjListNode node(v, weight);
	adj[u].push_back(node); // Add v to u's list
}

// A recursive function used by longestPath. See below
void Graph::topologicalSortUtil(int v, bool visited[],
								stack<int>& Stack)
{
	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<AdjListNode>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {
		AdjListNode node = *i;
		if (!visited[node.getV()])
			topologicalSortUtil(node.getV(), visited, Stack);
	}

	// Push current vertex to stack which stores topological
	// sort
	Stack.push(v);
}

// The function to find longest distances from a given vertex.
// It uses recursive topologicalSortUtil() to get topological
// sorting.
void Graph::longestPath(int s, double &max_distance, int &end, int &source)
{
	stack<int> Stack;
	float dist[V];

	// Mark all the vertices as not visited
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to store Topological
	// Sort starting from all vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// Initialize distances to all vertices as infinite and
	// distance to source as 0
	for (int i = 0; i < V; i++)
		dist[i] = NINF;
	dist[s] = 0;
	// Process vertices in topological order
	while (Stack.empty() == false) {
		// Get the next vertex from topological order
		int u = Stack.top();
		Stack.pop();
        vector<int> v;
		// Update distances of all adjacent vertices
		list<AdjListNode>::iterator i;
		if (dist[u] != NINF) {
			for (i = adj[u].begin(); i != adj[u].end(); ++i){
			
				if (dist[i->getV()] < dist[u] + i->getWeight()){
				    //cout<<i->getV()<<"-";
				    v.push_back(i->getV());
					dist[i->getV()] = dist[u] + i->getWeight();
				}
			}
		}
	}
    cout<<"\t";
	// get the longest distance and endpoint from source
	
	for (int i = 1; i < V; i++){
		//(dist[i] == NINF) ? cout << "INF " : cout << dist[i] << " ";
		if(dist[i] > max_distance){
		    max_distance = dist[i];
		    end = i;
		    source = s;
		}
	}
	delete [] visited;
}
void Graph::dfs(int curNode, int lastNode, vector<int>& res,     vector<vector<int>> & ans){
    // depth first search to get all possible paths from current node to end node
    res.push_back(curNode);
    if(curNode == lastNode){
        ans.push_back(res);
        return;
    }
    list<AdjListNode>::iterator node;
    for(node = adj[curNode].begin(); node != adj[curNode].end(); ++node){
        dfs(node->getV(), lastNode, res, ans);
        res.pop_back();
    }
}

float Graph::getWt(int s, int e){
    // get weight of edges
    list<AdjListNode>::iterator node;
    for(node = adj[s].begin(); node != adj[s].end(); ++node){
        if(node->getV() == e)
            return node->getWeight();
    }
}

double Graph::sumWeights(vector<int> vec){
    // returns total weight of the path
    double sum = 0;
    for(int i = 0, j = 1; i < vec.size() && j < vec.size(); i++, j++){
        sum += getWt(vec[i], vec[j]);
    }
    return sum;
}


// Driver program to test above functions
int main()
{
	// Create a graph given in the above diagram.
	// Here vertex numbers are 0, 1, 2, 3, 4, 5 with
	// following mappings:
	// 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
	int n, edges;
	cout<<"Enter number of cells\n";
	cin>>n;
	cout<<"Enter number of edges\n";
	cin>>edges;
	Graph g(n+1);
	for(int i = 0; i < edges; i++){
	    int start, end;
	    float delay;
	    cout<<"enter start "; 
	    cin>>start;
	    cout<<"\tenter end ";
	    cin>>end;
	    cout<<"\tenter delay ";
	    cin>>delay;
	    cout<<"\n";
    	g.addEdge(start, end, delay);
	}
	
	double max_distance = INT_MIN;
	int end = 0;
	int source = 0;
	for(int i = 1; i <= n; i++){
    	int s = i;
    	g.longestPath(s, max_distance, end, source);
	}
	cout<<"max distance is "<<max_distance<<"\n";
	cout<<"path=\n";
	vector<int> res;
	vector<vector<int>> ans;
    g.dfs(source,end,res, ans);
    for(auto v : ans){
        if(g.sumWeights(v) == max_distance){
            for(auto n : v)
                cout<<n<<"-";
        }
    }
	return 0;
}

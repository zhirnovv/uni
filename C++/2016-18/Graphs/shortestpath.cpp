/**
 * Author:      Asif Ahmed
 * Site:        http://quickgrid.blogspot.com
 * Description: C++ easy Graph BFS Traversal with shortest path finding for
 * undirected graphs and shortest path retracing thorough parent nodes.
 */
#include <iostream>
#include <list>
#include <queue>
using namespace std;
// I have used this value as Infinite since I assume a graph
// larger than this won't be tested on this code. Rather other
// standard libraries should be used.
const int INF = 999;
// Create the class for graph and define necessary properties and functions.
// adjList is stores the whole adjacency list structure as shown in the books.
// See my other post on graph for visual representation and other ways.
// addEdge function connects an edge u with another edge v.
class Graph {
private:
  int V;
  vector<list<int>> adjList;

public:
  Graph(int const &V);
  void addEdge(int const &u, int const &v);
  void BFS(int const &s);
};
// Initialize the graph with node count and scale the adjacency list with node
// count.
Graph::Graph(int const &V) {
  this->V = V;
  adjList.resize(V);
}
// Go to the (u) th vector position then add v to the linked list.
void Graph::addEdge(int const &u, int const &v) { adjList[u].push_back(v); }
// Find path though the graph from a given node to another.
// If start and end node are same then nothing to do just print that node.
// Else
void findPath(int const &startNode, int const &endNode, int *&parent) {
  if (startNode == endNode || endNode == -1) {
    printf("%d\n", startNode);
  } else {
    findPath(startNode, parent[endNode], parent);
    printf("%d\n", endNode);
  }
}
// Performs BFS on given node, also prints distance array and parent array.
// Set distance array to infinite for all nodes and parent to -1. Set distance
// of parent node to zero and push to the queue. Take it out of queue and push
// all the reachable nodes from current node to queue.
// Also set the distance of the current node as the distance of its parent node
// plus one assuming all the distances are one instead of another same value.
// Set parent of current node to the node that was taken out of queue.
void Graph::BFS(int const &s) {
  int *dist = new int[V];
  int *parent = new int[V];
  for (int v = 0; v < V; ++v) {
    dist[v] = INF;
    parent[v] = -1;
  }
  dist[s] = 0;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    cout << u << " ";
    list<int>::iterator it;
    for (it = adjList[u].begin(); it != adjList[u].end(); ++it) {
      if (dist[*it] == INF) {
        Q.push(*it);
        dist[*it] = dist[u] + 1;
        parent[*it] = u;
      }
    }
  }
  // Print all the reachable nodes with distance from current nodes.
  printf("\n");
  for (int v = 0; v < V; ++v) {
    if (dist[v] != INF) {
      cout << s << v << endl;
    } else {
      cout << -1;
    }
  }
  // Print the parent array.
  for (int v = 0; v < V; ++v) {
    cout << "parent of" <<  v << ':' << parent[v];
  }
  // Try to find the shortest path from current node to another.
  // This can be modified based on need. Return the vector or
  // array from here to main in order to call function from there.
  int node;
  cin >> node;
  if (dist[node] != INF)
    findPath(s, node, parent);
  else
    cout << -1;
}
int main() {
  //
  int n;
  cin >> n;
  // Create a graph given in the above diagram
  Graph *g = new Graph(n);
  // For inputting undirected graph either uncomment below or,
  // create Edges pointing from (u,v) and (v,u)
  int u, v;

  while (cin >> u >> v) {
    g->addEdge(u, v);
    // g->addEdge(v,u);
  }
  // Run DFS on graph
  cout << "Breadth First Search Traversal: \n";
  int node;
  cin >> node;
  g->BFS(node);
  return 0;
}

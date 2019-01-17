#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

class Graph
{
    vector< vector<int> > Edge;
    vector<unsigned char> visited;
public:

    Graph(int V)
    {
        Edge.resize(V);
        visited.resize(V);
    }

    void add_edge(int v,int w)
    {
        Edge[v].push_back(w);
    }

    void BFS(int s)
    {
        for(auto i : visited)
          i = false;
        list<int> q;
        visited[s] = true;
        q.push_back(s);
        while (!q.empty())
        {
            s = q.front();
            cout<<s<<" ";
            q.pop_front();
            for(auto i : Edge[s])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push_back(i);
                }
            }
        }

    }

    void DFSUtil(int s, bool visited[])
    {
      // Mark the current node as visited and print it
      visited[s] = true;
      cout << s << " ";

      // Recur for all the vertices adjacent to this vertex
      list<int>iterator i;
      for (auto i : Edge[s])
          if (!visited[*i])
              DFSUtil(*i, visited);
    }

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
    void DFS(int v)
    {
    // Mark all the vertices as not visited
      bool *visited = new bool[V];
      for (int i = 0; i < V; i++)
          visited[i] = false;

    // Call the recursive helper function to print DFS traversal
      DFSUtil(v, visited);
    }
};

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    Graph g(vertices);
    for(int i=0; i < edges; i++)
    {
      int start, end;
      cin >> start >> end;
      g.add_edge(start, end);
    }
    int s;
    cin >> s;
    cout << "BFS:" << endl;
    g.BFS(s);
    cout << endl;
    cout << "DFS:" << endl;
    g.DFS(s);
    return 0;
}

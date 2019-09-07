#include<iostream>
#include<list>

using namespace std;


class Graph
{
    int V;    //Количество вершин
    list<int> *adj; //Список смежности
    void DFSUtil(int v, bool visited[]);//Основная функция
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);   //Вспомогательная функция
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{
    //Отмечаем начальную вершину как посещенную и выводим ее
    visited[v] = true;
    cout << v << " ";

    //Рекурсия для каждой соседней вершины до конца графа
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
    //Отмечаем все вершины как непосещенные
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(v, visited);
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    Graph g(vertices);
    for(int i=0; i < edges; i++)
    {
      int start, end;
      cin >> start >> end;
      g.addEdge(start, end);
    }

    int s;
    cin >> s;

    g.DFS(s);

    return 0;
}

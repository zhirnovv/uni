#include<iostream>
#include <list>

using namespace std;

class Graph
{
    int V;    //Количество вершин
    list<int> *adj;    //Список смежности
public:
    Graph(int V);  //Конструктор
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    //Отмечаем все вершнины как непосещенные
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    //Создаем очередь для обхода вершин
    list<int> queue;

    //Отмечаем начальную вершину как посещенную и добавляем ее в очередь
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty())
    {
        //Извлекаем вершину из очереди и выводим её
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        //Добавляем в очередь все соседние вершины
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
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

    g.BFS(s);

    return 0;
}

#include <iostream>
using namespace std;

void graph_list(int **graph, int **list, int n);

void dfs_matr(int v, int n, int *used, int **graph);

void dfs_list(int v, int n, int *used, int **list, int **graph);

int main()
{
  int m, n, i, a, b, j;
  cout << "Количество вершин: " << endl;
  cin >> n; //вершин
  cout << "Количество рёбер: " << endl;
  cin >> m; //ребер
  int **graph = new int*[n];
  int *used = new int[n];
  int **list = new int*[n];
  for (i = 0; i < n; i++)
  {
    graph[i] = new int[n];
  }
  for (i = 0; i < n; i++)
  {
    list[i] = new int[n+1];
  }
  for (i = 0; i < n; i++)
  {
      used[i] = 0;
  }
  for(i = 0; i < m; i++) //матрица смежности графа
  {
    cin >> a;
    cin >> b;
    graph[a - 1][b - 1] = 1;
    graph[b - 1][a - 1] = 1;
  }
  graph_list(graph, list, n);
  cout << "Список смежных рёбер:" << endl;
  cout << "№ |ст:|"<< endl;
  for(i = 0; i < n; i++)
  {
    cout << i << " | " << list[i][0] << " | ";
    for(j = 1; j < n+1; j++)
    {
        //if(list[i][j] != 0)
       // {
            cout << list[i][j] << " ";
        //}
    }
    cout << endl;
  }
  //dfs_matr(0, n, used, graph);
  dfs_list(0, n, used, list, graph);
  return 0;
}

void graph_list(int **graph, int **list, int n)
{

  int sum, i, j;
  for(i = 0; i < n; i++)
  {
    sum = 0;
    for(j = 0; j < n; j++)
    {
        if(graph[i][j] == 1)
        {
            list[i][j+1] = j + 1;
        }
        else
        {
            list[i][j+1] = 0;
        } 
        sum += graph[i][j];
    }
    list[i][0] = sum;
  }
}

void dfs_matr(int v, int n, int *used, int **graph) 
{
    int i;
    used[v] = 1;
    cout << "Посещена вершина " << v + 1 << endl;
    for(i = 0; i < n; i++)
        cout << used[i] << " ";
    cout << endl;
    cout << "   Ищем соседа вершины " << v + 1 << endl;
    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !used[i]) 
        {
            dfs_matr(i, n, used, graph);
        }
    }
    cout << "       Соседей у вершины " << v + 1 << " не осталось" <<  endl;
}

void dfs_list(int v, int n, int *used, int **list, int **graph)
{
    int i, next;
    used[v] = 1;
    cout << "Посещена вершина " << v + 1 << endl;
    for(i = 0; i < n; i++)
        cout << used[i] << " ";
    cout << endl;
    cout << "   Ищем соседа вершины " << v + 1 << endl;
    for (i = 1; i < n; i++)
    {
        next = list[v][i];
        if (used[next] == 0)
        {
            dfs_list(next, n, used, list, graph);
        }
    }
    cout << "       Соседей у вершины " << v + 1 << " не осталось" <<  endl;
}
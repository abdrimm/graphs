#include <iostream>
using namespace std;

void get_graph_matr(int **graph, int n, int m)
{
  int a, b, i, j;
  for(i = 0; i < m; i++)
  {
    cin >> a;
    cin >> b;
    graph[a - 1][b - 1] = 1;
    graph[b - 1][a - 1] = 1;
  }
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
        cout << graph[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void graph_list(int **graph, int n, int m)
{

  int sum, i, j;
  for(i = 0; i < n; i++)
  {
    sum = 0;
    for(j = 0; j < n; j++) {
        if(graph[i][j] == 1)
            cout << j + 1 << " ";
        sum += graph[i][j];
    }
    cout << ": " << "deg(вершина-" << i + 1 << ") = " << sum << endl;
  }
}

int main()
{
  int **graph, m, n, i;
  cin >> n; //вершин
  cin >> m; //ребер
  graph = new int*[n];
  for (i = 0; i < n; i++)
  {
    graph[i] = new int[n];
  }
  get_graph_matr(graph, n, m);
  graph_list(graph, n, m);
  return 0;
}
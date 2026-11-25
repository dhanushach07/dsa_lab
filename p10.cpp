#include <iostream>
#include <queue>
using namespace std;

int adj[10][10];
int visited[10];

void DFS(int start, int n)
{
    cout << start << " ";
    visited[start] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (adj[start][i] == 1 && !visited[i])
            DFS(i, n);
    }
}

void BFS(int start, int n)
{
    int visited2[10] = {0};
    queue<int> q;

    q.push(start);
    visited2[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 1; i <= n; i++)
        {
            if (adj[node][i] == 1 && !visited2[i])
            {
                visited2[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n, edges;

    cout << "Enter no of cities: ";
    cin >> n;

    cout << "Enter no of directed edges: ";
    cin >> edges;

    cout << "Enter edges (u,v):\n";

    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    int start;
    cout << "Enter starting city: ";
    cin >> start;

    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    cout << "\nDFS: ";
    DFS(start, n);

    cout << "\nBFS: ";
    BFS(start, n);

    return 0;
}
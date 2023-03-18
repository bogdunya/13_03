#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 100; // максимальное количество вершин в графе
vector<int> graph[MAXN]; // список смежности для графа
bool visited[MAXN]; // флаги посещения вершин
int distantion[MAXN]; // расстояния до каждой вершины

void first_commin_in_my_branch(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < graph[v].size(); i++) {
            int u = graph[v][i];
            if (!visited[u]) {
                visited[u] = true;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start, end;
    cin >> start >> end;

    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    bfs(start);

    return 0;
}

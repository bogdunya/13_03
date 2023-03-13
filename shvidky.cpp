#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
//FIRST COMMIT IN A MAIN
const int MAXN = 100; // максимальное количество вершин в графе
vector<int> graph[MAXN]; // список смежности для графа
bool visited[MAXN]; // флаги посещения вершин
int dist[MAXN]; // расстояния до каждой вершины

void first_IN_main(int start) {
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

    if (dist[end] == -1) {
        cout << "Нет пути из " << start << " в " << end << endl;
    } else {
        cout << "Кратчайший путь из " << start << " в " << end << " равен " << dist[end] << endl;
    }

    return 0;
}

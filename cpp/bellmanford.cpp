#include <iostream>
#include <vector>

std::vector<int> bellmanFord(int V, std::vector<std::vector<int>> &edges, int src) {
	std::vector<int> dist(V, 1e8);
	dist[src] = 0;
  
	for (int i = 0; i < V; i++) {
		for (std::vector<int> edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                if(i == V - 1) return {-1};
                dist[v] = dist[u] + wt;
            }
		}
	}

    return dist;
}

int main() {
    int V = 5;
    std::vector<std::vector<int>> edges = {
        {1, 3, 2}, 
        {4, 3, -1},
        {2, 4, 1}, 
        {1, 2, 1},
        {0, 1, 5} 
    };
    int src = 0;
    std::vector<int> ans = bellmanFord(V, edges, src);
    for (int dist : ans) 
        std::cout << dist << " ";

    return 0; 
}
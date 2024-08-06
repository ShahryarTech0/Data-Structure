#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int numNodes = 6;  // Total number of nodes in the graph

int dijkstra(const vector<vector<int> >& graph, int start, int end) {
    vector<int> dist(numNodes, numeric_limits<int>::max());  // Initialize distances to a large value
    vector<bool> visited(numNodes, false);  // Keep track of visited nodes
    dist[start] = 0;  // Distance from start node to itself is 0

    for (int i = 0; i < numNodes - 1; ++i) {
        int minDist = numeric_limits<int>::max();
        int minIndex = -1;

        // Find the node with the minimum distance from the set of unvisited nodes
        for (int j = 0; j < numNodes; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minIndex = j;
            }
        }

        if (minIndex == -1)
            break;

        visited[minIndex] = true;

        // Update the distances of neighboring nodes
        for (int j = 0; j < numNodes; ++j) {
            if (!visited[j] && graph[minIndex][j] != -1 &&
                dist[minIndex] != numeric_limits<int>::max() && dist[minIndex] + graph[minIndex][j] < dist[j]) {
                dist[j] = dist[minIndex] + graph[minIndex][j];
            }
        }
    }

    return dist[end];
}

int main() {
    vector<vector<int> > graph(numNodes, vector<int>(numNodes, -1));  // Initialize graph with -1 (representing absence of edge)
    graph[0][1] = 7;
    graph[0][2] = 9;
    graph[0][5] = 14;
    graph[1][2] = 10;
    graph[1][3] = 15;
    graph[2][3] = 11;
    graph[2][5] = 2;
    graph[3][4] = 6;
    graph[4][5] = 9;

    int start = 1;  // Node B
    int end = 4;    // Node E

    int shortestPath = dijkstra(graph, start, end);
    cout << "Shortest path from B to E: " << shortestPath << endl;

    return 0;
}


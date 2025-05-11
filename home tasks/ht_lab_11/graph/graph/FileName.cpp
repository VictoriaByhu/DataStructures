#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int SIZE = 4;

int graph[SIZE][SIZE] = {
    {0, 0, 4, 0},
    {0, 0, 6, 3},
    {4, 6, 0, 7},
    {0, 3, 7, 0}
};

bool is_full_graph() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (i != j && graph[i][j] == 0)
                return false;
    return true;
}

void print_adjacency_list() {
    cout << "Adjacency list:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << i << ": ";
        for (int j = 0; j < SIZE; ++j)
            if (graph[i][j] != 0)
                cout << j << " ";
        cout << endl;
    }
}

double average_path_length() {
    int total = 0, count = 0;
    for (int i = 0; i < SIZE; ++i)
        for (int j = i + 1; j < SIZE; ++j)
            if (graph[i][j] != 0) {
                total += graph[i][j];
                count++;
            }
    return count ? static_cast<double>(total) / count : 0;
}

vector<int> find_isolated_nodes() {
    vector<int> isolated;
    for (int i = 0; i < SIZE; ++i) {
        int connections = 0;
        for (int j = 0; j < SIZE; ++j)
            if (graph[i][j] != 0)
                connections++;
        if (connections <= 1)
            isolated.push_back(i);
    }
    return isolated;
}

void nearest_neighbor(int node, int& nearest, int& distance) {
    int min_dist = INF;
    nearest = -1;
    for (int j = 0; j < SIZE; ++j) {
        if (j != node && graph[node][j] != 0 && graph[node][j] < min_dist) {
            min_dist = graph[node][j];
            nearest = j;
        }
    }
    distance = min_dist;
}

void find_max_path_from_isolated(const vector<int>& isolated) {
    int max_sum = -1;
    vector<int> result;

    for (int iso : isolated) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (iso != i && i != j && iso != j) {
                    int first_weight = -INF;
                    if (graph[iso][i] != 0)
                        first_weight = graph[iso][i];

                    int second_weight = -INF;
                    if (graph[i][j] != 0)
                        second_weight = graph[i][j];

                    int sum = first_weight + second_weight;
                    if (sum > max_sum) {
                        max_sum = sum;
                        result = { iso, i, j };
                    }
                }
            }
        }
    }

    if (!result.empty()) {
        cout << "Maximum path: (" << result[0] + 1 << ") --- "
            << graph[result[0]][result[1]] << " --- (" << result[1] + 1 << ") --- "
            << graph[result[1]][result[2]] << " --- (" << result[2] + 1 << ")\n";
    }
}

bool hamiltonian_util(int pos, vector<bool>& visited, int count) {
    if (count == SIZE)
        return true;
    for (int i = 0; i < SIZE; ++i) {
        if (!visited[i] && graph[pos][i] != 0) {
            visited[i] = true;
            if (hamiltonian_util(i, visited, count + 1))
                return true;
            visited[i] = false;
        }
    }
    return false;
}

bool has_hamiltonian_path() {
    for (int i = 0; i < SIZE; ++i) {
        vector<bool> visited(SIZE, false);
        visited[i] = true;
        if (hamiltonian_util(i, visited, 1))
            return true;
    }
    return false;
}

int main() {
    cout << (is_full_graph() ? "Graph is full" : "Graph is not full") << endl;

    print_adjacency_list();

    cout << fixed << setprecision(2);
    cout << "Average path length: " << average_path_length() << endl;


    vector<int> isolated = find_isolated_nodes();
    if (!isolated.empty()) {
        cout << "Isolated nodes:\n";
        for (int node : isolated) {
            int near, dist;
            nearest_neighbor(node, near, dist);
            cout << node << " Nearest to " << near << " at distance " << dist << endl;
        }
        cout << "Number of isolated nodes: " << isolated.size() << endl;
        find_max_path_from_isolated(isolated);
    }
    else {
        cout << "No isolated nodes\n";
    }

    cout << (has_hamiltonian_path() ?
        "It is possible to visit all nodes only once" :
        "It is not possible to visit all nodes only once") << endl;

    return 0;
}

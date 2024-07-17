#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


//Function to verify whether a non-increasing array is a valid degree sequence
bool Erdos_Gallai(vector<int>& degree_sequence) {
    int n = degree_sequence.size();
    int sum_degree = 0;

    for (int i = 0; i < n; ++i) {
        sum_degree += degree_sequence[i];

        int left_hand_side = i * (i + 1);
        int right_hand_side = 0;

        for (int j = 0; j <= i; ++j) {
            right_hand_side += min(degree_sequence[j], i);
        }

        if (left_hand_side > sum_degree + right_hand_side)
            return false;
    }

    return sum_degree % 2 == 0;
}

/*sum_of_degree = 0 
* degree_sequence
  for each degree of vertex in degree_sequence{
        //Check condition i:
        sum_degree += degree_sequence[i];

        //Check condition 2:
        right_side_equallity = 0
        for every k from 1 to i

  }

        
        
        */

//Function to construct a simple graph from a given degree sequence
vector<vector<int>> Havel_Hakimi(vector<int>& degree_sequence) {
    int n = degree_sequence.size();
    vector<pair<int, int>> degree_pairs;

    // Create pairs of vertices and degrees
    for (int i = 0; i < n; ++i) {
        degree_pairs.push_back({ degree_sequence[i], i });
    }

    // Sort in non-increasing order
    sort(degree_pairs.rbegin(), degree_pairs.rend());

    // Havel-Hakimi algorithm
    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        int v = degree_pairs[i].second;
        for (int j = i + 1; j < i + 1 + degree_pairs[i].first; ++j) {
            int u = degree_pairs[j].second;
            graph[v][u] = 1;
            graph[u][v] = 1;
            degree_pairs[j].first--;
        }
    }

    return graph;
}

void solve(vector<int>& degree_sequence, ofstream& out) {
    if (!Erdos_Gallai(degree_sequence))
        out << "IMPOSSIBLE" << endl;
    else {
        // Construct and output the graph
        vector<vector<int>> graph = Havel_Hakimi(degree_sequence);

        int n = graph.size();
        out << n << endl;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                out << graph[i][j] << " ";
            }
            out << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " Input.dat Output.res" << endl;
        return 1;
    }

    ifstream in(argv[1]);
    ofstream out(argv[2]);

    if (!in.is_open() || !out.is_open()) {
        cout << "Error opening files." << endl;
        return 1;
    }

    vector<int> degree_sequence;
    int degree;

    // Read input degree sequence
    while (in >> degree) {
        degree_sequence.push_back(degree);
    }

    // Verify degree sequence
    solve(degree_sequence, out);
    

    in.close();
    out.close();

    return 0;
}


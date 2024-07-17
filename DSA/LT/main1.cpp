#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Function to read input from a file
vector<int> ReadFile(string& filename) {
    vector<int> result;
    ifstream infile(filename);
    int num;

    while (infile >> num) {
        result.push_back(num);
    }
    infile.close();
    return result;
}

// Function to check if a given sequence is a valid degree sequence using Erdős-Gallai theorem
bool ErdosGallaiTheorem(const vector<int>& sequence) {
    size_t n = sequence.size();
    int sum = 0;

    // Calculate the sum of the degrees
    for (int i = 0; i < n; i++) {
        sum += sequence[i];
    }

    // Check the conditions of Erdős-Gallai theorem
    if (sum % 2 != 0)
        return false; // Sum must be even

    int prefixSum = 0;
    for (int k = 1; k <= n; k++) {
        prefixSum += sequence[k - 1];

        int leftSide = k * (k - 1);
        int rightSide = k * min(sequence[k - 1], k);

        if (prefixSum > leftSide + rightSide)
            return false;
    }
    return true;
}

// Function to construct a graph using Havel-Hakimi algorithm
bool HavelHakimiAlgorithm(vector<vector<int>>& adjMatrix, vector<int>& sequence) {
    size_t n = sequence.size();

    // Sort the sequence in non-increasing order
    sort(sequence.begin(), sequence.end(), greater<int>());

    // Check if the sequence is a valid degree sequence
    if (!ErdosGallaiTheorem(sequence))
        return false;

    // Construct the adjacency matrix using the Havel-Hakimi algorithm
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= sequence[i]; j++)
        {
            if (i + j < n) {
                adjMatrix[i][i + j] = 1;
                adjMatrix[i + j][i] = 1;
                sequence[i + j]--;
            }
            else
                return false; // Invalid sequence
        }
    }

    sequence.erase(sequence.begin());

    return true;
}



int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " Input.dat Output.res" << endl;
        exit(1);
    }

    string inputFile = argv[1];
    string outputFile = argv[2];

    // Create file to store output
    ofstream writer(outputFile);
    
    // Read the input sequence
    vector<int> degreeSequence = ReadFile(inputFile);
    size_t n = degreeSequence.size();

    // Initialize adjacency matrix
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));
    
    if (HavelHakimiAlgorithm(adjacencyMatrix, degreeSequence)) {
        // Output the result to the file
        writer << n << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                writer << adjacencyMatrix[i][j] << " ";
            }
            if (i != n - 1)
                writer << endl;
        }
    }
    else
        writer << "IMPOSSIBLE";

    writer.close();
    return 0;
}
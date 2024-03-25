#include <iomanip>
#include <iostream>
#include <limits>
#include <math.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Function to map a value from the interval [1, 5] to the interval [-1, 2]
double mapValue(double value)
{
    return (value - 1.0) * (3.0 / 4.0) - 1.0;
}

int main()
{
    string fileName = "data.csv"; // input file name
    ifstream inFile(fileName); // create istream object and open file

    if(inFile.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }

    // Read values from the input file
    vector<double> values;
    double value;
    while (inFile >> value)
    {
        values.push_back(value);
    }

    inFile.close(); // Close the input file

    // Open the output file
    ofstream outFile("result.csv");
    if (!outFile)
    {
        cerr << "Unable to create output file." << endl;
        return 1;
    }

    // Compute the mean of mapped values for each index i from 1 to N
    double sum = 0.0;
    int N = values.size();
    vector<double> means;
    outFile << "# N Mean" << scientific << setprecision(16) << endl;
    for (int i = 0; i < N; i++)
    {
        sum += mapValue(values[i]);
        means.push_back(sum / (i + 1));
        outFile << i + 1 << " " << means[i] << endl;
    }

    outFile.close(); // Close the output file

    return 0;
}

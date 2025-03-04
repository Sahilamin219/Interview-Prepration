You can set the delimiter for "getline", in the third argument.
#include <iostream>
#include <chrono>
#include <thread>
#include<fstream>
using namespace std;

int main() {
    ofstream obj("sahil.cpp");
    string name = "my name is sahil";
    obj << name;
    obj.close();
    ifstream obj2("sql.cpp");
    string content;
    obj2>>content;
    getline(obj2, content, '\r'); // as my file does not contains '\r' it will automatically include all the contents :P
    cout<<content<<"\n";
    obj2.close();
    return 0;
}
CSV File
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Data to write to the CSV file
    vector<vector<string>> data = {
        {"Name", "Age", "City"},
        {"John Doe", "25", "New York"},
        {"Jane Smith", "30", "Los Angeles"},
        {"Alice Johnson", "22", "Chicago"}
    };

    // Open a file for writing
    ofstream file("output.csv");

    // Check if the file is open
    if (!file.is_open()) {
        cerr << "Failed to open the file!" << endl;
        return 1;
    }

    // Write data to the file
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) {
                file << ","; // Add comma separator
            }
        }
        file << "\n"; // Add newline after each row
    }

    // Close the file
    file.close();

    cout << "CSV file written successfully!" << endl;

    return 0;
}

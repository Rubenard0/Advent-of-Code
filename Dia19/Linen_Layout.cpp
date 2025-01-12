#include "TableEntry.h"
#include "HashTable.h"

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void read_list(vector<string>& towels, vector<string>& designs) {
    string input;
    cout << "Enter the list of towels and the list of designs (AoC input):" << endl;
    
    while (getline(cin, input) && !input.empty()) {
        
        istringstream line_stream(input);
        string row;

        while (getline(line_stream, row, ',')) {
            row.erase(0, row.find_first_not_of(" \t")); 
        }
    }

    while (getline(cin, input) && !input.empty()) {
        istringstream line_stream(input);
        designs.push_back(input);  
    }
}

void print(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    cout << endl;
}

bool check_possible(HashTable& towels_table, string& design, int start, vector<int>& memory) {
    if (start == design.length()) {
        return true;
    }

    if (memory[start] != -1) {
        return memory[start] == 1;
    }

    for (int i = start + 1; i <= design.length(); i++) {
        string fragment = design.substr(start, i - start);

        if (towels_table.search(fragment) && check_possible(towels_table, design, i, memory)) {
            memory[start] = 1;
            return true;
        }
    }

    memory[start] = 0;
    return false;
}

int main() {

    HashTable towels_table(128);
    vector<string> designs;
    vector<string> towels;

    int possible_patterns = 0;

    read_list(towels, designs);
    towels_table.fill_table(towels);
    print(towels);
    towels_table.print();
    print(designs);

    for (int i = 0; i < designs.size(); i++) {
        cout << "----- Combination: " << designs[i] << " -----" << endl;
        vector<int> memory(designs[i].length(), -1); 
        if (check_possible(towels_table, designs[i], 0, memory)) {
            cout << "Possible" << endl;
            possible_patterns++;
        } else {
            cout << "Not possible" << endl;
        }
    }

    cout << possible_patterns << endl;

    return 0;
}

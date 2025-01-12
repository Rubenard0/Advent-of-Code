#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void read_list(vector<int>& l1, vector<int>& l2) {
    string input;
    cout << "Enter the lists:" << endl;

    while (getline(cin, input) && !input.empty()) {
        stringstream ss(input);

        int num1, num2;
        if (ss >> num1 >> num2) {
            l1.push_back(num1);
            l2.push_back(num2);
        }
    }
}

int Partition(vector<int>& v, int start, int end) {
    int x = v[end];
    int i = start;

    for (int j = start; j <= end - 1; j++) {
        if (v[j] <= x) {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
        }
    }

    int temp = v[i];
    v[i] = v[end];
    v[end] = temp;

    return i;
}

void QuickSort(vector<int>& v, int start, int end) {
    if (start < end) {
        int pivot = Partition(v, start, end);

        QuickSort(v, start, pivot - 1);
        QuickSort(v, pivot + 1, end);
    }
}

void print_list(const vector<int>& v) {
    cout << "{";

    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ", ";
        } else {
            cout << "}" << endl;
        }
    }
}

int point_distance(int a, int b) {
    return abs(a - b);
}

int list_distance(const vector<int>& l1, const vector<int>& l2) {
    int sum = 0;
    for (size_t i = 0; i < l1.size(); i++) {
        sum += point_distance(l1[i], l2[i]);
    }
    return sum;
}

int BinarySearch(int x, vector<int> v, int start, int end) {
    if (start > end) {
        return -1;
    }

    int middle = (start + end) / 2;

    if (v[middle] == x) {
        return middle;
    } else if (v[middle] > x) {
        return BinarySearch(x, v, start, middle - 1);
    } else {
        return BinarySearch(x, v, middle + 1, end);
    }
}

int similar_count(int x, vector<int> v) {
    int similar = 0;
    int pos_x = BinarySearch(x, v, 0, v.size());

    if (pos_x == -1) {
        return 0;
    }

    similar++;

    int pos_x_right = pos_x + 1;
    int pos_x_left = pos_x - 1;

    while (x == v[pos_x_left]) {
        pos_x_left--;
        similar++;
    }
    while (x == v[pos_x_right]) {
        pos_x_right++;
        similar++;
    }

    return similar;
}

double calculate_similarities(vector<int> l1, vector<int> l2) {
    double similarities = 0;

    for (int i = 0; i < l1.size(); i++) {
        similarities = similarities + l1[i] * similar_count(l1[i], l2);
    }

    return similarities;
}

int main() {
    vector<int> list_1;
    vector<int> list_2;

    read_list(list_1, list_2);

    cout << "The lists are as follows:" << endl;
    print_list(list_1);
    print_list(list_2);
    cout << endl;

    QuickSort(list_1, 0, list_1.size() - 1);
    QuickSort(list_2, 0, list_2.size() - 1);

    cout << "Sorting lists..." << endl;
    print_list(list_1);
    print_list(list_2);

    cout << "The distance between the lists is " << list_distance(list_1, list_2) << endl;

    cout << "SECOND PART" << endl
         << "The similarity score calculation is:" << fixed << calculate_similarities(list_1, list_2);

    return 0;
}

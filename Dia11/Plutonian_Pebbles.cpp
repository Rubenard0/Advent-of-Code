#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <list>

#define BLINKS 25

using namespace std;

void read_list(list<long long>& stones) {
    string input;
    cout << "Enter the list of stones:" << endl;

    getline(cin, input);
    istringstream line_stream(input);
    int number;

    while (line_stream >> number) {
        stones.push_back(number);
    }
}

void print_list(list<long long> stones) {
    list<long long>::iterator it = stones.begin();
    for (it = stones.begin(); it != stones.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int count_digits(long long number) {
    if (number == 0) {
        return 1;
    }

    int digits = 0;
    while (number > 0) {
        number /= 10;
        digits++;
    }
    return digits;
}

int blink(list<long long>& stones, int n) {
    if (n <= 0) {
        return stones.size();
    }

    list<long long>::iterator it = stones.begin();
    for (it; it != stones.end(); advance(it, 1)) {
        if (*it == 0) {
            *it = 1;
        } else if (count_digits(*it) % 2 == 0) {
            int upper_half = (*it / pow(10, count_digits(*it) / 2));
            int lower_half = *it - (upper_half * pow(10, count_digits(*it) / 2));
            *it = lower_half;
            stones.insert(it, upper_half);
        } else {
            *it *= 2024;
        }
    }
    return blink(stones, n - 1);
}

int main() {

    list<long long> stones;

    read_list(stones);

    cout << "There are " << blink(stones, BLINKS) << " stones." << endl;

    return 0;
}

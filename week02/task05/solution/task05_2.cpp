#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

void print_out(const vector<int>& vec) {
    for (int item : vec) {
        cout << item << "\n";
    }
}

int main() {
    /* read inputs */
    vector<int> input;
    int value;
    while (cin >> value) {
        input.push_back(value);
    }

    int pointer = -1;
    vector<int> output;
    int input_size = input.size();

    while (++pointer < input_size) {
        if (input[pointer] == 0) {
            if (input_size - pointer <= 3) {
                output.push_back(*max_element(input.begin() + pointer, input.end()));
            } else {
                int position = pointer + (input_size - pointer) / 3;
                output.push_back(input[position]);
                input.erase(input.begin() + position);
                input_size--;
            }
        }
    }
    print_out(output);

    /* return */
    return 0;
}

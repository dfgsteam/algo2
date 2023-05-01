#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

void print_out(vector<int> vec) {
    //cout << "------\n";
    for (int item:vec) {
        cout << item << endl;
    }
    //cout << "------\n";
}


int find_0(vector<int>& input_copy) {
    int position;
    if (input_copy.size() > 3) {
        position = input_copy.size() - ceil((double)input_copy.size()/3);
    } else {
        position = input_copy.size() - 1;
    }

    int value = input_copy[position];

    //cout << "[" << position << "/" << input_copy.size()-1 << "]\n";
    //print_out(input_copy);
    input_copy.erase(std::find(input_copy.begin(), input_copy.end(), value));
    return value;
}

int main() {
    /* read inputs */
    vector<int> input;
    string inp_console;
    while (cin >> inp_console) {
        try {
            input.emplace_back(stoi(inp_console));
        } catch (...) {
            input.emplace_back(0);
        }
    }
    //input.pop_back();
    
    //print_out(input);
    
    vector<int> input_copy;
    vector<int> output;
    input_copy.reserve(input.size() - 1);
    output.reserve((input.size() - 1)/2+5);

    for (int item : input) {
        if (item == 0) {
            output.push_back(find_0(input_copy));
        } else {
            input_copy.emplace(lower_bound(input_copy.begin(), input_copy.end(), item), item);        
        }
    }
    print_out(output);

    /* return */
    return 0;
} 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int distributeBulls(const vector<int>& stalls, int K) {
    int N = stalls.size();
    int low = 0;
    int high = stalls[N-1] - stalls[0];

    while (low < high) {
        int mid = (low + high + 1) / 2;
        int count = 1;
        int prev = stalls[0];

        for (int i = 1; i < N; i++) {
            if (stalls[i] - prev >= mid) {
                count++;
                prev = stalls[i];
            }
        }

        if (count >= K) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> stalls(N);
    for (int i = 0; i < N; i++) {
        cin >> stalls[i];
    }

    int result = distributeBulls(stalls, K);
    cout << result << endl;

    return 0;
}

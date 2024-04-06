#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_group_id(int N, vector<int>& weights) {
    int group_id = 0;
    
    for (int i = 0; i < N; ++i) {
        int weight_score = 0;
        if (i < N - 1 && weights[i] < *max_element(weights.begin() + i + 1, weights.end())) {
            weight_score += 5;
        }
        if (i < N - 1 && weights[i] < *min_element(weights.begin() + i + 1, weights.end())) {
            weight_score += 10;
        }
        if (i == N - 1 || weights[i] > *max_element(weights.begin() + i + 1, weights.end())) {
            weight_score += 15;
        }
        group_id += weight_score;
    }
    return group_id;
}

int main() {
    int N;
    cin >> N;

    vector<int> weights(N);
    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }

    // Calculate and print the group ID
    cout << calculate_group_id(N, weights) << endl;

    return 0;
}

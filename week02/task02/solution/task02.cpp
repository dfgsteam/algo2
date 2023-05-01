#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cctype>
#include <map>

using namespace std;


int main() {
    /* read buckets, balls, bets */
    int buckets, balls, bets;
    cin >> buckets >> balls >> bets;

    /* read buckets */
    map<int, vector<int>> buckets_maps;
    for (int ball=1; ball<=balls; ball++) {
        int ball_throw;
        cin >> ball_throw;
        if (buckets_maps.find(ball_throw) == buckets_maps.end()) {
            buckets_maps[ball_throw]; 
        }
        buckets_maps[ball_throw].push_back(ball);
    }

    /* read bets */
    vector<string> bets_vector(bets);
    for (int bet=0; bet<bets; bet++) {
        int bet_bucket, bet_ball_amount;
        cin >> bet_bucket >> bet_ball_amount;
        vector<int> bet_balls(bet_ball_amount);
        for (int bet_ball_counter=0; bet_ball_counter<bet_ball_amount; bet_ball_counter++) {
            cin >> bet_balls[bet_ball_counter];

        }
        if (buckets_maps.find(bet_bucket) != buckets_maps.end()) {
            if (buckets_maps[bet_bucket].size() == bet_ball_amount) {
                bool bet_check = true;
                for (int ball_throw : bet_balls) {
                    if (bet_check && find(buckets_maps[bet_bucket].begin(), buckets_maps[bet_bucket].end(), ball_throw) != buckets_maps[bet_bucket].end()) {
                        continue;
                    }
                    bet_check = false;
                    break;
                }
                if (bet_check) {
                    bets_vector[bet] = "CORRECT";
                    continue;
                }
            }
        }
        bets_vector[bet] = "INCORRECT";
    }


    for (string bet : bets_vector) {
        cout << bet << "\n";
    }

    /* return */
    return 0;
} 
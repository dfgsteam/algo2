#include <algorithm>
#include<bits/stdc++.h>
#include <string>
using namespace std;


int main(){
    int X,Y,x1,x2,y1,y2,r;
    cin >> X >> Y;
    int regen[X+1][Y+1];
    fill(regen[0], regen[0] + (X+1) * (Y+1), 0);
    while(true){
        string what;
        cin >> what;
        if(what == "RAIN"){
            cin >> x1 >> y1 >> x2 >> y2 >> r;
            for(int i = x1; i <= x2; i++){
                for(int j = y1; j <= y2; j++){
                    regen[i][j] += r;
                }
            }
        }
        else if(what == "REQUEST"){
            cin >> x1 >> y1;
            if(x1 < 0 || y1 < 0){
                break;
            }
            cout << regen[x1][y1] << endl;

        }
    }

    return 0;
}

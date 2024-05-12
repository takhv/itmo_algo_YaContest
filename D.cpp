#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c, d, k;
    int bacteries;
    cin >> a >> b >> c >> d >> k;
    k = min(k, 1000);

    bacteries = a;
    for (int i = 1; i <= k; i++){
        bacteries = bacteries * b;
        if (bacteries < c){
            bacteries = 0;
            break;
        } else {
            bacteries = bacteries - c;
        }
        bacteries = min(bacteries, d);
    }

    cout << bacteries;
}
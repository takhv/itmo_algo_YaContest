#include <iostream>
#include <vector>

using namespace std;

bool cowPlacer(vector<int> coords, int distance, int cows){
    int lastCow = coords[0];
    int placedCowsCount = 1;

    for (int i = 1; i < coords.size(); ++i){
        if (coords[i] - lastCow >= distance){
            lastCow = coords[i];
            placedCowsCount++;
            if (placedCowsCount == cows){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> coords(N);
    for (int i = 0; i < N; ++i){
        cin >> coords[i];
    }

    int low = 0;
    int high = coords.back() - coords.front();
    int max_distance = -1;

    while (low <= high){
        int middle = low + (high - low)/2;
        if (cowPlacer(coords, middle, K)){
            max_distance = middle;
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }

    cout << max_distance;

    return 0;
}
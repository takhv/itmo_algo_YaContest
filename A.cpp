#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> flowers(n);
    for (int i = 0; i < n; i++){
        cin >> flowers.at(i);
    }


    int start = 0;
    int end = 0;
    int countChain = 0;
    int maxChain = -999;
    int prevFlower = 0;
    int alsoPrevFlower = 0;
    for (int i = 0; i < flowers.size(); i++){
        if (flowers[i] == prevFlower && flowers[i] == alsoPrevFlower){
            countChain = 2;
        } else {
            countChain++;
        }

        if (countChain > maxChain){
            maxChain = countChain;
            start = i - maxChain + 1;
        }

        alsoPrevFlower = prevFlower;
        prevFlower = flowers[i];

        end = start + maxChain-1;
    }

    cout << start+1 << " " << end+1;
}
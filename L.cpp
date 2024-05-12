#include <iostream>
#include <vector>

using namespace std;

int main() {
    int count;
    int space;
    cin >> count >> space;
    vector<int> sequence(count);
    for (int i = 0; i < count; ++i)
        cin >> sequence[i];

    int left = 0;
    int right = left+space-1;

    while (right < count) {
        ++right;

        int min = sequence[left];
        for (int i = left+1; i < right; i++) {
            if (sequence[i] < min){
                min = sequence[i];
            }
        }
        cout << min << " ";

        ++left;
    }

    return 0;
}

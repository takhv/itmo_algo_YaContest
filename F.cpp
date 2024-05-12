#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool checker(const string& a, const string& b) {
    return a + b > b + a;
}

int main() {
    string n;
    vector<string> number;

    while (cin >> n) {
        number.push_back(n);
    }

    sort(number.begin(), number.end(), checker);

    string result;
    for (const auto & i : number){
        result += i;
    }

    cout << result;

    return 0;
}

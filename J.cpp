#include <iostream>
#include <vector>

using namespace std;

int main(){
    int goblin_count;
    vector<int> queue;
    vector<string> input;
    string n;
    cin >> goblin_count;

    while (cin >> n){
        input.push_back(n);
    }

    for(int i = 0; i < input.size(); i++){
        if (input[i] == "+") {
            queue.push_back(stoi(input[i+1]));
        } else if (input[i] == "-") {
            cout << queue.at(0) << "\n";
            queue.erase(queue.begin());
        } else if (input[i] == "*") {
            if (queue.size() % 2 == 0){
                queue.insert(queue.begin()+queue.size()/2, stoi(input[i+1]));
            } else {
                queue.insert(queue.begin()+queue.size()/2 + 1, stoi(input[i+1]));
            }
        }
    }

    return 0;
}
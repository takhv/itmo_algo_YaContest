#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cells;
    int count;
    cin >> cells >> count;
    vector<bool> memory (cells);
    vector<int> moves (count);

    for (int i = 0; i < count; ++i){
        cin >> moves[i];
    }

    for (int i = 0;i < moves.size(); ++i){
        cout << i+1 << " " << moves[i] << endl;
        for (int j = 0; j < moves[i]; ++j) {
            if (!memory[j]) {

            }
        }
    }

    return 0;
}
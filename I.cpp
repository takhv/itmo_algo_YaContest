#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cars_count;
    int cars_on_floor;
    int wanna_play_num;
    vector<int> playlist;
    int n;
    cin >> cars_count >> cars_on_floor >> wanna_play_num;

    while (playlist.size() < wanna_play_num){
        cin >> n;
        playlist.push_back(n);
    }

    for(int i = 0; i < wanna_play_num; i++){
        cout << playlist[i];
    }



    return 0;
}
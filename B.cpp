#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    string animalsAndTraps;
    cin >> animalsAndTraps;
    stack<char> s;
    string result;
    vector<int> animals;
    vector<int> traps;

    // eaacCbAaBAADdE
    // eaabAaBAADdE - 4
    // eaabBAADdE - 4 6
    // eaaAADdE - 4 6 5
    // eaADdE - 4 6 5 3
    // eDdE - 4 6 5 3 2
    // eE - 4 6 5 3 2 7
    //  - 4 6 5 3 2 7 1
    // 4 6 5 3 2 7 1
    //     e a a
    //   E       c
    //  d         C
    //  D         b
    //   A       A
    //     A B a
    //

    for (int i = 0; i < animalsAndTraps.size(); i++){
        if (animalsAndTraps[i] == toupper(animalsAndTraps[i])) {
            traps.push_back(i);
        }
        if (animalsAndTraps[i] == tolower(animalsAndTraps[i])){
            animals.push_back(i);
        }
    }

    for (int i = 0; i < traps.size(); i++){
        cout << traps[i] << " " << animals[i] << " --- ";
    }

    vector<int> leaver;
    for (int j = 0; j < animals.size(); j++){
        leaver.push_back(-1);
    }

    while (animals != leaver){
        for (int i = 0; i < animalsAndTraps.size(); i++) {

            if (animalsAndTraps[i] == toupper(animalsAndTraps[i])) { // выбор клетки
                s.push(animalsAndTraps[i]);
                // проверка на животное буквы перед клеткой
                // eaacCbAaBAADdE
                if (animalsAndTraps[i - 1] == tolower(animalsAndTraps[i - 1])) {
                    // подходит ли животное
                    if (animalsAndTraps[i] == toupper(animalsAndTraps[i - 1])) {
                        for (int k = 0; k < animals.size(); k++){
                            if (animals[k] == i-1){
                                result += to_string(k+1) + " ";
                                animals[k] = -1;
                            }
                        }
                        s.pop();
                        animalsAndTraps.erase(i - 1, 2);
                        continue;
                        cout << "\n" << animalsAndTraps << " - anim, result -" << result << "\n";
                    }
                }

                // проверка на животное буквы после клетки
                // eaacCbAaBAADdE
                if (animalsAndTraps[i + 1] == tolower(animalsAndTraps[i + 1])) {
                    // подходит ли животное
                    if (animalsAndTraps[i] == toupper(animalsAndTraps[i + 1])) {
                        for (int k = 0; k < animals.size(); k++){
                            if (animals[k] == i+1){
                                result += to_string(k+1) + " ";
                                animals[k] = -1;
                            }
                        }
                        s.pop();
                        animalsAndTraps.erase(i, 2);
                        continue;
                        cout << "\n" << animalsAndTraps << " - anim, result -" << result << "\n";
                    }
                }

            }
            if (animals == leaver){
                break;
            }
        }

        for (int animal : animals){
            cout << animal << " ";
        }

    }


    if (s.empty()){
        cout << "Possible\n" << result;
    } else {
        cout << "Impossible";
    }
}

//        if (animalsAndTraps[i] == toupper(animalsAndTraps[i])){
//            result += to_string(i) + " ";
//            s.pop();
//            animalsAndTraps.erase(i, 1);
//            cout << animalsAndTraps << " ";
//        }
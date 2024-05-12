#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string str;
    cin >> str;
    bool big = false;
    bool smol = false;
    bool numbers = false;
    bool signs = false;
    if (str.size() > 14 or str.size() < 8){
        cout << "NO";
    } else {
        for (char i : str){
            if ((int)i < 33 or (int)i > 126){
                cout << "NO";
                break;
            } else {
                if ((int)i <= 90 and (int)i >= 65){
                    big = true;
                } else if ((int)i >= 97 and (int)i <= 122){
                    smol = true;
                } else if ((int)i >= 48 and (int)i <= 57){
                    numbers = true;
                } else {
                    signs = true;
                }
            }
        }
    }
    if (big and smol and numbers and signs){
        cout << "YES";
    } else if (!big and smol and numbers and signs){
        cout << "YES";
    } else if (big and !smol and numbers and signs){
        cout << "YES";
    } else if (big and smol and !numbers and signs){
        cout << "YES";
    } else if (big and smol and numbers and !signs){
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    string word;
    cin >> word;
    auto* answer = new string[word.length()];

    int arr[26][3];

    for (int i = 0; i < 26; i++) {
        arr[i][0] = i;
        cin >> arr[i][1];
        arr[i][2] = 0;
    }

    for (char i : word) {
        arr[(int)i - 'a'][2]++;
    }

    int temp;
    for (int i = 0; i < 26 - 1; i++) {
        for (int j = 0; j < 26 - i - 1; j++) {
            if (arr[j][1] < arr[j + 1][1]) {
                temp = arr[j][1];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][1] = temp;

                temp = arr[j][0];
                arr[j][0] = arr[j + 1][0];
                arr[j + 1][0] = temp;

                temp = arr[j][2];
                arr[j][2] = arr[j + 1][2];
                arr[j + 1][2] = temp;
            }
        }
    }

    int size = word.length();
    int i = 0;
    for (int j = 0; j < 26; j++) {
        if (arr[j][2] > 1) {
            answer[i] = (char)(arr[j][0] + 'a');
            answer[word.length() - 1 - i] = (char)(arr[j][0] + 'a');
            arr[j][2] -= 2;
            size--;
            i++;
        }
    }

    for (int k = i; i < size; i++) {
        int j;
        for (j = 0; j < 26; j++) {
            if (arr[j][2] > 0)
                break;
        }
        if (j != 26) {
            answer[i] = (char)(arr[j][0] + 'a');
            arr[j][2]--;
        }
    }


    for (int i = 0; i < word.length(); i++) {
        cout << answer[i];
    }
    return 0;
}
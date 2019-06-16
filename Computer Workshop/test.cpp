#include <iostream>
#include <string>
#include <vector>

using namespace std;

  bool compare(string word, char* lib) {
        bool has = false;
        for (int i = 0; i < word.length(); i++) { 
            has = false;
            cout << "iteration" << i << endl;
            for(int j = 0; j < 8; j++) {
                cout << word[i] << " -- " << lib[j] << endl; 
                if (word[i] == lib[j]) {
                    cout << "matches" << endl;
                    has = true;
                }
            }
            cout << "INTERMITTENT VALUE IS " << has;
            if (!has)
                return false;
        }
        cout << "FINAL VALUE IS" << has;
        return has;
        // return true;
    }

int main() {

    string word = "abcdefgh";
    char lib1[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}; // all letters match
    char lib2[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'y'}; // not all letters match
    char lib3[8] = {'z', 'x', 'n', 'k', 'l', 'o', 'p', 'i'}; // no letters match

    bool test1 = compare(word, lib1);
    bool test2 = compare(word, lib2);
    bool test3 = compare(word, lib3);

    cout << endl << test1 << ' ' << test2 << ' ' << test3;

    return 0;
}
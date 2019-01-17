#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  string longest_str = "", comparison_str = "";

  while(cin >> comparison_str){
    if (comparison_str.size() > longest_str.size()) {
      longest_str = comparison_str;
    }
  }

  cout << longest_str << endl << longest_str.size();

  return 0;
}

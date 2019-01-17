#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Party {
  string name;
  int votes;
};

bool compareByVotes(const Party &a, const Party &b) {
  return a.votes > b.votes;
}

int main(int argc, char const *argv[]) {

  int cnt;
  cin >> cnt;

  Party party;

  vector<Party> v;

  for (size_t i = 0; i < cnt; i++) {
    getline(cin, party.name);
    party.votes = 1;
    string party_name = party.name;

    int temp = 0;
    for (size_t j = 0; j < v.size(); j++) {
      if (party_name == v[j].name)
      {
        v[j].votes++;
        temp++;
      }
    }
    if(temp == 0)
    {
      v.push_back(party);
      v[v.size()-1].votes++;
    }
  }

  sort(v.begin(), v.end(), compareByVotes);

  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i].name << endl;
  }

  return 0;
}

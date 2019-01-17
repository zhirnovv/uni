#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<vector<int>> adjacencyMatrixToListUnweighted(const vector<vector<int>>& a)
{
    int n = a.size();
    vector<vector<int>> res(n);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
           if (a[i][j] > 0) {
               res[i].push_back(j);
           }
        }
    }
    return res;
}

vector<vector<int>> listToAdjacencyMatrixUnweighted(const vector<vector<int>>& a)
{
    int n = a.size();
    vector<vector<int>> r(n, vector<int>(n, 0));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            r[i][a[i][j]] = 1;
        }
    }
    return r;
}

vector<string> splitString(const string &s, char delim)
{
	vector<string> elems;
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<vector<int>> reverseGraph(vector<vector<int>>& a)
{
	vector<vector<int>> r(a.size(), vector<int>());
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			r[a[i][j]].push_back(i);
		}
	}
	return r;
}

int main()
{
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	vector<vector<int>> a(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		auto r = splitString(s,  ' ');
		for (int j = 0; j < r.size(); ++j) {
			a[i].push_back( stoi(r[j]) - 1);
		}
	}
	auto res = reverseGraph(a);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}

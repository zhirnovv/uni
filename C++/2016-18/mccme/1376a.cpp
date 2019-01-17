#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct Set {
    int sum = 0;
    shared_ptr <Set> redir = nullptr;
};

int main() {
    vector <shared_ptr <Set>> parent;

    int n, m, command;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        shared_ptr <Set> temp = make_shared <Set> ();
        parent.push_back(temp);
    }

    for (int i = 0; i < m; i++) {
        cin >> command;

        if (command == 1) {
            int a, b, c;
            cin >> a >> b >> c;

            shared_ptr <Set> t1 = parent[--a];
            while (t1->redir) {
                t1 = t1->redir;
            }

            shared_ptr <Set> t2 = parent[--b];
            while (t2->redir) {
                t2 = t2->redir;
            }

            if (t1 == t2) {
                t1->sum += c;
                continue;
            }

            t1->sum += t2->sum + c;
            t2 = t1;
        } else {
            int a;
            cin >> a;

            shared_ptr <Set> temp = parent[--a];

            while (temp->redir) {
                temp = temp->redir;
            }

            cout << temp->sum << endl;
        }
    }

    return 0;
}

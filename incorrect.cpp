// Assummed everything was clockwise
// Saw an elegant pattern
// Believed it.. It was wrong

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct Node {
    public:
    short int val;
    short int c[2];

    Node() {
        c[0] = -1;
        c[1] = -1;
    };
};

int main() {
    int n;
    cin >> n;

    vector<Node> v(n);
    for(int i = 0; i < 2 * n; i++) {
        int idx, c;
        cin >> idx >> c;
        idx--; c--;
        v[idx].c[v[idx].c[0] != -1] = c;
    }

    int parentdx;
    parentdx  = 0;
    vector<short int> ret;
    ret.push_back(1);
    for (int i = 1; i < n; i++) {
        bool is0 = v[v[parentdx].c[0]].c[0] == v[parentdx].c[1] || v[v[parentdx].c[0]].c[1] == v[parentdx].c[1];
        bool is1 = (v[v[parentdx].c[1]].c[0] == v[parentdx].c[0] || v[v[parentdx].c[1]].c[1] == v[parentdx].c[0]);
        if (is0) {
            parentdx = v[parentdx].c[0];
        }
        else if (is1) {parentdx = v[parentdx].c[1];}
        else {
            cout << -1;
            return 0;
        }
        ret.push_back(parentdx + 1);
    }

    for (auto elem : ret) {
        cout << elem << " ";
    }

    // cout << '\n';
    return 0;
}
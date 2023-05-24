#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct Tetra {
    public:
    unsigned int c[4];
    short int ct = 0;

    Tetra() {
        ct = 0;
    }

    bool append(unsigned int x) {
        if (ct == 4) {
            return true;
        }
        else {
            c[ct++] = x;
            return false;
        }
    }
};

int main() {
    unsigned int n;
    cin >> n;
    vector<Tetra> v(n);

    unsigned int v1, v2;
    for (unsigned int i = 0; i < 2 * n; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        if (v[v1].append(v2) || v[v2].append(v1)) {
            cout << -1;
            return 0;
        }
    }

    for (unsigned int i = 0; i < n; i++) {
        if (v[i].ct != 4) {
            cout << -1;
            return 0;
        }
    }

    vector<bool> visited(n);
    vector<short int> vis;
    vector<unsigned int> ret;
    ret.push_back(0);
    vis.push_back(0);
    visited[0] = true;
    Tetra tmp;

    while (1) {
        if (ret.size() == n) {
            // v[ret.back()].c superset {ret[0], ret[1]};
            bool x = 0, y = 0;
            for (auto elem : v[ret.back()].c) {
                if (elem == ret[0]) { x = 1; }
                if (elem == ret[1]) { y = 1; }
            }

            // v[ret[n - 2]].c superset {ret[0]};
            bool z = 0;
            for (auto elem : v[ret[n - 2]].c) {
                if (elem == ret[0]) { z = 1; break; }
            }


            if (x && y && z) {
                for (auto elem : ret) {
                    cout << elem + 1 << " ";
                }
                return 0;
            }

            visited[ret.back()] = 0;
            ret.pop_back();
            vis.pop_back();

            if (!z) {
                visited[ret.back()] = 0;
                ret.pop_back();
                vis.pop_back();
            }

        } else if (ret.size() == 0) {
            cout << -1;
            return 0;
        }

        tmp = v[ret.back()];
        if (vis.back() != 4) {
            unsigned int l = tmp.c[vis.back()++];
            bool i = 0;
            if (ret.size() > 1) {
                for (auto elem : v[l].c) {
                    if (elem == *(ret.end() - 2)) { i = 1; break; };
                }
            } else i = 1;
            if (!visited[l] && i) {
                ret.push_back(l);
                vis.push_back(0);
                visited[l] = true;
            }
        }
        else {
            vis.pop_back();
            visited[ret.back()] = false;
            ret.pop_back();
        }
    }
}
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

struct Weighing {
    string res;
    vector<int> left;
    vector<int> right;
};

bool valid(const vector<Weighing>& w, int f, bool h) {
    for (const auto& v : w) {
        const vector<int>& L = v.left;
        const vector<int>& R = v.right;
        bool fl = find(L.begin(), L.end(), f) != L.end();
        bool fr = find(R.begin(), R.end(), f) != R.end();
        string r = v.res;

        if (!fl && !fr) {
            if (r != "=") return false;
        } else if (fl && !fr) {
            if ((h && r != ">") || (!h && r != "<")) return false;
        } else if (fr && !fl) {
            if ((h && r != "<") || (!h && r != ">")) return false;
        } else {
            if (r != "=") return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Weighing> w;

    for (int i = 0; i < m; ++i) {
        string r;
        int a, b;
        cin >> r >> a;
        vector<int> L(a), R(b);
        for (int j = 0; j < a; ++j) cin >> L[j];
        cin >> b;
        for (int j = 0; j < b; ++j) cin >> R[j];
        sort(L.begin(), L.end());
        sort(R.begin(), R.end());
        w.push_back({r, L, R});
    }

    set<int> candidates;
    for (int coin = 1; coin <= n; ++coin) {
        if (valid(w, coin, true)) candidates.insert(coin);
        if (valid(w, coin, false)) candidates.insert(coin);
    }

    if (candidates.empty()) {
        cout << "Данные противоречивы." << endl;
    } else if (candidates.size() == 1) {
        cout << "Фальшивая монета: " << *candidates.begin() << endl;
    } else {
        cout << "Недостаточно данных." << endl;
    }

    return 0;
}
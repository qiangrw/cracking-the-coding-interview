/*
 * Problem 10.1 Design an algorithm that takes a set of files containing sotck trade information
 * in sorted order, and writes a single file containing all lines appearing in the individual files
 * sorted in sorted order. The algorithm should use very little RAM, ideally of the order of a few
 * kilobytes.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
struct cmp {
    bool operator() (const pair<T, int> &a, const pair<T, int> &b) const {
        return a.first > b.first;
    }
};

template <typename T>
vector<T> merge_arrays(const vector<vector<T>> &S) {
    priority_queue<pair<T,int>, vector<pair<T, int> >, cmp<T> > minheap;
    vector<int> S_idx(S.size(), 0);

    for (int i = 0; i < S.size(); ++i) {
        if (!S[i].empty()) {
            minheap.push(make_pair(S[i][0], i));
            S_idx[i] = 1;
        }
    }

    vector<T> res;
    while (!minheap.empty()) {
        pair<T,int> p = minheap.top();
        res.push_back(p.first);
        if (S_idx[p.second] < S[p.second].size()) {
            minheap.push(make_pair(S[p.second][S_idx[p.second]], p.second));
            ++S_idx[p.second];
        }
        minheap.pop();
    }

    return res;
}


int main() {
    vector<vector<int> > S(3);
    S[0] = {1, 2, 3, 4};
    S[1] = {2, 100, 3000, 9999};
    S[2] = {4, 5, 88, 120, 222, 444, 555};
    //vector<vector<int> > S = { {1, 2, 3, 4, 5}, {2, 100, 300, 999}, {4, 5, 8, 100000} };
    vector<int> res = merge_arrays(S);
    for (auto x: res) cout << x << " ";
    cout << endl;
    return 0;
}

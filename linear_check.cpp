#include<bits/stdc++.h>
using namespace std;

vector<int> StringtoVector(const string &s) {
    vector<int> v;
    for(auto x : s) {
        v.push_back(x - '0');
    }
    return v;
}

vector<int> XOR(const vector<int> &a, const vector<int> &b) {
    vector<int> ans(a.size());
    for(int i = 0; i < a.size(); i++) {
        ans[i] = a[i] ^ b[i];
    }
    return ans;
}

string VectortoString(const vector<int> &v) {
    string s = "";
    for(auto i : v) {
        s.push_back(char(i + '0'));
    }
    return s;
}


int main()
{
    int n;
    cin >> n;
    vector<string> code(n);
    for(auto &s : code) {
        cin >> s;
    }
    int l = code[0].size();
    unordered_set<string> c; //fast searching
    vector<vector<int>> v; //store in vector

    bool zero = false; //all-zero codeword

    for(auto &s : code) {
        c.insert(s);
        v.push_back(StringtoVector(s));
        bool ok = true;
        for(auto i : s) {
            if(i != '0') {
                ok = false;
                break;
            }
        }
        if(ok) zero = true;
    }

    if(!zero) {
        cout << "Not linear" << endl;
        return 0; //continue if there are more cases in one test
    }

    int nv = v.size();
    for(int i = 0; i < nv; i++) {
        for(int j = 0; j < nv; j++) {
            vector<int> a = v[i];
            vector<int> b = v[j];
            vector<int> d = XOR(a, b);
            if(c.find(VectortoString(d)) == c.end()) {
                cout << "Not linear" << endl;
                return 0;
            }
        }
    }

    cout << "Linear code block" << endl;

    return 0;
}

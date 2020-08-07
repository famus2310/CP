#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const ll INF64 = 1e18;

template <typename T>
string to_string(const vector<T> &v) {
    string ret = "<";
    for (auto it : v) {
        ret += to_string(it) + ", ";
    }
    ret.pop_back(); ret.pop_back();
    ret += ">";
    return ret;
}

void debug_print() { cerr << endl; }

template <typename T, typename ...U>
void debug_print(T t, U... u) {
    cerr << " " << to_string(t);
    debug_print(u...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_print(__VA_ARGS__)
const int N = 1e5 + 5;

class Thesaurus {
    private:
        unordered_map<string, unordered_set<string>> hashTable;
    
    public:
        void add(string word, vector<string> synonyms) {
            for (string synonym : synonyms) {
                this->hashTable[word].insert(synonym);
                this->hashTable[synonym].insert(word);
            }
        }

        vector<string> getSynonyms(string word) {
            vector<string> synonyms;
            for (string s : this->hashTable[word]) {
                synonyms.push_back(s);
            }
            return synonyms;
        }
};

void output(const vector<string>& s) {
    if (s.empty()) {
        cout << "[ null ]" << endl;
        return;
    }
    cout << "[ ";
    for (int i = 0; i < s.size(); i++) {
        if (i > 0)
            cout << ", ";
        cout << "'" << s[i] << "'";
    }
    cout << " ]";
    cout << endl;
}

int main() {
    Thesaurus *thesaurus = new Thesaurus();
    thesaurus->add("big", {"large", "great"});
    thesaurus->add("big", {"huge", "fat"});
    thesaurus->add("huge", {"enormous", "gigantic"});

    output(thesaurus->getSynonyms("big"));

    output(thesaurus->getSynonyms("huge"));

    output(thesaurus->getSynonyms("gigantic"));

    output(thesaurus->getSynonyms("colossal"));

    return 0;
}
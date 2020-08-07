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
const int N = 2e5 + 5;

string s;
ll p[N], c[N], p_new[N], c_new[N], cnt[N], pos[N], lcp[N];

void count_sort(ll n) {
  SET(cnt, 0);
  for (int i = 0; i < n; i++)
    cnt[c[i]]++;
  pos[0] = 0;
  for (int i = 1; i < n; i++)
    pos[i] = pos[i - 1] + cnt[i - 1];
  for (int i = 0; i < n; i++)
    p_new[pos[c[p[i]]]++] = p[i];
  for (int i = 0; i < n; i++)
    p[i] = p_new[i];
}

int main() {
  ll n, m;
  cin >> n >> m;
  ll len = n + 1;
  vector<ll> s(n);
  for (auto &it : s)
    cin >> it;
  s.pb(0);
  vector<pair<ll, ll> > a(len);
  for (int i = 0; i < len; i++)
    a[i] = {s[i], i};
  sort(all(a));
  for (int i = 0; i < len; i++)
    p[i] = a[i].second;
  c[p[0]] = 0;
  for (int i = 1; i < len; i++)
    c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);

  int k = 0;
  while ((1 << k) < len) {
    for (int i = 0; i < len; i++)
      p[i] = (p[i] - (1 << k) + len) % len;

    count_sort(len);
    
    c_new[p[0]] = 0;
    for (int i = 1; i < len; i++) {
      pii prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % len]};
      pii now = {c[p[i]], c[(p[i] + (1 << k)) % len]};
      c_new[p[i]] = c_new[p[i - 1]] + (prev != now);
    }
    for (int i = 0; i < len; i++)
      c[i] = c_new[i];
    k++;
  }

  //kasai, arimura, arikawa, lee & park
  ll cur = 0;
  for (int i = 0; i < len - 1; i++) {
    int pi = c[i];
    while (s[i + cur] == s[p[pi - 1] + cur])
      cur++;
    lcp[pi] = cur;
    cur = max(0ll, cur - 1);
  } 
  
  // Largest Rectangle in Histogram!!
  stack<ll> st;
  ll max_area = n;
  ll start = 0;
  ll ans_len = n;
  ll i = 0;
  ll tp, area_with_top;
    while (i < len)
    {
        if (st.empty() || lcp[st.top()] <= lcp[i])
            st.push(i++);
        else
        {
            tp = st.top();  // store the top index
            st.pop();  // pop the top

            area_with_top = lcp[tp] * (st.empty() ? i + 1 :
                                   i - st.top());

            if (max_area < area_with_top) {
                max_area = area_with_top;
                start = p[tp];
                ans_len = lcp[tp];
            }
        }
    }

    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (st.empty() == false)
    {
        tp = st.top();
        st.pop();
        area_with_top = lcp[tp] * (st.empty() ? i + 1 :
                                i - st.top() );

        if (max_area < area_with_top) {
            max_area = area_with_top;
            start = p[tp];
            ans_len = lcp[tp];
        }
    }

  //for (ll i = 1; i < len; i++) {
    //while (!st.empty() && lcp[st.top()] > lcp[i]) {
      //ll tp = st.top(); st.pop();
      //ll cur_area = (i - tp + 1) * (lcp[tp]); 
      //if (cur_area > max_area) {
        //max_area = cur_area;
        //start = p[tp];
        //ans_len = lcp[tp];
      //}
    //}
    //if (lcp[i] > 0)
      //st.push(i);
  //}  
  //while (!st.empty()) {
    //ll tp = st.top(); st.pop();
    //ll cur_area = (len - tp + 1) * (lcp[tp]); 
    //if (cur_area > max_area) {
      //max_area = cur_area;
      //start = p[tp];
      //ans_len = lcp[tp];
    //}
  //}
  cout << max_area << endl;
  cout << ans_len << endl;
  for (int i = start; i < start + ans_len; i++)
    cout << s[i] << " ";
  cout << endl;
  return 0;
}

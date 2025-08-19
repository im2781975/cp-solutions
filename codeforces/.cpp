#include<bits/stdc++.h>
#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;


const ll MAXAI =(ll) 1e12;
const int INF = (int) 1e9;
const int mod = (int)1e9 + 7; 
const int maxn = (int) 1e5 + 10;

int longestCommonSubstr(string x, string y, int n, int m, int cnt)
{
   if(n == 0 || m == 0) return cnt;
   if(x[n - 1] == y[m - 1])
   {
      cnt = longestCommonSubstr(x, y, n - 1, m - 1, cnt + 1); 
   }
   int cnt1 = longestCommonSubstr(x, y, n, m - 1, 0); 
   int cnt2 = longestCommonSubstr(x, y, n - 1, m , 0);
   cnt = max({cnt, cnt1, cnt2});
   return cnt;
}

int unboundKnapsack(vector<int>& wt, vector<int>& val, int w, int n)
{
   if(n == 0 || w == 0) return 0;
   if(wt[n - 1] <= w)
   {
      return max(val[n - 1] + unboundKnapsack(wt, val, w - wt[n - 1], n),
      0 + unboundKnapsack(wt, val, w - 0, n - 1));
   }
   else return 0 + unboundKnapsack(wt, val, w, n - 1);
}

int knapsack(vector<int>& wt, vector<int>& val, int w, int n, vector<vector<int>>&ans)
{
   if(n == 0 || w == 0) return 0;
   if(ans[n][w] != -1) return ans[n][w];
   if(wt[n - 1] <= w)
   {
      return ans[n][w] = max (val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1, ans), 
      0 + knapsack(wt, val, w - 0, n - 1, ans));
   }
   else return ans[n][w] = 0 + knapsack(wt, val, w - 0, n - 1, ans);
}


int knapsackDP(vector<int>& wt, vector<int>& val, int capacity, int n, vector<vector<int>>& ans)
{
   //if(n == 0 || capacity == 0) return 0;
   for(int i = 0; i < ans.size(); i++)
   {
   for(int j = 0; j < ans[0].size(); j++)
   {
         if(i == 0 || j == 0) ans[i][j] = 0;
     }
   }
   //if(ans[n][capacity] != -1) return ans[n][capacity];
   for(int i = 1; i < ans.size(); i++)
   {
     for (int j = 1; j < ans[0].size(); j++)
     {
         if(wt[i - 1] <= j)
         {
             //return ans[n][capacity] = max(val[n - 1] + knapsack(wt, val, capacity - wt[n - 1], n - 1, ans)
             //0 + knapsack(wt, val, capacity - 0, n - 1, ans));
             ans[i][j] = max(val[i - 1] + ans[i - 1][j - wt[i - 1]], 
                                     0 + ans[i - 1][j]);
         }
         else 
         {
             //return ans[n][capacity] = 0 + knapsack(wt, val, capacity - 0, n - 1, ans);
             ans[i][j] = 0 + ans[i - 1][j];
         }
         
     }
   }
   for(int i = 0; i < ans.size(); i++)
   {
     for(int j = 0; j < ans[0].size(); j++)
     {
         cout << ans[i][j] << " ";
     }
     cout << endl;
   }
   return ans[n][capacity];
}

void subsetgenerator2(vector<int>& given, int n, vector<int> subset, vector<vector<int>>& ans)
{
   if(n == 0)
   {
     ans.push_back(subset);
     return;
   }
   subsetgenerator2(given, n - 1, subset, ans);
   subset.push_back(given[n - 1]);
   subsetgenerator2(given, n - 1, subset, ans);
}

void subsetgenerator3withbacktrack(vector<int>& given, int n, vector<int>& subset, vector<vector<int>>& ans)
{
   if(n == 0)
   {
     ans.push_back(subset);
     return;
   }
   subsetgenerator3withbacktrack(given, n - 1, subset, ans);
   subset.push_back(given[n - 1]);
   subsetgenerator3withbacktrack(given, n - 1, subset, ans);
   subset.pop_back();
}



void subsetWithKElements(vector<int>&given, int k, vector<vector<int>>& ans)
{
   int n = given.size();
   for(int i = 1; i < pow(2, n); i++)
   {
     int z = i;
     vector<int> binary;
     while(z > 0)
     {
         int rem = z % 2;
         binary.push_back(rem);
         z = z / 2;
     }
     int p = n - binary.size();
   
     for(int j = 1; j <= p; j++) binary.push_back(0);
     reverse(binary.begin(), binary.end());
   
     //for(auto elem : binary) cout << elem << " "; cout << endl;
     int cnt = 0;
   
     for(int j = 0; j < binary.size(); j++)
     {
         if(binary[j] == 1) cnt++;
     }
     //cout << cnt << endl;
     if(cnt == k)
     {
         vector<int> subset;
         for(int j = 0; j < binary.size(); j++)
         {
             if(binary[j] == 1) subset.push_back(given[j]);
         }
         ans.push_back(subset);
     }
     //binary.clear();
   }
}
void power(int a, int n)
{
   int res = 1;
   while(n > 0)
   {
     if(n % 2 == 1)
     {
         res *= a;
         n--;
     }
     else 
     {
         a = a * a;
         n = n / 2;
     }
   }
   cout << res << endl;
}

void power(ll a, ll n, ll p)
{
   ll res = 1;
   while(n > 0)
   {
     if(n % 2 == 1)
     {
         res = (res * a) % p;
         n--;
     }
     else
     {
         a = (a * a) % p;
         n /= 2;
     }
   }
   cout << res << endl;
}


bool isPrime(ll n)
{
   if(n <= 1) return false;
   for(ll i = 2; i * i <= n; i++)
   {
     if(n % i == 0) return false;
   }
   return true;
}

void primefact(ll n)
{
   for(ll i = 2; i * i <= n; i++)
   {
     if(n % i == 0)
     {
         int cnt = 0;
         while(n % i == 0)
         {
            n = n / i;
            cnt++;
         }
         cout << i << " ^ " << cnt << endl;
     }
   }
   if(n > 1) cout << n << " ^ " << 1 << endl;
}


void eulertotientfunction(int n)
{
   int res = n;
   for(int i = 2; i * i <= n; i++)
   {
     if(n % i == 0)
     {
         res /= i;
         res *= (i - 1);
     }
     while(n%i == 0) n /= i;
   }
   if(n > 1)
   {
     res /= n;
     res *= n - 1;
   }
   cout << res << endl;
}


void sieveprimefact()
{
   vector<int> a(51, -1);
   a[0] = a[1] = 0;
   for(int i = 2; i < 51; i++)
   {
     if(a[i] == -1)
     {
         for(int j = i; j < 51; j += i)
         {
             if(a[j] == -1) a[j] = i;
         }
     }
   }
   
   
   int n = 40;
   while(n > 1)
   {
     cout << a[n] << " ";
     n /= a[n];
   }
}
int bubblesort(vector<int>& a, vector<int>& b, vector<pair<int, int>>& ans)
{
   int moves = 0;
   int n = a.size();
   for(int i = 0; i < n; i++)
   {
     for(int j = 0; j < n - 1; j++)
     {
         if(a[j] > a[j + 1] || b[j] > b[j + 1]) 
         {
             swap(a[j], a[j + 1]);
             swap(b[j], b[j + 1]);
             ans.push_back({j, j + 1});
             moves++;
         }
     }
   }
   return moves;
}


void solve7()
{
   int n;
   cin >> n;
   vector<int> a(n), b(n);
   for(auto &e : a) cin >> e;
   for(auto &e : b) cin >> e;
   vector<pair<int, int>> ans;
   int moves = bubblesort(a, b, ans);
   bool flag = true;
   for(int i = 0; i < n - 1; i++)
   {
     if(a[i] > a[i + 1] || b[i] > b[i + 1]) flag &= false;
     else flag &= true;
   }
   
   if(flag == false) cout << -1 << endl;
   else
   {
     cout << moves << endl;
     for(auto elem : ans)
     {
         cout << elem.first + 1<< " " << elem.second + 1<< endl;
     }
   }
}



int merge2(vector<pair<int, int>>&c,int left, int mid, int right, vector<pair<int, int>>& temp, vector<pair<int,int>>& ans)
{
   //cout <<"merge2 "<< left<<" " << right << endl;
   int i, j, k, moves = 0;
   i = left, j = mid, k = left;
   while(i <= mid - 1 && j <= right)
   {
     if(c[i].first > c[j].first || (c[i].first == c[j].first && c[i].second > c[j].second ))
     {
         for(int p = j; p >= k + 1; p--)
         {
             ans.push_back({p, p - 1});
             moves++;
         }
         temp[k++] = c[j++];
     }
     else 
     {
         temp[k++] = c[i++];
     }
   }
   while(i <= mid - 1) temp[k++] = c[i++];
   while(j <= right) temp[k++] = c[j++];
   
   for(int i = left; i <= right; i++) c[i] = temp[i];
   return moves;
}

int mergesort2(vector<pair<int, int>>&c,int left, int right, vector<pair<int, int>>& temp, vector<pair<int,int>>& ans)
{
   //cout <<"sort2 "<< left <<" " << right  << endl;
   int moves = 0, mid;
   if(right - left > 0)
   {
     mid = (left + right) / 2;
     moves += mergesort2(c, left, mid, temp, ans);
     moves += mergesort2(c, mid + 1, right,temp, ans);
     moves += merge2(c, left, mid + 1, right, temp, ans);
   }
   return moves;
   }
   
   int mergesort2util(vector<pair<int, int>>&c, vector<pair<int,int>>& ans)
   {
   //cout <<"util" << endl;
   int n = c.size();
   vector<pair<int, int>> temp(n);
   return mergesort2(c, 0, n - 1, temp, ans);
}


void solve1685B()
{
   ll n, a, b, c, d;
   cin >> a >> b >> c >> d;
   string s;
   cin >> s;
   if(count(s.begin(), s.end(), 'A') != a + c + d)
   {
     cout <<"NO" << endl; return;
   }
   
   n = a + b + 2 * c + 2 * d;
   s += string(1, s[n - 1]);
   
   string curr = string(1, s[0]);
   vector<ll> AB, BA;
   ll commoncount = 0;
   
   for(ll i = 1; i <= n; i++)
   {
     if(s[i] == s[i - 1])
     {
         if(curr.size() == 1)
         {
             
         }
         else if(curr.size() & 1)
         {
             commoncount += curr.size() / 2;
         }
         else
         {
             if(curr[0] == 'A') AB.push_back(curr.size() / 2);
             else BA.push_back(curr.size() / 2);
         }
         curr = "";
     }
     curr.push_back(s[i]);
   }
   
   sort(AB.begin(), AB.end());
   sort(BA.begin(), BA.end());
   
   ll cntAB = 0, cntBA = 0, commoncountleft = commoncount;
   
   
   for(auto &x : AB)
   {
     ll req = c - cntAB;
     if(req >= x)
     {
         cntAB += x;
         x = 0;
     }
     else
     {
         cntAB += req;
         x -= req;
     }
   }
   
   for(auto &x : BA)
   {
     ll req = d - cntBA;
     if(req >= x)
     {
         cntBA += x;
         x = 0;
     }
     else
     {
         cntBA += req;
         x -= req;
     }
   }
   
   if(cntAB < c)
   {
     ll required = c - cntAB;
     cntAB += min(required, commoncountleft);
     commoncountleft -= min(required, commoncountleft);
     required = c - cntAB;
     if(required > 0)
     {
         for(auto &x : BA)
         {
             if(x == 0) continue;
             ll req = c - cntAB;
             if(req >= x - 1)
             {
                 cntAB += x - 1;
                 x -= x;
             }
             else
             {
                 cntAB += req;
                 x -= req + 1;
             }
         }
     }
   }
   
   if(cntBA < d)
   {
     ll required = d - cntBA;
     cntBA += min(required, commoncountleft);
     commoncountleft -= min(required, commoncountleft);
     
     required = d - cntBA;
     if(required > 0)
     {
         for(auto &x : AB)
         {
             if(x == 0) continue;
             ll req = d - cntBA;
             if(req >= x - 1)
             {
                 cntBA += x - 1;
                 x -= x;
             }
             else
             {
                 cntBA += req;
                 x -= req + 1;
             }
         }
     }
   }
   if(cntAB >= c && cntBA >= d) cout << "YES" << endl;
   else cout << "NO" << endl;
}


void solve1697C()
{
   int n;
   cin >> n;
   string s, t;
   cin >> s >> t;
   string s2, t2;
   
   for(int i = 0; i < n; i++)
   {
     if(s[i] != 'b') s2.push_back(s[i]);
     if(t[i] != 'b') t2.push_back(t[i]);
   }
   //cout << s2 << endl << t2 <<endl;
   if(s2 != t2) {cout << "NO" << endl; return;}
   
   vector<int>saindx, taindx;
   for(int i = 0; i < n; i++)
   {
     if(s[i] == 'a') saindx.push_back(i);
     if(t[i] == 'a') taindx.push_back(i);
   }
   //for(auto elem : saindx) cout << elem <<" "; cout << endl;
   //for(auto elem : taindx) cout << elem <<" "; cout << endl;
   
   for(int i = 0; i < saindx.size(); i++)
   {
     if(saindx[i] > taindx[i])
     {
         cout << "NO" << endl; return;
     }
   }
   
   vector<int>scindx, tcindx;
   for(int i = 0; i < n; i++)
   {
     if(s[i] == 'c') scindx.push_back(i);
     if(t[i] == 'c') tcindx.push_back(i);
   }
   //for(auto elem : scindx) cout << elem <<" "; cout << endl;
   //for(auto elem : tcindx) cout << elem <<" "; cout << endl;
   
   for(int i = 0; i < scindx.size(); i++)
   {
     if(scindx[i] < tcindx[i])
     {
         cout << "NO" << endl; return;
     }
   }
   cout << "YES" << endl;
}

bool targetsum(vector<int>& a, int sum, int n, vector<vector<int>>& ans) 
{
   if(sum == 0) return true;
   if(n == 0 && sum > 0) return false;
   
   if(ans[n][sum] != -1) return ans[n][sum];
   
   if(a[n - 1] <= sum)
   {
     return ans[n][sum] = targetsum(a, sum - a[n - 1], n - 1, ans) || targetsum(a, sum, n - 1, ans);
   }
   else
   {
     return ans[n][sum] = targetsum(a, sum, n - 1, ans);
   }
}


void solve1527B1()
{
   int n;
   cin >> n; 
   string s;
   cin >> s;
   ll cnt = count(s.begin(), s.end(), '0');
   if(cnt == 1 || cnt % 2 == 0) cout << "BOB" << endl;
   else cout << "ALICE" << endl;

}

void solve1674E()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(auto &e : a) cin >> e;
   int ans = INF;
   for(int i = 0; i <= n - 3; i++)
   {
      int currans = (a[i] + a[i + 2] + 1) / 2;
      ans = min(ans, currans);
   }
   
   for(int i = 0; i <= n - 2; i++)
   {
      int x = max(a[i], a[i + 1]);
      int y = min(a[i], a[i + 1]);
      if(2 * y <= x)
      {
         int currans = (x + 1) / 2;
         ans = min(currans, ans);
      }
      else
      {
         int currans = x - y;
         x = 2 * y - x;
         y = x;
         currans += (x * 2 + 2) / 3;
         ans = min(ans, currans);
      }
   }
   sort(a.begin(), a.end());
   int currans = (a[0] + 1) / 2 + (a[1] + 1) / 2;
   ans = min(currans, ans);
   cout << ans << endl;

}


void solve1406B()
{
   ll n;
   cin >> n;
   vector<int> a(n);
   for(auto &e : a) cin >> e;
   sort(a.begin(), a.end());
   ll ans = -1e18;
   for(int i = 0; i <= 5; i++)
   {
      int ee = (n - 1 + i) % n;
      int dd = (n - 2 + i) % n;
      int cc = (n - 3 + i) % n;
      int bb = (n - 4 + i) % n;
      int aa = (n - 5 + i) % n;
      ll curr = a[ee] * 1ll * a[dd] * a[cc] * a[bb] * a[aa];
      ans = max(ans, curr);
   }
   cout << ans << endl;

}

void solve1692F()
{
   int n; 
   cin >> n;
   vector<int> cnt(10, 0);
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      cnt[x % 10]++;
   }
   
   vector<int> a;
   for(int i = 0; i < 10; i++)
   {
      for(int j = 0; j < min(3, cnt[i]); j++) a.push_back(i);
   }
   
   int sz = a.size();
   for(int i = 0; i < sz; i++)
   {
      for(int j = i + 1; j < sz; j++)
      {
         for(int k = j + 1; k < sz; k++)
         {
            if((a[i] + a[j] + a[k]) % 10 == 3) 
            {
               cout << "YES" << endl;
               return;
            }
         }
      }
   }
   cout <<"NO" << endl;
}

void solve1692G()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n), b(n - 1, 0), pref(n - 1, 0);
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i <= n - 2; i++)
   {
      if(a[i] < 2 * a[i + 1]) b[i] = 1;
      else b[i] = 0;
   }
   
   //prefix sum
   pref[0] = b[0];
   for(int i = 1; i <= n - 2; i++) pref[i] = pref[i - 1] + b[i];
   
   int ans = 0;
   for(int i = 0; i <= n - k - 1; i++)
   {
      if(i == 0 && pref[i + k - 1] == k) ans++; 
      else if(pref[i + k - 1] - pref[i - 1] == k) ans++;
   }
   
   cout << ans << endl;
   
   //sliding window
   /*int curr = 0, res = 0;
   for(int i = 0; i < k; i++)
   {
      curr += b[i];
   }
   
   if(curr == k) res++;
   for(int i = k, j = 0; i <= n - 2; i++)
   {
      curr += b[i];
      curr -= b[j++];
      if(curr == k) res++;
   }
   cout << res << endl;*/
}

void solve1694B()
{
   int n;
   cin >> n;
   vector<int> a;
   string s;
   cin >> s;
   for(int i = 0; i <= n - 2; i++)
   {
      if(s[i] != s[i + 1]) a.push_back(1);
      else a.push_back(0);
   }
   //for(auto elem : a) cout << elem << " "; cout << endl;
   ll cnt = ((n + 1) * 1ll * n) / 2;
   
   for(int i = 0; i < a.size(); i++)
   {
      if(a[i] == 1) continue;
      cnt--;
      cnt = cnt - i;
   }
   cout << cnt << endl;
}

void solve1694A()
{
   int zeros, ones;
   cin >> zeros >> ones;
   string s;
   int diff = abs(zeros - ones);
   if(diff > min(zeros, ones))
   {
      if(zeros < ones)
      {
         s += string(zeros, '0');
         s += string(ones, '1');
      }
      else
      {
         s += string(ones, '1');
         s += string(zeros, '0');
      }
   }
   else if(diff == 0)
   {
      for(int i = 1; i <= zeros + ones; i++)
      {
         if(i % 2 == 1) s += '1';
         else s += '0';
      }
   }
   else
   {
     while(zeros > 0 && ones > 0)
      {
         if(zeros >= diff)
         {
            s += string(diff, '0');
            zeros -= diff;
         }
         else
         {
            s += string(zeros, '0');
            zeros = 0;
         }
         
         if(ones >= diff)
         {
            s += string(diff, '1');
            ones -= diff;
         }
         else
         {
            s += string(ones, '1');
            ones = 0;
         }
         
      }
      if(zeros > 0) {s+= string(zeros, '0');}
      if(ones > 0) {s += string(ones, '1');}
   }
   cout << s << endl;
}
void solve1695B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   int mn = INT_MAX;
   int mnindx = -1;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(a[i] < mn)
      {
         mn = a[i];
         mnindx = i;
      }
   }
   if(n % 2 == 0)
   {
      if(mnindx % 2 == 0) cout << "Joe" << endl;
      else cout << "Mike" << endl;
   }
   else cout << "Mike" << endl;
}

void solve1692H()
{
   int n;
   cin >> n;
   vector<int>a(n);
   for(auto& e : a) cin >> e;
   vector<int>dp(n, 1);
   map<int, int> pos;
   int idx = -1, ma = 0;
   for(int i = 0; i < n; i++)
   {
      if(pos.count(a[i]))
      {
         dp[i] = max(dp[i], dp[pos[a[i]]] + 1 - (i - pos[a[i]] - 1));
      }
      if(dp[i] > ma)
      {
         ma = dp[i];
         idx = i;
      }
      pos[a[i]] = i;
   }
   
   int r = idx;
   int l = idx;
   int p = a[l];
   
   /*while(ma)
   {
      if(a[l] == p) ma--;
      else ma++;
      l--;
   }
   cout << p << " " << l + 2 << " " << r + 1 << endl;*/
   for(; l>= 0; l--)
   {
      if(dp[l] == 1 && a[l] == p) break;
   }
   
   cout << p << " " << l + 1 << " " << r + 1 << endl;
}

void solve1694C()
{
   ll n;
   cin >> n;
   vector<ll> a(n), pref(n, 0);
   int mark = -1;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(a[i] != 0) mark = i;
      if(i == 0) pref[i] = a[i];
      else pref[i] = pref[i - 1] + a[i];
   }
   for(int i = 0; i < n; i++)
   {
      if(pref[i] < 0) 
      {
         cout << "NO" << endl; 
         return;
      }
      if(pref[i] == 0)
      {
         while(i < n)
         {
            if(pref[i] != 0)
            {
               cout << "NO" << endl; return;
            }
            i++;
         }
      }
   }
   if(mark == -1 || pref[mark] == 0)cout << "YES" << endl;
   else cout << "NO" << endl;
   
}

void solve1700B()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   n = s.size();
   string fir = string(n, '9');
   //cout << fir << endl;
   string sec = string(n + 1, '1');
   string num1, num2;
   for(int i = n - 1; i >= 0; i--)
   {
      num1 += to_string((fir[i] - '0') - (s[i] - '0'));
   }
   reverse(num1.begin(), num1.end());
   int i = 0;
   while(num1[i] == '0')
   {
      i++;
   }
   if(i == 0) {cout << num1 << endl; return;}
   string s1 = "0";
   s1 += s;
   s = s1;
   n++;
   //cout << s << endl;
   int carry = 0;
   for(int i = n - 1; i >= 0; i--)
   {
      int fn = sec[i] - '0';
      int sn = (s[i] - '0') + carry;
      int add = 0;
      if(fn < sn)
      {
         fn += 10;
         add = fn - sn;
         carry = 1;
      }
      else
      {
         add = fn - sn;
         carry = 0;
      }
      num2 += to_string(add);
   }
   reverse(num2.begin(), num2.end());
   i = 0;
   while(num2[i] == '0') i++;
   num2 = num2.substr(i);
   cout << num2 << endl;
   
}

void solve1692E()
{
   int n, s;
   cin >> n >> s;
   vector<int> a;
   int sum = 0, mov = 0;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      if(x == 1) a.push_back(i);
      sum += x;
   }
   //cout << "sum : " << sum << " s :"<< s << endl;
   //for(auto elem : a) cout << elem << " "; cout << endl;
   if(sum < s) cout << -1 << endl; 
   else if (sum == s) cout << 0 << endl;
   else
   {
      int left = 0, right = n - 1;
      int p = a.size();
      int i = 0, j = p - 1;
      int cleft = a[i], cright = a[j];
      while(sum > s)
      {
         if(left > right) break;
         
         int lmov = cleft - left + 1;
         int rmov = right - cright + 1;
         
         //cout << "right : "<< right << " cright :" << cright << endl;
         
         if(lmov < rmov)
         {
            mov += lmov;
            left = cleft + 1;
            cleft = a[++i];
         }
         else 
         {
            mov += rmov;
            right = cright - 1;
            cright = a[--j];
         }
         sum--;
      }
      cout << mov << endl;
   }
}

void solve1360D()
{
   int n, k;
   cin >> n >> k;
   vector<int> divisors;
   for(int i = 1; i * i<= n; i++)
   {
      if(n % i == 0) 
      {
         divisors.push_back(i);
         if(i != n / i) divisors.push_back(n / i);
      }
   }
   sort(divisors.begin(), divisors.end());
   //for(auto elem : divisors) cout << elem << " "; cout << endl;
   if(binary_search(divisors.begin(), divisors.end(), k))
   {
      cout << n / k << endl;
   }
   else
   {
      int indx = lower_bound(divisors.begin(), divisors.end(), k) - divisors.begin();
      k = divisors[--indx];
      cout << n / k << endl;
   }
}

void solve1647B()
{
   int n, m;
   cin >> n >> m;
   vector<vector<int>> a(n, vector<int>(m));
   for(int i = 0; i < n; i++)
   {
      string s;
      cin >> s;
      for(int j = 0; j < m; j++) 
      {
         if(s[j] == '0') a[i][j] = 0;
         else a[i][j] = 1;
      }
   }
   
   for(int i = 0; i <= n - 2; i++)
   {
      for(int j = 0; j <= m - 2; j++)
      {
         int cnt = 0;
         for(int curr = i; curr <= i + 1; curr++)
         {
            for(int curr2 = j; curr2 <= j + 1; curr2++)
            {
               //cout << curr << " " << curr2 << endl;
               if(a[curr][curr2] == 1) cnt++;
               //cout << "cnt :" << cnt << endl;
            }
         }
         if(cnt == 3) 
         {
            cout << "NO" << endl;
            return;
         }
      }
   }
   cout << "YES" << endl;
}

void solve1637C()
{
   int n;
   cin >> n;
   vector<int> a(n);
   bool allones = true;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   for(int i = 1; i <= n - 2; i++)
   {
      if(a[i] > 1) allones &= false;
   }
   if(allones == true || (n == 3 && a[1] % 2 == 1))
   {
      cout << -1 << endl;
      return;
   }
   
   ll mov = 0;
   for(int i = 1; i <= n - 2; i++)
   {
      mov += (a[i] + 1) / 2;
   }
   cout << mov << endl;
}

void solve1690E()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      ans += a[i] / k;
      a[i] %= k;
   }
   
   sort(a.begin(), a.end());
   int l = 0, r = n - 1;
   while(r - l > 0)
   {
      if(a[l] + a[r] >= k)
      {
         ans++; r--; l++;
      }
      else l++;
   }
   cout << ans << endl;
}


void solve1696B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   a.push_back(0);
   int l = 0, r = 0;
   int segs = 0;
   for(r = 0; r <= n; r++)
   {
      //cout << "entering r "<< r << endl;
      if(a[r] == 0)
      {
         if(a[l] != 0)
         {
            segs++;
         }
         while(r <= n && a[r] == 0)
         {
            r++;
         }
         if(r > n) break;
         //cout << r << endl;
         l = r;
         //r--;
      }
      
   }
   //if(l < n) segs++;
   //cout << segs << endl;
   cout << min(segs, 2) << endl;
}


void solve1696A()
{
   int n, z;
   cin >> n >> z;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   
   ll maxi = 0;
   ll prevmaxi = -1;
   ll prevz = -1;
   ll ind = -1;
   while(prevmaxi != maxi)
   {
      for(int i = 0; i < n; i++)
      {
         //cout << "maxi" << maxi << endl;
         //cout << "or : " << (a[i] | z) << endl;
         if((a[i] | z) > maxi)
         {
            maxi = a[i] | z;
            ind = i;
         }
      }
      //prevz = z;
      z = a[ind] & z;
      a[ind] = maxi;
      prevmaxi = maxi;
   }
   cout << maxi << endl;
}

void solve1689B()
{
   int n;
   cin >> n;
   vector<int> a(n + 1), b(n + 1);
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      b[a[i]] = i;
   }
   //for(auto elem : b) cout << elem << " "; cout << endl;
   
   sort(a.begin(), a.end());
   for(int i = 1; i <= n; i++)
   {
      if(i < n && b[a[i]] == i)
      {
         //cout << "if swap" << endl;
         swap(a[i], a[i + 1]);
      }
      else if(i == n && b[a[i]] == i)
      {
         //cout << "else swap" << endl;
         //cout << a[i] << " " << a[i - 1] << endl;
         swap(a[i], a[i - 1]);
      }
      //for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
   }
   if(n == 1){cout << -1 << endl; return;}
   for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
}



void solve1689C()
{
   int n;
   cin >> n;
   vector<vector<int>> g(n + 1);
   for(int i = 1; i <= n - 1; i++)
   {
      int u, v;
      cin >> u >> v;
      if(u < v) g[u].push_back(v);
      else g[v].push_back(u);
   }
   
}

void solve1535B()
{
   int n;
   cin >> n;
   vector<int>a(n);
   for(auto& e : a) cin >> e;
   sort(a.begin(), a.end(), [](int x, int y) {return x  % 2 < y % 2;});
   for(auto elem : a) cout << elem << " "; cout << endl;
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      for(int j = i + 1; j < n; j++)
      {
         if(__gcd(a[i], 2 * a[j]) > 1) ans++;
      }
   }
   //cout << ans << endl;
}

void solve1350A()
{
   int n, k;
   cin >> n >> k;
   int mini = n;
   for(int i = 2; i * i <= n; i++)
   {
      if(n % i == 0)
      {
         mini = i;
         break;
      }
   }
   ll ans = 0;
   ans = n + mini + (2 * 1ll * (k - 1));
   cout << ans << endl;
}

void solve567A()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < n; i++)
   {
      int mini = INT_MAX;
      int maxi = INT_MIN;
      if(i > 0 && i < n - 1)
      {
         mini = min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1]));
         maxi = max(abs(a[i] - a[0]), abs(a[i] - a[n - 1]));
      }
      else if(i == 0)
      {
         mini = abs(a[0] - a[1]);
         maxi = abs(a[0] - a[n - 1]);
      }
      else
      {
         mini = abs(a[n - 1] - a[n - 2]);
         maxi = abs(a[0] - a[n - 1]);
      }
      cout << mini << " " << maxi << endl;
   }
}


bool check2(ll mid, ll x, ll k)
{
   ll sum = 0, rem = 2 * k - 1 - mid; 
   if(mid < k) sum = (mid * 1ll * (mid + 1)) / 2;
   else sum = (k * 1ll * k) - ((rem * 1ll * (rem + 1)) / 2);
   return sum <= x;
}
ll check3(ll mid, ll x, ll k)
{
   ll sum = 0, rem = 2 * k - 1 - mid;
   if(mid < k) sum = (mid * 1ll * (mid + 1)) / 2;
   else sum = (k * 1ll * k) - ((rem * 1ll * (rem + 1)) / 2);
   return x - sum;
}
void solve1612C()
{
   ll k, x, ans;
   cin >> k >> x;
   ll lo = 1, hi = 2 * k - 1;
   while(hi - lo > 1)
   {
      ll mid = (hi + lo) / 2;
      if(check2(mid, x, k)) lo = mid;
      else hi = mid;
   }
   
   if(lo != hi && check2(lo, x, k) && check3(lo, x, k) > 0ll) ans = lo + 1;
   else ans = lo;
   cout << ans << endl;
}

void solve268B()
{
   int n;
   cin >> n;
   ll sum = n;
   for(int i = n - 1; i >= 1; i--)
   {
      sum += i * 1ll * (n - i);
   }
   cout << sum << endl;
}

void solve1433C()
{
   int n, maxi = 0;
   cin >> n;
   vector<int> a(n), b;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      a[i] = x;
      maxi = max(maxi, a[i]);
   }
   int cnt = 0;
   for(int i = 0; i < n; i++)
   {
      if(a[i] == maxi) cnt++;
      else a[i] = 0;
   }
   if(cnt == n) cout << -1 << endl;
   else
   {
      for(int i = 0; i < n; i++)
      {
         if(a[i] == maxi)
         {
            if(i >= 1 && i <= n - 2 && a[i - 1] == 0 || a[i + 1] == 0)
            {
               cout << i + 1 << endl;
               break;
            }
            else if(i == 0 && a[i + 1] == 0)
            {
               cout << i + 1 << endl;
               break;
            }
            else if(i == n - 1 && a[i - 1] == 0)
            {
               cout << i + 1 << endl;
               break;
            }
         }
      }
   }
}

void solve1324A()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(auto & e: a) cin >> e;
   bool fl = true;
   for(int i = 0; i < n - 1; i++)
   {
      if( (abs(a[i] - a[i + 1])) % 2 != 0) fl = false;
   }
   if(fl) cout << "YES" << endl;
   else cout << "NO" << endl;
}


void solveEduCourse2Lesson93PracticeE()
{
   int n, s;
   cin >> n >> s;
   vector<int> w(n), c(n);
   for(int i = 0; i < n; i++) cin >> w[i];
   for(int i = 0; i < n; i++) cin >> c[i];
   
   int l = 0, r = 0;
   ll ans = 0, weight = 0, cost = 0;
   for(r = 0; r < n; r++)
   {
      weight += w[r];
      cost += c[r];
      while(weight > s)
      {
         weight -= w[l];
         cost -= c[l];
         l++;
      }
      //cout << cost << endl;
      ans = max(ans, cost);
   }
   cout << ans << endl;
}

void solve1702D()
{
   string s;
   cin >> s;
   ll w, sum = 0;
   cin >> w;
   vector<int>a(27, 0);
   for(int i = 0; i < s.size(); i++)
   {
      a[s[i] - 'a' + 1]++;
      sum += s[i] - 'a' + 1;
   }
   //cout << sum << endl;
   //for(auto elem : a) cout << elem << " " ; cout << endl;
   if(w >= sum) 
   {
      cout << s << endl;
      return;
   }
   string ans;
   while(sum > w)
   {
      ll need = 26;
      while(need >= 1 && a[need] == 0) need--;
      if(need >= 1)
      {
         sum -= need;
         a[need]--;
      }
      else break;
      
   }
   //for(auto elem : a) cout << elem << " " ; cout << endl;
   for(int i = 0; i < s.size(); i++)
   {
      if(a[s[i] - 'a' + 1] > 0) 
      {
         a[s[i] - 'a' + 1]--;
         ans += s[i];
      }
   }
   cout << ans << endl;
}

void solve1702A()
{
   int s;
   cin >> s;
   int zeroes = log10(s);
   cout << s - (int) pow(10, zeroes) << endl;
}

void solve1702B()
{
   string s;
   cin >> s;
   int n = s.size();
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      vector<int>f(26, 0);
      int cnt = 0, j = i;
      while(j < n && cnt <= 3)
      {
         
         //cout << s[j] << endl;
         if(j < n && f[s[j] - 'a'] == 0)
         {
            f[s[j] - 'a']++;
            cnt++;
            if (cnt > 3) break;
            j++;
         }
         else if(j < n && f[s[j] - 'a'] > 0)
         {
            j++;
         }
      }
      if(cnt > 3 || j >= n) ans++;
      i = j - 1;
   }
   cout << ans << endl;
}

void solve1702C()
{
   int n, q;
   cin >> n >> q;
   map<int, vector<int>> b;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      b[x].push_back(i);
   }
   
   while(q--)
   {
      int u, v;
      cin >> u >> v;
      if(b[u].size() == 0 || b[v].size() == 0)
      {
         cout << "NO" << endl;
         continue;
      }
      if(b[u].front() < b[v].back())
      {
         cout << "YES" << endl;
         continue;
      }
      else
      {
         cout << "NO" << endl;
         continue;
      }
   }
}

void solve1703D()
{
   int n;
   cin >> n;
   vector<string>a(n);
   set<string>st;
   for(int i = 0; i < n; i++)
   {
      string s;
      cin >> s;
      a[i] = s;
      st.insert(s);
   }
   
   string ans;
   for(int i = 0; i < n; i++)
   {
      string curr = a[i];
      int n = curr.size();
      bool found = false;
      for(int i = 0; i <= n - 2; i++)
      {
         string fi = curr.substr(0, i + 1);
         string se = curr.substr(i + 1);
         if(st.find(fi) != st.end() && st.find(se) != st.end())
         {
            found = true;
            break;
         }
      }
      if(found) ans += '1';
      else ans += '0';
   }
   cout << ans << endl;
   
}

void solve1703A()
{
   string s;
   cin >> s;
   if( (s[0] == 'y' || s[0] == 'Y' ) && (s[1] == 'e' || s[1] == 'E') && (s[2] == 's' || s[2] == 'S') )
   {
      cout << "YES" << endl;
   }
   else cout << "NO" << endl;
}

void solve1703B()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   set<char> st;
   int ans = 0;
   for(int i = 0; i < n; i++)
   {
      if(st.find(s[i]) == st.end())
      {
         ans += 2;
      }
      else ans += 1;
      st.insert(s[i]);
   }
   cout << ans << endl;
}

void solve1703C()
{
   int n;
   cin >> n;
   vector<int>a(n);
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   
   for(int i = 0; i < n; i++)
   {
      int t;
      cin >> t;
      string s;
      cin >> s;
      
      for(int j = 0; j < t; j++)
      {
         if(s[j] == 'D')
         {
            a[i] = (a[i] + 1) % 10;
         }
         else 
         {
            a[i] = (a[i] - 1 + 10) % 10;
         }
      }
      
   }
   
   for(int i = 0; i < n; i++)
   {
      cout << a[i] << " ";
   }
   cout << endl;
}

void solve1703F()
{
   int n;
   cin >> n;
   vector<int> a(n + 1);
   vector<pair<int, int>> b;
   for(int i = 1; i <= n; i++) 
   {
      cin >> a[i];
      if(a[i] < i)
      {
         b.push_back({a[i], i});
      }
   }
   
   sort(b.begin(), b.end());
   
   //for(auto elem : b) cout <<"(" << elem.first << " " << elem.second <<")"; cout << endl;
   
   int sz = b.size();
   ll ans = 0;
   for(int i = 0; i < sz; i++)
   {
      int lo = i + 1, hi = sz - 1, x = -1;
      
      while(lo <= hi)
      {
         int mid = (lo + hi) / 2;
         if(b[i].second >= b[mid].first || b[i].second >= b[mid].second)
         {
            lo = mid + 1;
         }
         else
         {
            x = mid;
            hi = mid - 1;
            //if(i == 5)cout << x << endl;
         }
      }
      if(x != -1)
      {
         //cout << sz - x << endl;
         ans += sz - x;
      }
   }
   cout << ans << endl;
}

void solve1703E()
{
   int n;
   cin >> n;
   vector<vector<int>> a(n, vector<int> (n));
   for(int i = 0; i < n; i++)
   {
      string s;
      cin >> s;
      for(int j = 0; j < n; j++)
      {
         if(s[j] == '0') a[i][j] = 0;
         else a[i][j] = 1;
      }
   }
   int i = 0, j = n - 1;
   ll ans = 0;
   while(i < j)
   {
      //cout << i << " i and j " << j << endl;
      for(int k = 0; i + k < j; k++)
      {
         //cout << i << " " << i + k << endl;
         //cout << i + k << " " << j << endl;
         //cout << j - k << " " << i << endl;
         //cout << j << " " << j - k << endl;
         int cnt1 = 0;
         if(a[i][i + k] == 1) cnt1++;
         if(a[i + k][j] == 1) cnt1++;
         if(a[j - k][i] == 1) cnt1++;
         if(a[j][j - k] == 1 ) cnt1++;
         
         //cout << cnt1 << endl;
         ans += min(cnt1, 4 - cnt1);
      }
      i++, j--;
   }
   cout << ans << endl;
   
}

void solve1097B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   vector<vector<int>> dp(n + 1);
   dp[0].push_back(0);
   
   for(int i = 1; i <= n; i++)
   {
      int curr = a[i - 1];
      for(auto elem : dp[i - 1])
      {
         dp[i].push_back((elem + curr) % 360);
      }
      for(auto elem : dp[i - 1])
      {
         dp[i].push_back((elem - curr + 360) % 360);
      }
   }
   
   //for(auto elem : dp)
   {
      //for(auto e : elem) cout << e << " "; cout << endl;
   }
   
   for(int i = 0; i < dp[n].size(); i++)
   {
      //cout << dp[n][i] << " "; 
      if(dp[n][i] == 0 || dp[n][i] == 360) 
      {
         cout << "YES" << endl;
         return;
      }
   }
   cout << "NO" << endl;
}


void solve1294C()
{
   int n, n1;
   cin >> n;
   n1 = n;
   set<int> a;
   int cnt = 0;
   for(int i = 2; i * i <= n1; i++)
   {
      //cout << "i " << i << endl;
      if(n % i == 0 && a.find(i) == a.end())
      {
         a.insert(i);
         n /= i;
         cnt++;
      }
      if(cnt == 2) break;
   }
   if(n > 1) a.insert(n);
   
   //for(auto elem : a) cout << elem << " "; cout << endl;
   //cout << n << endl;
   if(a.size() == 3) 
   {
      cout << "YES" << endl;
      for(auto elem : a) cout << elem << " "; cout << endl;
   }
   else cout << "NO" << endl;
}

void solve1705B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   ll ans = 0;
   ll moves = 0;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(i < n - 1)
      {
         ans += a[i];
         if(a[i] == 0) 
         {
            if(i >= 1 && a[i - 1] != 0)
            {
               moves++;
               a[i]++;
               a[i - 1]--;
            }
         }
         
      }
   }
   ans += moves;
   cout << ans << endl;
}

void solve1705C()
{
   ll n, c, q;
   cin >> n >> c >> q;
   string s;
   cin >> s;
   vector<pair<ll,ll>>len(c), query(c);
   
   ll curr = n;
   for(ll i = 0; i < c; i++)
   {
      ll l, r;
      cin >> l >> r;
      ll qlen = r - l + 1;
      query[i].first = l;
      query[i].second = r;
      
      len[i].first = curr + 1;
      len[i].second = curr + qlen;
      curr = curr + qlen;
      
   }
   //for(auto elem : query) cout <<"(" << elem.first <<" " << elem.second <<")"; cout << endl;
   
   //for(auto elem : len) cout <<"(" << elem.first <<" " << elem.second <<")"; cout << endl;
   while(q--)
   {
      ll idx;
      cin >> idx;
      for(ll i = c - 1; i >= 0; i--)
      {
         //cout <<i << " "<<  idx << " " << len[i].first << " " << len[i].second << endl;
         if(idx >= len[i].first && idx <= len[i].second)
         {
            ll gap = idx - len[i].first;
            idx = gap + query[i].first;
            
         }
      }
      cout << s[--idx] << endl;
   }
}


void solve1708B()
{
   int n, l, r;
   //cout << "HI" << endl;
   cin >> n >> l >> r;
   vector<ll> a(n + 1, 0);
   a[1] = l;
   
   for(int i = 2; i < n + 1; i++)
   {
      //cout << "for" << endl;
      if((l % i) == 0)
      {
          //cout << "divisibel";
         a[i] = l;
      }
      else
      {
         ll k = ((l / i) + 1) * 1ll * i;
         //cout << k << endl;
         if(k >= l && k <= r) 
         {
             //cout << "not";
             a[i] = k;
         }
      }
   }
   for(int i = 1; i < n + 1; i++)
   {
       if(a[i] == 0) 
       {
           cout << "NO" << endl;
           return;
       }
   }
   cout << "YES" << endl;
   for(int i = 1; i < n + 1; i++) cout << a[i] << " "; cout << endl;
}


void solve1708A()
{
   int n;
   cin >> n;
   vector<int> a(n);
   bool fl = false;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      
   }
   for(int i = 1; i < n; i++)
   {
      a[i] = a[i] % a[0];
   }
   for(int i = 1; i < n; i++)
   {
      if(a[i] != 0) 
      {
         cout <<"NO" << endl;
         return;
      }
   }
   cout << "YES" << endl;
}


void solve1698C()
{
   int n;
   cin >> n;
   vector<int> pos, neg, a;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      if(x > 0) pos.push_back(x);
      
      else if(x < 0) neg.push_back(x);
      else
      {
         if(a.size() < 2) a.push_back(x);
      }
   }
   
   if(pos.size() > 2 || neg.size() > 2) 
   {
      cout <<"NO" << endl;
      return;
   }
   
   for(auto elem : pos) a.push_back(elem);
   for(auto elem : neg) a.push_back(elem);
   int sz = a.size();
   
   for(int i = 0; i < sz; i++)
   {
      for(int j = i + 1; j < sz; j++)
      {
         for(int k = j + 1; k < sz; k++)
         {
            int sum = a[i] + a[j] + a[k];
            bool fl = false;
            for(int l = 0; l < sz; l++)
            {
               if(a[l] == sum)
               {
                  fl = true;
               }
            }
            if(fl == false) 
            {
               cout << "NO" << endl;
               return;
            }
         }
      }
   }
   cout << "YES" << endl;
}

void solve1708C()
{
   int n, q;
   cin >> n >> q;
   vector<int> v(n),good, bad;
   for(int i = 0; i < n; i++) cin >> v[i];
   
   for(int i = 0; i < n; i++)
   {
      if(v[i] > q) bad.push_back(i);
      else good.push_back(i);
   }
   
   ll low = 0, high = (int)bad.size() - 1, ans = n;
   
   while(low <= high)
   {
      ll mid = (low + high) / 2;
      ll ok = 1, curr_iq = q;
      
      for(int i = bad[mid]; i < n; i++)
      {
         if(curr_iq == 0) ok = 0;
         if(v[i] > curr_iq) curr_iq--;
      }
      if(ok == 1)
      {
         ans = bad[mid];
         high = mid - 1;
      }
      else low = mid + 1;
   }
   
   for(int i = 0; i < ans; i++)
   {
      if(v[i] <= q) cout << 1;
      else cout << 0;
   }
   for(int i = ans; i < n; i++)
   {
      cout << 1;
   }
   cout << endl;
   
}

void solve1667A()
{
   int n;
   cin >> n;
   vector<int> a(n), b(n, 0);
   for(int i = 0; i < n; i++) cin >> a[i];
   ll ans = (int)1e9 + 7;
   for(int i = 0; i < n; i++)
   {
      ll moves = 0;
      ll curr = 0;
      for(int j = i - 1; j >= 0; j--)
      {
         //cout << a[j] << " ";
         if(a[j] >= curr)
         {
            if(curr == 0) 
            {
               curr = a[j] * (-1);
               moves += 1;
            }
            else
            {
               
               ll divi = curr / a[j];
               if (divi > 0) divi++;
               else divi--;
               
               curr = divi * a[j];
               moves += abs(curr / a[j]);
            }
         }
         else {curr = a[j]; moves++;}
      }
      
      curr = 0;
      for(int j = i + 1; j < n; j++)
      {
         if(a[j] <= curr)
         {
            if(curr == 0) 
            {
               curr = a[j] * (-1);
               moves += 1;
            }
            else
            {
               ll divi = curr / a[j];
               if(divi > 0) divi++;
               else divi--;
               curr = divi * a[j];
               moves += abs(curr / a[j]);
            }
         }
         else {curr = a[j]; moves++;} 
      }
      ans = min(moves, ans);
   }
   cout << ans << endl;
}


void solve1706B()
{
   int n;
   cin >> n;
   vector<int> a(n + 1), ans(n + 1, 0);
   vector<vector<int>> b(n + 1);
   
   
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      b[a[i]].push_back(i);
   }
   
   /*for(auto elem : b)
   {
      for (auto e : elem) cout << e << " ";
      cout << endl;
   }*/
   for(int i = 1; i <= n; i++)
   {
      if(b[i].size() == 0) continue;
      //cout << b[i].size() << endl;
      int cnt = 0;
      for(int j = 0; j < b[i].size() - 1; j++)
      {
         //cout << b[i][j + 1] << " " << b[i][j] << endl;
         if((b[i][j + 1] - b[i][j] - 1) % 2 == 0) 
         {
            cnt++;
         }
      }
      ans[i] = cnt + 1;
   }
   
   
   for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}


void solve1706A()
{
   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   for(int i = 0; i < n; i++) {int x; cin >> x; x--; a[i] = x;}
   string s(m, 'B');
   
   for(int i = 0; i < n; i++)
   {
      int first = a[i];
      int second = m - 1 - a[i];
      if(first < second)
      {
         if(s[first] == 'B') s[first] = 'A';
         else s[second] = 'A';
      }
      else
      {
         if(s[second] == 'B') s[second] = 'A';
         else s[first] = 'A';
      }
   }
   cout << s << endl;
   
}

void solve1706C()
{
   ll n; 
   cin >> n;
   vector<ll> a(n);
   for(auto &e : a) cin >> e; 
   ll ans = 1e18;
   
   if(n % 2 == 1)
   {
      ans = 0;
      for(ll i = 1; i < n; i += 2)
      {
         ans += max(0ll, max(a[i - 1], a[i + 1]) - a[i] + 1);
      }
   }
   
   else
   {
      vector<ll> pref(n + 1, 0), suff(n, 0);
      
      for(ll i = 1; i + 1 < n; i += 2)
      {
         pref[i + 1] = pref[i - 1] + max(0ll, max(a[i - 1], a[i + 1]) - a[i] + 1);
      }
      
      for(ll i = n - 2; i - 1 >= 0; i -= 2)
      {
         suff[i - 1] = suff[i + 1] + max(0ll, max(a[i - 1], a[i + 1]) - a[i] + 1);
      }
      
      for(ll i = 0; i < n; i += 2)
      {
         ans = min(ans, pref[i] + suff[i + 1]);
      }
   }
   cout << ans << endl;
}

void solve1699B()
{
   int n, m;
   cin >> n >> m;
   for(int i = 0; i < n; i++)
   {
      bool z = false, o = false;
      if(i % 4 == 0 || i % 4 == 3) z = true;
      else o = true;
      for(int j = 0; j < m; j++)
      {
         if(z == true)
         {
            if(j % 4 == 0 || j % 4 == 3) cout << 0 << " ";
            else cout << 1 << " ";
         }
         else if(o == true)
         {
            if(j % 4 == 0 || j % 4 == 3) cout << 1 << " ";
            else cout << 0 << " ";
         }
      }
      cout << endl;
      z = false;
      o = false;
   }
}




void solve1709B()
{
   ll n, m;
   cin >> n >> m;
   vector<ll> a(n + 1), pref(n + 1, 0), suff(n + 1, 0);
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
   }
   
   for(int i = 1; i + 1 <= n; i++)
   {
      if(a[i + 1] < a[i]) pref[i + 1] = pref[i] + abs(a[i] - a[i + 1]);
      else pref[i + 1] = pref[i];
   }
   
   for(int i = n; i - 1 >= 1; i--)
   {
      if(a[i - 1] < a[i]) suff[i - 1] = suff[i] + abs(a[i] - a[i - 1]);
      else suff[i - 1] = suff[i];
   }
   
   //for(int i = 1; i <= n; i++) cout << pref[i] << " "; cout << endl;
   //for(int i = 1; i <= n; i++) cout << suff[i] << " "; cout << endl;
   
   for(int k = 0; k < m; k++)
   {
      int i, j;
      cin >> i >> j;
      if(i < j)
      {
         cout << pref[j] - pref[i] << endl;
      }
      else
      {
         cout << suff[j] - suff[i] << endl;
      }
   }
}

void solve1709A()
{
   int x;
   cin >> x;
   vector<int>a(4);
   int cnt = 0;
   for(int i = 1; i < 4; i++) cin >> a[i];
   while(a[x] != 0)
   {
      cnt++;
      x = a[x];
   }
   if(cnt == 2) cout << "YES" << endl;
   else cout << "NO" << endl;
}

void solve1709C()
{
   string s;
   cin >> s;
   ll buffer = 0, cnt = 0;
   for(auto x : s)
   {
      if(x == ')') cnt++;
      else if(x == '(') cnt--;
      else buffer++;
   }
   
   ll open = (buffer + cnt) / 2;
   ll close = (buffer - cnt) / 2;
   
   if(open == 0 || close == 0)
   {
      cout << "YES" << endl;
      return;
   }
   
   string check = string(open - 1, '(') + string(1, ')') + string(1, '(') + string(close - 1, ')');
   ll ptr = 0;
   
   for(auto & x : s)
   {
      if(x == '?') x = check[ptr++];
   }
   cnt = 0;
   for(auto x : s)
   {
      if(x == '(') cnt++;
      else cnt--;
      if(cnt < 0) {cout << "YES" << endl; return;}
   }
   
   cout << "NO" << endl;
   
}

void solve1335D()
{
   vector<vector<int>> a(10, vector<int>(10));
   for(int i = 0; i < 9; i++)
   {
      string s;
      cin >> s;
      for(int j = 0; j < 9; j++)
      {
         a[i + 1][j + 1] = s[j] - '0';
      }  
   }
   
   int start = 0;
   int mul = 0;
   for(int i = 1; i <= 9; i++)
   {
      if(i % 3 == 1) 
      {
         start++;
         mul = 0;
      }
      else mul++;
      
      for(int j = 1; j <= 9; j++)
      {
         if(j == start + 3 * mul)
         {
            //cout << i << " " << j << endl;
            int curr = a[i][j];
            for(int k = 1; k <= 9; k++)
            {
               if(k != curr) {a[i][j] = k; break;}
            }
         }
         cout << a[i][j];
      }
      cout << endl;
   }
}

void solve476B()
{
   string s1, s2;
   cin >> s1 >> s2;
   int n = s1.size();
   int sum = 0;
   for(int i = 0; i < n; i++) sum += (s1[i] == '+') ? 1 : -1;
   
   vector<vector<int>>dp(n);
   if(s2[0] == '+') dp[0].push_back(1);
   else if (s2[0] == '-') dp[0].push_back(-1);
   else {dp[0].push_back(-1); dp[0].push_back(1);}
   
   
   for(int i = 1; i < n; i++)
   {
      auto curr = s2[i];
      if(curr == '+')
      {
         for(auto elem : dp[i - 1])
         {
            dp[i].push_back(elem + 1);
         }
      }
      else if(curr == '-')
      {
         for(auto elem : dp[i - 1])
         {
            dp[i].push_back(elem - 1);
         }
      }
      else
      {
         for(auto elem : dp[i - 1])
         {
            dp[i].push_back(elem - 1);
            dp[i].push_back(elem + 1);
         }
      }
   }
   
   int p = dp[n - 1].size();
   int q = 0;
   for(auto elem : dp[n - 1])
   {
      if(elem == sum) q++;
   }
   
   cout << setprecision(12) << fixed <<  q / (p * 1.0) << endl;
}

//

void solve699B()
{
   int n, m, total = 0;
   cin >> n >> m;
   vector<vector<char>> a(n + 1, vector<char>(m + 1));
   vector<int> rows(n + 1, 0), cols(m + 1, 0);
   for(int i = 1; i <= n; i++)
   {
      for(int j = 1; j <= m; j++) 
      {
         cin >> a[i][j];
         if(a[i][j] == '*') total++;
      }
   }
   for(int i = 1; i <= n; i++)
   {
      int cnt = 0;
      for(int j = 1; j <= m; j++)
      {
         if(a[i][j] == '*') cnt++;
      }
      rows[i] = cnt;
   }
   for(int i = 1; i <= m; i++)
   {
      int cnt = 0;
      for(int j = 1; j <= n; j++)
      {
         if(a[j][i] == '*') cnt++;
      }
      cols[i] = cnt;
   }
   for(int i = 1; i <= n; i++)
   {
      for(int j = 1; j <= m; j++)
      {
         int s = rows[i] + cols[j] - ((a[i][j] == '*') ? 1 : 0);
         if(s == total) 
         {
            cout << "YES" << endl << i << " " << j << endl;
            return;
         }
      }
   }
   cout << "NO" << endl;
}

void solve757B()
{
   int n, x, maxi = 1;
   cin >> n;
   vector<int> a(1e5 + 10, 0);
   for(int i = 0; i < n; i++)
   {
      cin >> x;
      for(int j = 2; j * j <= x; j++)
      {
         if(x % j == 0)
         {
            a[j]++;
            while(x % j == 0) x /= j;
         }
      }
      if(x > 1) a[x]++;
   }
   
   for(auto e : a) maxi = max(e, maxi);
   cout << maxi << endl;
}

void solve479B()
{
   int n, k, x;
   cin >> n >> k;
   set<pair<int, int>> st;
   vector<pair<int, int>> ans;
   for(int i = 1; i <= n; i++)
   {
      cin >> x;
      st.insert(make_pair(x, i));
   }
   if(st.size() == 1) {cout << 0 << " " << 0 << endl; return;}
   int maxidiff = INT_MAX, moves = 0;
   while(k--)
   {
      auto f = *st.begin();
      auto s = *prev(st.end());
      int diff = s.first - f.first;
      if(diff <= maxidiff && diff > 1)
      {
         st.erase(st.begin()); st.erase(prev(st.end()));
         moves++;
         maxidiff = diff;
         ans.push_back(make_pair(s.second, f.second));
         f.first++;
         s.first--;
         st.insert(f);
         st.insert(s);
      }
      else break;
   }
   auto f = *st.begin();
   auto s = *prev(st.end());
   cout << s.first - f.first << " " << moves << endl;
   for(auto e : ans) cout << e.first << " " << e.second << endl;
}

void solve1828C()
{
   ll n, mod = (ll)1e9 + 7, ans = 1;
   cin >> n;
   vector<ll> a(n), b(n);
   for(auto& e : a) cin >> e;
   for(auto& e : b) cin >> e;
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());
   ll i = 0, j = 0;
   for(; i < n; i++)
   {
      while(j < n && a[i] > b[j]) j++;
      ans = ( (ans % mod) * (j - i) % mod ) % mod;
   }
   cout << ans << endl;
}

void solve359B()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(2 * n + 1);
   for(int i = 1; i <= 2 * n; i++) a[i] = i;
   int i = 2 * n - 1;
   while(k--)
   {
      swap(a[i], a[i + 1]);
      i -= 2;
   }
   for(int i = 1; i <= 2 * n; i++) cout << a[i] << " "; cout << endl;
}

void solve1829D()
{
   int n, m, cnt = 0;
   cin >> n >> m;
   unordered_set<int> st;
   vector<int> a;
   a.push_back(n);
   while((int)a.size() > 0)
   {
      int x = a.back();
      a.pop_back();
      if(x == m)
      {
         cout << "YES" << endl;
         return;
      }
      else if(x < m) continue;
      else
      {
         if(x % 3 == 0)
         {
            if(st.find(x / 3) == st.end()) 
            {
               a.push_back(x / 3);
               st.insert(x / 3);
            }
            if(st.find(2 * x / 3) == st.end())
            {
               a.push_back(2 * x / 3);
               st.insert(2 * x / 3);
            }
         }
      }
   }
   //for(auto e : st) cout << e << " "; cout << endl;
   cout << "NO" << endl;
}

void solve911C()
{
   vector<int> a(3); int cnt = 1;
   for(int i = 0; i < 3; i++) cin >> a[i];
   sort(a.begin(), a.end());
   if(a[0] >= 4) cout << "NO" << endl;
   else if(a[0] == 3)
   {
      if(a[1] == a[2] && a[2] == 3) cout << "YES" << endl;
      else cout << "NO" << endl;
   }
   else if(a[0] == 2)
   {
      if(a[1] == 2 || (a[1] == 4 && a[2] == 4)) cout << "YES" << endl;
      else cout << "NO" << endl;
   }
   else cout << "YES" << endl;
}

void solve125A()
{
   int n, f = 0, i = 0;
   cin >> n;
   i = n / 3;
   if(n % 3 == 2) i++;
   f = i / 12;
   i = i % 12;
   cout << f << " " << i << endl;
}

void solve233B()
{
   ll n, ans = INT_MAX;
   cin >> n;
   for(ll ds = 1; ds <= 90; ds++)
   {
      ll root = (ll)sqrt(ds * ds + 4 * n);
      if(root * root != ds * ds + 4 * n) continue;
      ll x = (-ds + root) / 2;
      //cout << ds << " " << root << " " << x << endl;
      ll ds2 = 0;
      ll cpyx = x;
      while(x > 0) 
      {
         ds2 += x % 10;
         x /= 10;
      }
      if(ds2 == ds) ans = min(ans, cpyx);
   }
   if(ans == INT_MAX) ans = -1;
   cout << ans << endl;
}

void solve416A()
{
   int n, greater = -2e9, lesser = 2e9;
   cin >> n;
   while(n--)
   {
      string sign, conf; int num;
      cin >> sign >> num >> conf;
      if(conf == "N")
      {
         if(sign == ">=") {sign = "<="; num--;}
         else if(sign == ">") sign = "<=";
         else if(sign == "<=") {sign = ">="; num++;}
         else sign = ">=";
      }
      else
      {
         if(sign == ">") {sign = ">="; num++;}
         else if(sign == "<") {sign = "<="; num--;}
      }
      //cout << sign << endl;
      if(sign == ">=") greater = max(greater, num);
      else lesser = min(lesser, num);
   }
   //cout << greater << " " << lesser << endl;
   if(greater > lesser) cout << "Impossible" << endl;
   else cout << greater << endl;
}

void solve838A()
{
   int n, m; string s;
   cin >> n >> m;
   vector<vector<int>> a(n, vector<int> (m, 0));
   for(int i = 0; i < n; i++) 
   {
      cin >> s;
      for(int j = 0; j < m; j++) a[i][j] = s[j] - '0';
   }
   vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
   for(int i = 1; i <= n; i++)
   {
      for(int j = 1; j <= m; j++) 
      pref[i][j] += pref[i][j - 1] + a[i - 1][j - 1];
   }
   
   for(int i = 1; i <= m; i++)
   {
      for(int j = 1; j <= n; j++) pref[j][i] += pref[j - 1][i];
   }
   /*for(auto e : pref)
   {
      for(auto e2 : e) cout << e2 << " "; cout << endl;
   }*/
   int ans = INT_MAX;
   for(int k = 2; k <= max(n, m); k++)
   {
      int curr = 0;
      for(int i = 1; i <= n; i += k)
      {
         for(int j = 1; j <= m; j += k)
         {
            int endx = min(i + k - 1, n), endy = min(j + k - 1, m);
            int ones = pref[endx][endy] - pref[endx][j - 1] - pref[i - 1][endy] + pref[i - 1][j - 1];
            int zeroes = k * k - ones;
            curr += min(ones, zeroes);
         }
      }
      ans = min(curr, ans);
      //cout << k << " " << curr << endl;
   }
   cout << ans << endl;
}

void solve331A1A2()
{
   ll n, ans = INT_MIN, l = -1, r = -1;
   cin >> n;
   vector<ll> a(n + 1), pref(n + 1, 0);
   map<int, pair<int, int>> mp;
   for(int i = 1; i <= n; i++) 
   {   
      cin >> a[i];
      if(mp[a[i]].first == 0) mp[a[i]].first = i;
      mp[a[i]].second = i;
      pref[i] += ((a[i] < 0) ? 0 : a[i]) + ((i == 0)? 0 : pref[i - 1]);
   }
   /*for(auto e : mp)
   {
      for(auto e2 : e.second) cout << e2 << " "; cout << endl;
   }*/
   
   for(auto e : mp)
   {
      int num = e.first;
      int f = e.second.first;
      int s = e.second.second;
      if(f == s) continue;
      ll curr = pref[s] - pref[f - 1];
      if(num < 0) curr += 2 * num;
      //cout << f << " " << s << " " << curr << endl;
      if(curr >= ans)
      {
         ans = curr;
         l = f;
         r = s;
      }
   }
   vector<int> cut;
   for(int i = 1; i <= l - 1; i++) cut.push_back(i);
   for(int i = l + 1; i <= r - 1; i++) if(a[i] < 0) cut.push_back(i);
   for(int i = r + 1; i <= n; i++) cut.push_back(i);
   cout << ans << " "<< (int)cut.size() << endl;
   for(auto e : cut) cout << e << " "; cout << endl;
}

void solve227B()
{
   int n, x, q; ll left = 0, right = 0; 
   map<int, int> mp;
   cin >> n;
   for(int i = 1; i <= n; i++)
   {
      cin >> x;
      mp[x] = i;
   }
   cin >> q;
   while(q--)
   {
      cin >> x;
      left += mp[x];
      right += n + 1 - mp[x];
   }
   cout << left << " " << right << endl;
}

void solve290D()
{
   string s; int n;
   cin >> s >> n;
   char c = 'a' + n - 1;
   for(int i = 0; i < s.size(); i++)
   {
      s[i] = tolower(s[i]);
      if(s[i] >= 'a' && s[i] <= c) s[i] = toupper(s[i]);
   }
   cout << s << endl;
}

void solve41B()
{
   int n, b;
   cin >> n >> b;
   int ans = b;
   vector<int> a(n);
   for(auto &e : a) cin >> e;
   for(int buyday = 0; buyday < n; buyday++)
   {
      int howmuchdollar = b / a[buyday];
      int rem = b % a[buyday];
      for(int sellday = buyday; sellday < n; sellday++)
      {
         ans = max(ans, rem + a[sellday] * howmuchdollar);
      }
   }
   cout << ans << endl;
}

void solve19A()
{
   int n; string s, t;
   cin >> n;
   for(int i = 1; i <= n; i++) cin >> s;
   map<string, pair<int, pair<int, int>>> mp;
   for(int i = 1; i <= (n * (n - 1)) / 2; i++)
   {
      cin >> s >> t;
      int j = 0;
      while(j < s.size() && s[j] != '-') j++;
      string team1 = s.substr(0, j);
      string team2 = s.substr(j + 1);
      j = 0;
      while(j < t.size() && t[j] != ':') j++;
      int goal1 = stoi(t.substr(0, j));
      int goal2 = stoi(t.substr(j + 1));
      //cout << team1 << " " << goal1 << " "<< team2 << " " << goal2 << endl;
      if(goal1 == goal2)
      {
         mp[team1].first += 1;
         mp[team2].first += 1;
         mp[team1].second.second += goal1;
         mp[team2].second.second += goal2;
      }
      else if(goal1 > goal2)
      {
         mp[team1].first += 3;
         mp[team2].first += 0;
         int diff = goal1 - goal2;
         mp[team1].second.second += goal1;
         mp[team2].second.second += goal2;
         mp[team1].second.first += diff;
         mp[team2].second.first -= diff;
      }
      else
      {
         mp[team1].first += 0;
         mp[team2].first += 3;
         int diff = goal2 - goal1;
         mp[team1].second.second += goal1;
         mp[team2].second.second += goal2;
         mp[team1].second.first -= diff;
         mp[team2].second.first += diff;
      }
   }
   vector<pair<int, pair<int, pair<int, string> >>> a;
   for(auto e : mp)
   {
      t = e.first;
      int points = e.second.first;
      int diff = e.second.second.first;
      int goals = e.second.second.second;
      a.push_back(make_pair(points, make_pair(diff, make_pair(goals, t))));
   }
   //for(auto e : a) 
   //cout << e.first << " " << e.second.first << " " << e.second.second.first << " " << e.second.second.second << endl;
   sort(a.begin(), a.end(), [](pair<int, pair<int, pair<int, string> >> x, pair<int, pair<int, pair<int, string> >> y)
   {
      if(x.first == y.first)
      {
         if(x.second.first == y.second.first)
         {
            return x.second.second.first > y.second.second.first;
         }
         else return x.second.first > y.second.first;
      }
      else return x.first > y.first;
   });
   //for(auto e : a) 
   //cout << e.first << " " << e.second.first << " " << e.second.second.first << " " << e.second.second.second << endl;
   vector<string> ans;
   for(int i = 0; i < n / 2; i++) ans.push_back(a[i].second.second.second);
   sort(ans.begin(), ans.end());
   for(auto e : ans) cout << e << endl;
}

int main()
{  
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 1;
   //cin >> t;
   while(t--) 
   {
      //solve1826CFromPC();
      //solve290D();
      //solve227B();
      solve19A();
   } 
}

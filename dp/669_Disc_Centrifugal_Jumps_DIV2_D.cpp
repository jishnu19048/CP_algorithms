// Template begins
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <queue> 
#include <string.h>
#include <string>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<=b;i++)
#define all(v) (v).begin(),(v).end()
#define sort0(v) sort(all(v))
#define lbb(a,b,arr,x) lower_bound(arr+a,arr+b+1,x)-arr
#define ubb(a,b,arr,x) upper_bound(arr+a,arr+b+1,x)-arr
#define freq(a,b,arr,x) upper_bound(arr+a,arr+b+1,x)-lower_bound(arr+a,arr+b+1,x)
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define printp(x) cout << x.ff << " " << x.ss << endl
 
const ll mod=998244353;
#define inf 9999999999999
#define MAXN   100001 
  
// stores smallest prime factor for every number 
 
 
ll inv(ll i){if(i==1) return 1;return (mod-((mod/i)*inv(mod%i))%mod)%mod;}
 
ll gcd(ll a,ll b){if(a==0) return b;return gcd(b,b%a);}
inline void fastio(){ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
// Template ends
const int MN = 2e5+7;
int n; 
ll nge1[300005];
ll nse1[300005];
ll arr[300005];
void bfs(vector <int> adj[]){
    bool visited[n];
    ll depth[n];
    for(int i=0;i<n;i++){ 
        visited[i]=false;
        depth[i]=0;
    }
    queue <int> q;
    q.push(0); visited[0]=true;
    while(q.size()>0){
        int s=q.front();
        q.pop();
        for(int i=0;i<adj[s].size();i++){
            if(!visited[adj[s][i]]){
                visited[adj[s][i]]=true;
                depth[adj[s][i]]=1+depth[s];
                q.push(adj[s][i]);
            }
        }
    }
    //for(int i=0;i<n;i++) cout<<depth[i]<<endl;
    cout<<depth[n-1]<<endl;
}
void nger(){
    vector<pair<int, int> >st;
    st.pb(mp(arr[0],0));
    for (int i = 1; i < n; i++) { 
        while (!st.empty() && st.back().first <= arr[i]) {
            nge1[st.back().second]=i;
            st.pop_back();
        }
        st.push_back(mp(arr[i],i));
    }
    while(!st.empty()){
        nge1[st.back().second]=-1;
        st.pop_back();
    }
    st.clear();
}
void ngel(){
    vector<pair<int, int> >st;
    st.pb(mp(arr[n-1],n-1));
    for (int i = n-2; i >=0; i--) { 
        while (!st.empty() && st.back().first <= arr[i]) {
            nge1[st.back().second]=i;
            st.pop_back();
        }
        st.push_back(mp(arr[i],i));
    }
    while(!st.empty()){
        nge1[st.back().second]=-1;
        st.pop_back();
    }
    st.clear();
}
void nser(){
    vector<pair<int, int> >st;
    if(st.empty()) st.pb(mp(arr[0],0));
    for (int i = 1; i < n; i++) { 
        while (!st.empty() && st.back().first >= arr[i]) {
            //cout<<"for "<<st.back().second<<" : "<<i<<endl;
            nse1[st.back().second]=i;
            st.pop_back();
        }
        st.push_back(mp(arr[i],i));
    }
    while(!st.empty()){
        nse1[st.back().second]=-1;
        st.pop_back();
    }
    st.clear();
}
void nsel(){
    vector<pair<int, int> >st;
    if(st.empty()) st.pb(mp(arr[n-1],n-1));
    for (int i = n-2; i >=0; i--) { 
        while (!st.empty() && st.back().first >= arr[i]) {
            //cout<<"for "<<st.back().second<<" : "<<i<<endl;
            nse1[st.back().second]=i;
            st.pop_back();
        }
        st.push_back(mp(arr[i],i));
    }
    while(!st.empty()){
        nse1[st.back().second]=-1;
        st.pop_back();
    }
    st.clear();
}
void solve(){
    cin>>n; vector <int> adj[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n==2){
        cout<<1<<endl;
        return;
    }
    nger(); nser();
    for(int i=0;i<n;i++){
        if(nge1[i]!=-1) adj[i].pb(nge1[i]);
        if(nse1[i]!=-1) adj[i].pb(nse1[i]);
    }
    ngel(); nsel();
    for(int i=0;i<n;i++){
        if(nge1[i]!=-1) adj[nge1[i]].pb(i);
        if(nse1[i]!=-1) adj[nse1[i]].pb(i);
    }
    bfs(adj);
    return;
}
int main(){
    fastio();
    //write code
    int t; t=1;
    while(t--){
        solve();
    }
    return 0;
}

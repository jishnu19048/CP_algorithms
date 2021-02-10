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
#define fo(i,a,b) for(i=a;i<b;i++)
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

ll n;
vector <int> adj[300005];
void binary_lifting(ll u, ll p, ll **memo, ll *depth, ll log){
    memo[u][0] = p;  
    for (int i = 1; i <= log; i++)  
        memo[u][i] = memo[memo[u][i - 1]][i - 1];  
    for (int v : adj[u])  
    {  
        if (v != p)  
        {  
            depth[v] = depth[u] + 1;  
            binary_lifting(v, u, memo, depth, log);  
        }  
    }
}
void find_lca(ll u, ll v, ll log, ll *depth, ll **memo, ll d)
{
    ll first=u; ll last=v;
    ll dis;
    if (depth[u] < depth[v])  
        swap(u, v);  
    int larger=u;
    for (int i = log; i >= 0; i--)  
        if ((depth[u] - (ll)pow(2, i)) >= depth[v])  
            u = memo[u][i];
    if (u == v) {
        dis=abs(depth[u]-depth[larger]); 
        if(d>=dis){
            cout<<last+1<<endl;
        }else{
            if(first==larger){
                for (int i = log; i >= 0; i--){  
                    if ((d - (ll)pow(2, i)) >= 0)  {
                        d = d - (ll)pow(2, i);
                        first = memo[first][i];
                    }
                }
                cout<<first+1<<endl;
            }else{
                ll val1 = dis - d;
                for (int i = log; i >= 0; i--){  
                    if ((val1 - (ll)pow(2, i)) >= 0)  {
                        val1 = val1 - (ll)pow(2, i);
                        last = memo[last][i];
                    }
                }
                cout<<last+1<<endl;
            }
            
        }
    }
    else{
        for (int i = log; i >= 0; i--)  
        {  
            if (memo[u][i] != memo[v][i])  
            {  
                u = memo[u][i];  
                v = memo[v][i];  
            }  
        }
        dis=abs(depth[memo[u][0]]-depth[first])+abs(depth[memo[u][0]]-depth[last]);
        if(d>=dis){
            cout<<last+1<<endl;
        }else if(d>=abs(depth[memo[u][0]]-depth[first])){
            d = d - abs(depth[memo[u][0]]-depth[first]);
            int val=abs(depth[memo[u][0]]-depth[last])-d;
            for (int i = log; i >= 0; i--){ 
                if ((val - (ll)pow(2, i)) >= 0) {
                    val = val - (ll)pow(2, i);
                    last = memo[last][i];
                }
            }
            cout<<last+1<<endl;
        }else{
            for (int i = log; i >= 0; i--){  
                if ((d - (ll)pow(2, i)) >= 0) { 
                    d = d - (ll)pow(2, i);
                    first = memo[first][i];
                }
            }
            cout<<first+1<<endl;
        }
    }
    //cout<<dis<<endl;
    
}
int main(){
    fastio();
    cin>>n;
    
    ll log = (ll)ceil(log2(n));  
    ll **memo = new ll *[n + 1];  
    for (int i = 0; i < n + 1; i++) memo[i] = new ll[log + 1]; 
    ll *depth = new ll[n + 1];
    for (int i = 0; i <= n; i++)  
        memset(memo[i], -1, sizeof memo[i]);
    for(int i=0;i<n-1;i++){
        int a; int e; cin>>a>>e;
        adj[a-1].pb(e-1);
        adj[e-1].pb(a-1);
    }
    ll q; cin>>q;
    binary_lifting(0,0,memo,depth,log);
    while(q--){
        int b,c,d; cin>>b>>c>>d;
        find_lca(b-1,c-1,log,depth,memo,d); 
    }
    
    return 0;
}

 
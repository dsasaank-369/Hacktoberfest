/*Fractional Knapsack


3    //number of item
v  w
21 1
21 2
20 4

weight of bag
4

output : 47
*/
#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)

#define ff first  // value
#define ss second  // weight
#define setBits(x) builtin_popcount(x);


bool compare (pii p1, pii p2){

 double v1 =(double) p1.ff/p1.ss;
 double v2 = (double) p2.ff/p2.ss;

 return  v1>v2;

}
signed main()
{
    int n;  // number of item in shop
    cin>>n;

    vii a(n);     // container ..weight and value

    rep(i,0,n){ // rep use fast input

      cin>>a[i].ff>>a[i].ss;

    }
    int w; // bag weight
    cin>>w;

    sort(a.begin(),a.end(),compare) ;// sort based on value/weight

    int ans=0;   // maximum value store


     rep(i,0,n){

       if(w>=a[i].ss) // bag w weight >= weight of item/sum of items
       {
           ans+=a[i].ff;  // add values
           w-=a[i].ss;  // weight of the bag - weight of items
           continue;
       }

       double vw =(double)a[i].ff/a[i].ss;
       ans+=vw*w;
       w=0;
       break;
     }
     cout<<"maximum value "<<ans;

    return 0;

}

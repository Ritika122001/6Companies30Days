// 2179. Count Good Triplets in an Array
// You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].

// A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

// Return the total number of good triplets.
// Example 1:

// Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
// Output: 1
// Explanation: 
// There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
// Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
// Example 2:

// Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
// Output: 4
// Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).


#define ll long long
vector<ll> seg;
vector<ll> v;
int n;
void build(ll l,ll r,ll c=1)
{
    if(l==r)
    {
        seg[c]=v[l];
        return;
    }
    ll mid=(l+r)/2;
    build(l,mid,2*c); build(mid+1,r,2*c+1);
    seg[c]=seg[2*c]+seg[2*c+1];
    return;
}
ll solve(ll l,ll r,ll a,ll b,ll c=1)
{
    if(l>b||r<a)
        return 0;
    if(l>=a&&r<=b)
        return seg[c];
    ll mid=(l+r)/2;
    return solve(l,mid,a,b,2*c)+solve(mid+1,r,a,b,2*c+1);
}
void update(ll l,ll r,ll ind,ll c=1)
{   
    if(ind<l||ind>r)
        return;
    if(l==r&&l==ind)
    {
        seg[c]=1;
        return;
    }
    ll mid=(l+r)/2;
    update(l,mid,ind,2*c);  update(mid+1,r,ind,2*c+1);
    seg[c]=seg[2*c]+seg[2*c+1];
}
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2)
    {
    int n=nums1.size();
    v.resize(n+1,0);
        ll ans=0;
    map<ll,ll> m;
        for(ll i=1;i<=n;i++)
        {
            m[nums2[i-1]+1]=i;
        }
        seg.clear();
        seg.resize(4*n+10,0);
        build(1,n);
        update(1,n,m[nums1[0]+1]);
        for(ll i=2;i<=n;i++)
        {
            ll r=m[nums1[i-1]+1];
            ll q=solve(1,n,1,r);
            // cout<<q<<"\n";
            ll d=i-q-1;
            ll loc=(n-r)-d;
            ans+=loc*q;
            update(1,n,r);
        }
        return ans;
    }
};

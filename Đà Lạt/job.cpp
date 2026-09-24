#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                         \
    if (fopen(name ".inp", "r"))           \
    {                                      \
        freopen(name ".inp", "r", stdin);  \
        freopen(name ".out", "w", stdout); \
    }
#define fileTHHB                            \
    if (fopen("input.txt", "r"))            \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
const int maxN = 200000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
struct Job
{
    int r;
    int p;
    int id;
    int tm;
};

bool cmp(const Job &a, const Job &b)
{
    return a.r < b.r;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    int n;
    cin >> n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> jobs[i].r >> jobs[i].p;
        jobs[i].id = i;
        jobs[i].tm = jobs[i].p;
    }

    sort(jobs.begin(), jobs.end(), cmp);

        auto cmp = [](const Job &a, const Job &b)
        { return a.tm > b.tm; };
    priority_queue<Job, vector<Job>, decltype(cmp)> pq(cmp);

    int cur_tm = 0;
    int res = 0;
    int job_id = 0;

    while (job_id < n || !pq.empty())
    {
        while (job_id < n && jobs[job_id].r <= cur_tm)
        {
            pq.push(jobs[job_id]);
            ++job_id;
        }

        if (!pq.empty())
        {
            Job cur_job = pq.top();
            pq.pop();

            int nx = (job_id < n) ? jobs[job_id].r : INF;
            int tmp = min(cur_job.tm, nx - cur_tm);

            cur_tm += tmp;
            cur_job.tm -= tmp;

            if (cur_job.tm == 0)
                res += cur_tm;
            else
                pq.push(cur_job);
        }
        else
            cur_tm = jobs[job_id].r;
    }

    cout << res;
    return 0;
}

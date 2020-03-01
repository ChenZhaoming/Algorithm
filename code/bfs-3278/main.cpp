#include <iostream>
#include <queue>

using namespace std;

#define MAX 100050
#define INF 100000000

int N, K;

int d[MAX];

int bfs()
{
    queue<int> que;

    for(int i=0; i<MAX; i++){
        d[i]=INF;
    }

    que.push(N);
    d[N]=0;

    while(que.size())
    {
        int n=que.front();
        que.pop();

        if(n==K){
            break;
        }
        if(n-1>=0 && d[n-1] == INF){
            que.push(n-1);
            d[n-1] = d[n] + 1;
        }
        if(n*2 <= MAX && d[n*2] == INF){
            que.push(n*2);
            d[n*2] = d[n] + 1;
        }
        if(n+1 <= MAX && d[n+1] == INF){
            que.push(n+1);
            d[n+1] = d[n] + 1;
        }
    }
    return d[K];
}

int main()
{
    cin >> N >> K;
    int res = bfs();
    cout << res << endl;
    return 0;
}

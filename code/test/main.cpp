#include <iostream>

using namespace std;


static const int MAX_N = 101;
static const int MAX_M = 101;

int N;
int M;

char field[MAX_N][MAX_M];

static void dfs(int n, int m){

    field[n][m] = '.';

    for(int dn=-1; dn<=1; dn++){
        for(int dm=-1; dm<=1; dm++){
            int m_new=m+dm;
            int n_new=n+dn;

            if (m_new>=0 && m_new<M && n_new>=0 && n_new<N && field[n_new][m_new]=='W'){
                dfs(n_new, m_new);
            }
        }
    }

    return;
}

int main()
{
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> field[i];
    }

    int res=0;
    // 横行和竖列 不能混淆
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(field[i][j] == 'W'){
                dfs(i, j);
                res++;
            }
        }
    }

    cout << res << endl;
    return 0;
}

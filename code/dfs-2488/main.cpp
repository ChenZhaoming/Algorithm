#include <iostream>

using namespace std;

#define MAX 30
#define INF 1000000

int N;
int P, Q;
typedef pair<char, char> L;
L state[MAX];
int d[MAX][MAX];

//int dy[8] = {1,1,-2,-2,2,2,-1,-1};
//int dx[8] = {-2,2,-1,1,-1,1,-2,2};

// 注意字典序，字母比数字排位靠前
int dy[8] = {-2,-2,-1,-1,1,1,2,2};
int dx[8] = {-1,1,-2,2,-2,2,-1,1};

bool dfs(int x, int y){

    if(d[x][y] == P*Q){
        return true;
    }

    for(int i=0;i<8;i++)
    {
        int new_x=x+dx[i];
        int new_y=y+dy[i];

        if(new_x>=0 && new_x<P && new_y>=0 && new_y<Q && d[new_x][new_y]==INF){
            d[new_x][new_y] = d[x][y]+1;
            if(dfs(new_x, new_y)) return true;
            // 如果从递归出来
            d[new_x][new_y] = INF;
        }
    }
    return false;
}

void path(){

    for(int x=0; x<P; x++){
        for(int y=0;y<Q;y++){
            int location = d[x][y];
            state[location-1] = L(char(x+49),char(y+65));
        }
    }

    for(int i=0;i<P*Q;i++){
        cout << state[i].second << state[i].first;
    }
    cout << endl << endl;
    return;
}

int main()
{
    cin >> N;

    for(int i=0;i<N;i++){

        cin >> P >> Q;
        cout << "Scenario #" << i+1 << ":" << endl;

        int found=0;
        // init
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                d[i][j] = INF;
            }
        }

        // 如果所有点都能遍历，那么必定经过 A1
        d[0][0]=1;
        if(dfs(0,0)){
            found=1;
            path();
        }
//        // 1-P
//        for(int x=0; x<P; x++){
//            // A-Z
//            for(int y=0; y<Q; y++){
//
//                d[x][y]=1;
//
//                if(dfs(x,y)){
//                    //
//                    found=1;
//                    path();
//                    break;
//                }
//            }
//            if(found==1) break;
//        }

        if(found==0){
            cout << "impossible" << endl << endl;
        }
    }
    return 0;
}

//SOHAM K 30 june 2022
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
char a[1001][1001];
const int INF=1e9+10;
int level[1001][1001];
void sett(){
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            level[i][j]=INF;
        }
    }
}
int bfs(int i,int j,int r,int c){
deque<pair<int,int>>q;
q.pb({i,j});
level[i][j]=0;
while(!q.empty()){
    pair<int,int>child=q.front();
    q.pop_front();
    int c1=child.first;
    int c2=child.second;
    int dr[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    for(int k=0;k<4;k++){
        int cx=c1+dr[k][0];
        int cy=c2+dr[k][1];
        if(cx>=0&&cy>=0&&cx<r&&cy<c){

            if(a[cx][cy]==a[c1][c2]){
                if(level[cx][cy]>level[c1][c2]){
                    level[cx][cy]=level[c1][c2];
                    q.push_front({cx,cy});
                }
            }else {
            if(level[cx][cy]>level[c1][c2]+1){
                level[cx][cy]=level[c1][c2]+1;
                q.pb({cx,cy});
            }

            }
        }
    }

}
return level[r-1][c-1];
}

int main(){
    int tt;cin>>tt;
    while(tt--){
        int r,c;
        cin>>r>>c;
        //vector<string>st;
        //for(int i=0;i<r;i++){
            //string str;cin>>str;
          //  st.pb(str);
        //}
        for(int i=0;i<r;i++){
            string str;cin>>str;
            for(int j=0;j<c;j++){
           a[i][j]=str[j];
            }
        }
        sett();
        cout<<bfs(0,0,r,c)<<endl;
    }

}

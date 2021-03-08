#include<bits/stdc++.h>
using namespace std;

int mx[8]={-2,-1,1,2,2,1,-1,-2},my[8]={-1,-2,-2,-1,1,2,2,1};
int a[8][8]={0};

void star(){
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      a[i][j]=0;
      for(int k=0;k<8;k++){
        int ax=i+mx[k],ay=j+my[k];
        if(ax>=0&&ax<8&&ay>=0&&ay<8)
          a[i][j]++;
      }
    }
  }
}  

int nex(int i,int j){
  int asc=9;
  for(int k=0;k<8;k++){
    int bx=i+mx[k],by=j+my[k];
    if(bx>=0&&bx<8&&by>=0&&by<8)
      asc=min(asc,a[bx][by]);
  }
  return asc;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  int x,y,nx,ny,ax,ay;
  cout<<"請輸入起點的xy座標(0~7)"<<endl;
  while(cin>>x>>y){
    if(x>7||y>7)
      cout<<"請輸入正確的數字範圍(0~7)"<<endl;
    else{
    star();
    int chess[8][8]={0},na[8]={};
    bool visit[8][8]={0};
    int k,step=1,am=0,nam;
    while(am!=9){
      chess[x][y]=step;
      visit[x][y]=1;
      a[x][y]=0;
      am=9,nam=9;
      for(k=0;k<8;k++){
        nx=x+mx[k];ny=y+my[k];
        na[k]=nex(nx,ny);
        if(nx>=0&&nx<8&&ny>=0&&ny<8&&visit[nx][ny]==0){
          if(a[nx][ny]<am&&a[nx][ny]!=0){
            am=a[nx][ny];
            nam=na[k];
            ax=nx,ay=ny;
          }
          if(a[nx][ny]==am&&a[nx][ny]!=0){
            if(na[k]<nam){
              nam=na[k];
              ax=nx,ay=ny;
            }
          }
          a[nx][ny]--;
        }
      }
      x=ax,y=ay;
      step++;
      if(step%10==0){
        cout<<"已走"<<step<<"步，目前剩餘可走步數矩陣為："<<endl;
        for(int i=0;i<8;i++){
          for(int j=0;j<8;j++)
            cout<<a[i][j]<<" ";
          cout<<endl;
        }
      }
    }
    cout<<endl<<"棋盤已走完，以下為騎士所走的順序："<<endl; 
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++)
        cout<<chess[i][j]/10<<chess[i][j]%10<<" ";
      cout<<endl;
    }
    }
  cout<<endl<<"請輸入起點的xy座標(0~7)"<<endl;  
  }
return 0;
}

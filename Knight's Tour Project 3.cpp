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
  int x,y,nx,ny,ax,ay,ix,iy,cou=0;
  bool closed=0;
  cout<<"正在尋找Closed tour......"<<endl;
  system("pause");
  for(int u=0;u<=7;u++){
  	for(int v=0;v<=7;v++){
		    star();
		    int chess[8][8]={0},na[8]={};
		    bool visit[8][8]={0};
		    int k,step=1,am=0,nam;
		    ix=u;iy=v;
		    x=u;y=v;
		    closed=0;
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
		    }
			for(k=0;k<8;k++){
				nx=x+mx[k];ny=y+my[k];
				if(nx==ix&&ny==iy)
					closed=1;
			}
			if(closed)
				cou++;
	    	cout<<endl<<"起點為("<<ix<<","<<iy<<")的棋盤已走完，以下為騎士所走的順序："<<endl<<endl; 
	    	for(int i=0;i<8;i++){
	      	for(int j=0;j<8;j++)
	        	cout<<chess[i][j]/10<<chess[i][j]%10<<" ";
	      		cout<<endl;
   			}
   			cout<<endl<<"終點座標為("<<x<<","<<y<<")"; 
   			if(closed){
   				cout<<"→("<<ix<<","<<iy<<")"<<endl<<endl; 
				cout<<"★為Closed tour★"<<endl;
   				system("pause");
			}
   			cout<<endl<<endl;
	  	}
    }
    cout<<"全部起始座標(0,0)~(7,7)已跑完，Closed tours總數為 "<<cou<<" 次"<<endl;
return 0;
}

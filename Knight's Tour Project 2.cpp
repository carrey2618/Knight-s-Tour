#include<bits/stdc++.h>
#include<time.h>
using namespace std;

int mx[8]={-2,-1,1,2,2,1,-1,-2};
int my[8]={-1,-2,-2,-1,1,2,2,1};
int x,y,ax,ay,step;
int chess[8][8]={},visited[8][8]={};
int next[8]={};
vector<int>cango;

int main(){
	srand(time(NULL));
	cout<<"請輸入起點的xy座標(0~7)"<<endl;
  	while(cin>>x>>y){
	    if(x>7||y>7)
	      cout<<"請輸入正確的數字範圍(0~7)"<<endl;
		else{
			cout<<"程式進行中......"<<endl;
			double START,END;
			int tim[65]={};
	    	START=clock();
			int num=1,cou=1;
			ax=x,ay=y;
			while(num<=64){
				chess[ax][ay]=num,visited[ax][ay]=1;
				if(num==64)
					break;
				for(int i=0;i<8;i++)
					if(!next[i])
						cango.push_back(i);
				if(cango.size()){
					int k=rand()%(cango.size());
					next[cango[k]]=1;
					int nx=ax+mx[cango[k]],ny=ay+my[cango[k]];
					if(nx>=0&&nx<8&&ny>=0&&ny<8&&visited[nx][ny]==0){
						ax=nx,ay=ny;
						memset(next,0,sizeof(next));
						num++;
					}
					cango.clear();
				}
				else{
					tim[num]++;
					memset(chess,0,sizeof(chess));
					memset(visited,0,sizeof(visited));
					memset(next,0,sizeof(next));
					ax=x,ay=y;
					num=1;
					cou++;
				}
			}
			tim[64]++;
	        END = clock();
	        cout<<"棋盤已走完，共嘗試了： "<<cou<<" 次"<<endl;
	        cout<<endl<<"所走步數的統計次數如下："<<endl; 
	        for(int i=1;i<64;i++){
				cout<<"走 "<<setw(2)<<i<<" 步後停止(無法再走)次數為："<<setw(8)<<tim[i]<<" 次"<<endl;
			}
			cout<<endl<<"以下為騎士所走的順序："<<endl;
			for(int i=0;i<8;i++){
	                for(int j=0;j<8;j++)
	                    cout<<chess[i][j]/10<<chess[i][j]%10<<" ";
	                cout<<endl;
	        }
			cout<<endl<<"共用時："<<(END-START)/CLOCKS_PER_SEC<<" 秒"<<endl;
		}
	}
}

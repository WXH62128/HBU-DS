//1-4 列车厢调度 (25分)
#include<bits/stdc++.h>
using namespace std;
queue<char> q1,q2;
stack<char> s;
int way[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string enter,exit;
	int flag = 1,k=0;
	cin >> enter >> exit;
	for(int i=0;i<enter.size();i++){
		q1.push(enter[i]);  //ABC
	}
	for(int i=0;i<exit.size();i++){
		q2.push(exit[i]);  //CBA
	}
	while(!q2.empty()){
		if(!q1.empty()&&q1.front()==q2.front()){  //1轨道的首车是3轨道首车
			q1.pop();q2.pop();  //1轨道进3轨道
			way[k++] = 1;
		}else if(!s.empty()&&s.top()==q2.front()){  //2轨道不空，2轨道倒数第一车等于3轨道首车
			s.pop();q2.pop();  //2轨道进3轨道
			way[k++] = 3;
		}else if(q1.empty()&&!q2.empty()&&s.top()!=q2.front()){  //1轨道空，3轨道不空，2轨道倒数第一车不等于3轨道首车
			flag = 0;break;
		}else if(!q1.empty()&&q1.front()!=q2.front()){  //1轨道的首车不是3轨道首车
			s.push(q1.front());  //1轨道进2轨道
			q1.pop();
			way[k++] = 2;
		}
	}
	if(!flag) cout << "Are you kidding me?";
	else{
		for(int i=0;i<k;i++){
			if(way[i]==1) cout << "1->2\n";
			else if(way[i]==2) cout << "1->3\n";
			else cout << "3->2\n";
		}
	}
	return 0;
}
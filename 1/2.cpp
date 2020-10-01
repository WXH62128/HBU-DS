//1-2 汉诺塔的非递归实现 (25分)
#include<bits/stdc++.h>
using namespace std;
void Hanoi(int n,char a,char b,char c){
	if(n==1) printf("%c -> %c\n",a,c);
	else{
		Hanoi(n-1,a,c,b);
		printf("%c -> %c\n",a,c);
		Hanoi(n-1,b,a,c);
	}
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int N;
	scanf("%d",&N);
	Hanoi(N,'a','b','c');
	return 0;
}
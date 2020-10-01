//1-3 表达式转换 (25分)
#include <bits/stdc++.h>
using namespace std;

stack<char> st;
map<char,int> mp;
int main(){
	mp['+'] = mp['-'] = 1;
	mp['*'] = mp['/'] = 2;
	string s="";
	cin >> s;
	int flag = 1;
	for(int i=0;i<s.length();++i){
		if(isdigit(s[i]) || s[i]=='.' || ((!i||s[i-1]=='(')&&(s[i]=='+'||s[i]=='-')) ){  //处理操作数
			if(!flag) cout << " ";
			else flag = 0;
			if(s[i]!='+') cout << s[i];
			while(s[i+1]=='.'||isdigit(s[i+1])) cout << s[++i];  //小数继续往后读
		}else{  //处理运算符
			if(s[i]=='(') st.push(s[i]);  //（:压栈
			else if(s[i]==')'){  //）：将栈顶的运算符弹出并输出，直到遇到左括号（出栈，不输出）
				while(!st.empty()&&st.top()!='('){
					cout << " " << st.top();
					st.pop();
				}
				st.pop();
			}
			else if(st.empty()||mp[s[i]]>mp[st.top()]) st.push(s[i]);  //s[i]的优先级比栈顶元素的大
			else{
				while(!st.empty()&&st.top()!='('){  //s[i]的优先级比栈顶元素的小或等
					cout << " " << st.top();
					st.pop();
				}
				st.push(s[i]);
			}
		}
	}
	while(!st.empty()){
		cout << " " << st.top();
		st.pop();
	}
	return 0;
}
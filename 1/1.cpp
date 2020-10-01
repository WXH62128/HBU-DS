//1-1一元多项式的乘法与加法运算 (25分)
#include<bits/stdc++.h>
using namespace std;
typedef struct PolyNode *Polynomial;
struct PolyNode{
	int coef,expon;  //系数，指数 
	Polynomial next;
};
void Attach(int c,int e,Polynomial *Prear){
	Polynomial P = new PolyNode();
	P->coef = c,P->expon = e;P->next = NULL;
	(*Prear)->next = P;
	*Prear = P;  //修改P值 
}
Polynomial ReadPoly(){
	Polynomial P,Rear,tmp;
	int c,e,n;
	P = new PolyNode();P->next = NULL;  //链表头空结点 
	Rear = P;
	cin >> n;
	while(n--){
		cin >> c >> e;
		Attach(c,e,&Rear);  //将当前结点插入多项式尾部 
	} 
	tmp = P;P=P->next;free(tmp);  //删除临时生成的头结点
	return P; 
}
void PrintPoly(Polynomial P){
	int flag = 0;
	if(!P){
		cout << 0 <<" " <<0 << endl;
		return;
	}
	while(P){
		if(!flag) flag = 1;
		else cout << " ";
		cout << P->coef <<" "<<P->expon;
		P = P->next;
	}
	cout << endl; 
}
Polynomial AddPoly(Polynomial P1,Polynomial P2){
	Polynomial t1 = P1,t2 = P2,P,Rear,tmp;
	P = new PolyNode();P->next = NULL;
	Rear = P;
	while(t1&&t2){
		if(t1->expon==t2->expon){
			if(t1->coef+t2->coef) Attach(t1->coef+t2->coef,t1->expon,&Rear);  //少 
			t1=t1->next;t2=t2->next;
		}else if(t1->expon>t2->expon){
			Attach(t1->coef,t1->expon,&Rear);
			t1=t1->next;
		}else{
			Attach(t2->coef,t2->expon,&Rear);
			t2=t2->next;
		}
	}
	while(t1){
		Attach(t1->coef,t1->expon,&Rear);
		t1=t1->next;
	}
	while(t2){
		Attach(t2->coef,t2->expon,&Rear);
		t2=t2->next;
	}
	tmp = P;P=P->next;free(tmp);
	return P;
}
Polynomial MultPoly(Polynomial P1,Polynomial P2){
	Polynomial P,Rear,tmp,t1=P1,t2=P2;
	int c,e;
	if(!P1||!P2) return NULL;
	P = new PolyNode();P->next = NULL;
	Rear = P;
	while(t2){  //先用P1的第一项×P2得到P 
		Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
		t2 = t2->next;
	}
	t1=t1->next;
	while(t1){
		t2 = P2;Rear = P;
		while(t2){
			c = t1->coef*t2->coef;
			e = t1->expon+t2->expon; 
			while(Rear->next&&Rear->next->expon>e) Rear=Rear->next;
			if(Rear->next&&Rear->next->expon==e){
				if(Rear->next->coef+c) Rear->next->coef+=c;
				else{
					tmp = Rear->next;
					Rear->next = tmp->next;
					free(tmp);
				}
			}else{
				tmp = new PolyNode();
				tmp->coef = c,tmp->expon = e;
				tmp->next = Rear->next;
				Rear->next = tmp;
				Rear = Rear->next;
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
	t2=P;P=P->next;free(t2);
	return P;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Polynomial P1,P2,PA,PM;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PM = MultPoly(P1,P2);
	PrintPoly(PM);
	PA = AddPoly(P1,P2);
	PrintPoly(PA);
	return 0;
} 

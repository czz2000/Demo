#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
typedef struct Lnode{
	int  xishu;
	int zhishu;
	char str1='x';
	struct Lnode *next;
}Lnode,*LinkList;

//void init(LinkList &L){
//	if(L->zhishu==0){
//		L->str2='\0';
//		L->str1='\0';
//	}
//	if(L->zhishu==1){
//		L->str2='\0';
//	}
//}
int main(){
	
	Lnode *L1=(LinkList)malloc(sizeof(Lnode));Lnode *r1=L1;
	Lnode *L2=(LinkList)malloc(sizeof(Lnode));Lnode *r2=L2;
	L1->next=NULL;L2->next=NULL;
	int n,m,op;
	scanf("%d%d%d",&n,&m,&op);
	while(n--){
		int x,z;scanf("%d %d",&x,&z);

			Lnode *p=(LinkList)malloc(sizeof(Lnode));
			p->next=NULL;
			p->xishu=x;
			p->zhishu=z;
			r1->next=p;
			r1=r1->next;
	}
	
		while(m--){
		int x,z;scanf("%d %d",&x,&z);
			Lnode *p=(LinkList)malloc(sizeof(Lnode));
			p->next=NULL;
			p->xishu=x;
			p->zhishu=z;
			r2->next=p;
			r2=r2->next;
	}
	
	Lnode *p1=L1->next;
	Lnode *p2=L2->next;
	Lnode *L=(LinkList)malloc(sizeof(Lnode));
		Lnode *r=L;

	L->next=NULL;
	while(p1&&p2){
		if(p1->zhishu<p2->zhishu){
			Lnode *p=(LinkList)malloc(sizeof(Lnode));
			p->next=NULL;
			p->xishu=p1->xishu;
			p->zhishu=p1->zhishu; 
			r->next=p;
			p1=p1->next;
			r=r->next;
		}
		else if(p1->zhishu==p2->zhishu){
			Lnode *p=(LinkList)malloc(sizeof(Lnode));
			p->next=NULL;
			p->zhishu=p1->zhishu;
			if(op==0){
			p->xishu=p1->xishu+p2->xishu;}
			if(op==1){
				p->xishu=p1->xishu-p2->xishu;
			} 
			r->next=p;
			r=r->next;
			p1=p1->next;
			p2=p2->next;
		}
	 else	if(p1->zhishu>p2->zhishu){
			Lnode *p=(LinkList)malloc(sizeof(Lnode));
			p->next=NULL;
			p->xishu=p2->xishu;
			p->zhishu=p2->zhishu; 
			r->next=p;
			p2=p2->next;
			r=r->next;
		}
	}
	
	if(p1){
		r->next=p1;
	}
	if(p2){
		r->next=p2;
	}
	
	L=L->next;int flag=1;
	while(L){
	    if(L->xishu){
	    	if(flag!=1&&L->xishu>0)printf("+");
	    	if(abs(L->xishu)>1||L->zhishu==0)printf("%d",L->xishu);
	    	if(L->xishu==-1&&L->zhishu!=0)printf("-");
	    	if(L->zhishu>1)printf("x^%d",L->zhishu);
	    	if(L->zhishu==1)printf("x");
		}
	flag--;
		L=L->next;
	}
	
//	init(L);
//	while(L){
//		printf("%d %d\n",L->xishu,L->zhishu);
//		L=L->next;
//	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Money//金额结构体
{
    int yuan;
    int jiao;
    int fen;
};


struct Time//时间结构体
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};
struct record//消费记录结构体
{
    int type;//消费类型
    struct Time time;//时间
    int store;//商家编号
    int shop;
    struct Money price;//消费金额
    struct record * next;//指向下一节点
};
struct card//校园卡结构体
{
    int number;     //卡号
    struct Money balance;   //余额
    int wash_ticket;    //洗漱票余额
    struct record * listHead;   //指向消费记录
    struct card * next;   //指向下一节点
    //    list = (record * )malloc(sizeof(record));
    //    list.type=0;
    //        list.time.year=2000;
    //        list.time.month=1;
    //        list.time.day=1;
    //        list.time.hour=0;
    //        list.time.minute=0;
    //        list.time.second=0;
    //        list.store=0;
    //        list.price.yuan=0;
    //        list.price.jiao=0;
    //        list.price.fen=0;
    //        list.next=NULL;
};
float get_money(record* now){//得到金额的钱浮点数 
    
	float value;
	float f_yuan=now->price.yuan;
	float f_jiao=now->price.jiao;
	float f_fen=now->price.fen;
	value = f_yuan+f_jiao/10+f_fen/100;
	return value; 
	
}
float get_money(card * p){//得到卡里余额的钱浮点数 
    
	float value;
	float f_yuan=p->balance.yuan;
	float f_jiao=p->balance.jiao;
	float f_fen=p->balance.fen;
	value = f_yuan+f_jiao/10+f_fen/100;
	return value; 
	
}

struct card * createCardList (void){
    struct card * cardHead;
    cardHead = (struct card* )malloc(sizeof(struct card));
    cardHead -> number = 0;
    cardHead -> balance.yuan = cardHead -> balance.jiao = cardHead -> balance.fen = 0;
    cardHead -> wash_ticket = 0;
    cardHead -> next = NULL;
    cardHead -> listHead = (struct record* )malloc(sizeof(struct record));
    cardHead -> listHead -> type = 0;
    cardHead -> listHead -> time.year = cardHead -> listHead -> time.month = cardHead -> listHead -> time.day = cardHead -> listHead -> time.hour = cardHead -> listHead -> time.minute = cardHead -> listHead -> time.second = 0;
    cardHead -> listHead -> store = 0;
    cardHead -> listHead -> shop = 0;
    cardHead -> listHead -> price.yuan = cardHead -> listHead -> price.jiao = cardHead -> listHead -> price.fen = 0;
    cardHead -> listHead -> next = NULL;
    struct card * p = cardHead;
    struct card * q = cardHead;
    for(int i = 0;i < 90;i++){
        p = (struct card* )malloc(sizeof(struct card));
        p -> listHead = (struct record* )malloc(sizeof(struct card));
        if(i < 30)p -> number = 1001 + i;//st
        else if((30 <= i) && (i < 60))p -> number = 1071 + i;//te
        else p -> number = 1141 + i;//zg
        p -> balance.yuan = cardHead -> balance.jiao = cardHead -> balance.fen = 0;
        p -> wash_ticket = 0;
        p -> next = NULL;
        p -> listHead = (struct record* )malloc(sizeof(struct record));
        p -> listHead -> type = 0;
        p -> listHead -> time.year = cardHead -> listHead -> time.month = cardHead -> listHead -> time.day = cardHead -> listHead -> time.hour = cardHead -> listHead -> time.minute = cardHead -> listHead -> time.second = 0;
        p -> listHead -> store = 0;
        p -> listHead -> shop = 0;
        p -> listHead -> price.yuan = cardHead -> listHead -> price.jiao = cardHead -> listHead -> price.fen = 0;
        p -> listHead -> next = NULL;
        while(q -> next != NULL) q = q -> next;
        q -> next = p;
        q = cardHead;
    }
    return cardHead;
}

void get_subsidy(card* s){//统计补贴函数 
	card* p=s;
	record* m=s->listHead;
	printf("所有补贴情况如下：\n") ;
	for(;p->next!=NULL;p = p->next)
	{
		for(;m-> next!=NULL;m = m->next)
		{
			if((s->number/100==11)&&(m->price.yuan>+20))
			printf("%d号在XX地获得了5元补贴",s->number);
		}
	}
}


int main(){
	card* test=createCardList();
	for(;test->next!=NULL;test = test->next)
	printf("%d\n",test->number);
	return 0;
}


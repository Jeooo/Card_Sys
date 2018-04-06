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
        p -> listHead -> type = 1;
        p -> listHead -> time.year = cardHead -> listHead -> time.month = cardHead -> listHead -> time.day = cardHead -> listHead -> time.hour = cardHead -> listHead -> time.minute = cardHead -> listHead -> time.second = 0;
        p -> listHead -> store = 0;
        p -> listHead -> shop = 0;
        p -> listHead -> price.yuan = 30;cardHead -> listHead -> price.jiao = cardHead -> listHead -> price.fen = 0;
        p -> listHead -> next = NULL;
        while(q -> next != NULL) q = q -> next;
        q -> next = p;
        q = cardHead;
    }
    return cardHead;
}

void get_subsidy(card* s){//统计补贴函数 
	card* p=s;
	record* m;
	printf("the following are the subsidies:\n") ;
	for(;p != NULL;p = p->next)
	{
		m=p->listHead;
		do{
			if((p->number/100==11)&&(get_money(m)>=20))
			printf("%d get 5 yuan subsidies in XX\n",p->number);
			m = m->next;
		}while (m!=NULL);
	}
}
struct card * AddMoney(struct card * cardHead){
    printf("Enter your card number:");
    int n;
    n = scanf("%d",&n);
    struct card *p = cardHead;
    while(p -> number != n && p -> next != NULL ) p = p -> next;
    if(p -> number != n)printf("Number not exists.");
    else{
        struct Money m;
        printf("Enter the money:");
        scanf("%d",&m.yuan);scanf("%d",&m.jiao);scanf("%d",&m.fen);
        p -> balance.yuan += m.yuan;p -> balance.jiao += m.jiao;p -> balance.fen += m.fen;
        struct record *q = p -> listHead;
        while(q -> next != NULL) q = q -> next;
        struct record *r = (struct record* )malloc(sizeof(struct record));
        r -> type = 1;
        r -> price = m;
        r -> next = NULL;
        int S,s;
        printf("Enter the Bank_num:");
        scanf("%d",&S);
        printf("Enter the ATM_num:");
        scanf("%d",&s);
        r -> store = S;
        r -> shop = s;
        r -> next = NULL;
        struct tm *c;
        time_t t = time(0);
        c = localtime(&t);
        r -> time.year = 1900 + c -> tm_year;
        r -> time.month = 1 + c -> tm_mon;
        r -> time.day = c -> tm_mday;
        r -> time.hour = c -> tm_hour;
        r -> time.minute = c -> tm_min;
        r -> time.second = c -> tm_sec;
        q -> next = r;
        printf("Money added.\n");
        }
    return cardHead;
}

struct card * Canteen(struct card * cardHead){
    printf("Enter your card number:");
    int n;
    scanf("%d",&n);
    struct card * p = cardHead;
    while(p -> number != n && p -> next != NULL) p = p -> next;
    if(p -> number != n) printf("Number not exists.");
    else{
        struct Money m;
        printf("Enter the money:");
        scanf("%d",&m.yuan);scanf("%d",&m.jiao);scanf("%d",&m.fen);
        p -> balance.yuan -= m.yuan;p -> balance.jiao -= m.jiao;p -> balance.fen -= m.fen;
        if(n / 100 > 10 && m.yuan >= 20) p -> balance.yuan += 5;
        struct record * q = p -> listHead;
        while(q -> next != NULL) q = q -> next;
        struct record *r = (struct record* )malloc(sizeof(struct record));
        r -> type = 2;
        r -> price = m;
        r -> next = NULL;
        int S,s;
        printf("Enter the Canteen_num:");
        scanf("%d",&S);
        printf("Enter the Window_num:");
        scanf("%d",&s);
        r -> store = S;
        r -> shop = s;
        r -> next = NULL;
        struct tm *c;
        time_t t = time(0);
        c = localtime(&t);
        r -> time.year = 1900 + c -> tm_year;
        r -> time.month = 1 + c -> tm_mon;
        r -> time.day = c -> tm_mday;
        r -> time.hour = c -> tm_hour;
        r -> time.minute = c -> tm_min;
        r -> time.second = c -> tm_sec;
        q -> next = r;
        printf("Money cutted.\n");
    }
    return cardHead;
}

struct card * Supermarket(struct card * cardHead){
    printf("Enter your card number:");
    int n;
    scanf("%d",&n);
    struct card * p = cardHead;
    while(p -> number != n && p -> next != NULL) p = p -> next;
    if(p -> number != n) printf("Number not exists.");
    else{
        struct Money m;
        printf("Enter the money:");
        scanf("%d",&m.yuan);scanf("%d",&m.jiao);scanf("%d",&m.fen);
        p -> balance.yuan -= m.yuan;p -> balance.jiao -= m.jiao;p -> balance.fen -= m.fen;
        if(n / 100 > 10 && m.yuan >= 20) p -> balance.yuan += 5;
        struct record *q = p -> listHead;
        while(q -> next != NULL) q = q -> next;
        struct record *r = (struct record* )malloc(sizeof(struct record));
        r -> type = 3;
        r -> price = m;
        r -> next = NULL;
        int S,s;
        printf("Enter the Supermarket_num:");
        scanf("%d",&S);
        printf("Enter the Shop_num:");
        scanf("%d",&s);
        r -> store = S;
        r -> shop = s;
        r -> next = NULL;
        struct tm *c;
        time_t t = time(0);
        c = localtime(&t);
        r -> time.year = 1900 + c -> tm_year;
        r -> time.month = 1 + c -> tm_mon;
        r -> time.day = c -> tm_mday;
        r -> time.hour = c -> tm_hour;
        r -> time.minute = c -> tm_min;
        r -> time.second = c -> tm_sec;
        q -> next = r;
        printf("Money cutted.\n");
    }
    return cardHead;
}
struct card * searchNumber(int number,struct card * cardHead){
    struct card * p = cardHead;
    while(p -> number != number && p -> next != NULL) p = p -> next;
    if(p -> number != number){
        printf("Number not exists.");
        return NULL;
    }
    return p;
}

void Delete(struct card * cardHead){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    struct card * p = searchNumber(n,cardHead);
    if(p){
        printf("Enter the acurite consumption time:");
        struct Time t;
        scanf("%d %d %d %d %d %d",&t.year,&t.month,&t.day,&t.hour,&t.minute,&t.second);
        struct record * q = p -> listHead;
        if(p -> listHead -> next == NULL) printf("Record list is empty.");
        else{
            q = p -> listHead -> next;
            while((q -> time.year != t.year) || (q -> time.month != t.month) || (q -> time.day != t.day) || (q -> time.hour != t.hour) || (q -> time.minute != t.minute) || ((q -> time.second != t.second) && (q -> next != NULL))) q = q -> next;
            if((q -> time.year != t.year) || (q -> time.month != t.month) || (q -> time.day != t.day) || (q -> time.hour != t.hour) || (q -> time.minute != t.minute) || (q -> time.second != t.second)) printf("No such record.");
               else{
                   struct record * d = p -> listHead;
                   while(d -> next != q) d = d -> next;
                   d -> next = q -> next;
                   printf("Delete finished.");
                   d = q = p -> listHead;
               }
        }
    }
}



void Modify(struct card * cardHead){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    struct card * p = searchNumber(n, cardHead);
    struct Time mt;
    printf("Please enter the acurite time to modify:");
    scanf("%d %d %d %d %d %d",&mt.year,&mt.month,&mt.day,&mt.hour,&mt.minute,&mt.second);
    struct record * q = p -> listHead;
    if(p -> listHead -> next == NULL) printf("Record list is empty.");
    else{
        q = p -> listHead -> next;
        while((q -> time.year != mt.year) || (q -> time.month != mt.month) || (q -> time.day != mt.day) || (q -> time.hour != mt.hour) || (q -> time.minute != mt.minute) || ((q -> time.second != mt.second) && (q -> next != NULL))) q = q -> next;
        if((q -> time.year != mt.year) || (q -> time.month != mt.month) || (q -> time.day != mt.day) || (q -> time.hour != mt.hour) || (q -> time.minute != mt.minute) || (q -> time.second != mt.second)) printf("No such record.");
        else{
            if(q -> type == 1){
                p -> balance.yuan += q -> price.yuan;
                p -> balance.jiao += q -> price.jiao;
                p -> balance.fen += q -> price.fen;
            }else{
                p -> balance.yuan -= q -> price.yuan;
                p -> balance.jiao -= q -> price.jiao;
                p -> balance.fen -= q -> price.fen;
            }
            printf("Enter the consume type:");
            scanf("%d",&(q -> type));
            printf("Enter the store number:");
            scanf("%d",&(q -> store));
            printf("Enter the shop number:");
            scanf("%d",&(q -> shop));
            printf("Enter the price:");
            scanf("%d %d %d",&(q -> price.yuan),&(q -> price.jiao),&(q -> price.fen));
            if(q -> type == 1){
                p -> balance.yuan += q -> price.yuan;p -> balance.jiao += q -> price.jiao;p -> balance.fen += q -> price.fen;
            }
            else{
                 p -> balance.yuan -= q -> price.yuan;p -> balance.jiao -= q -> price.jiao;p -> balance.fen -= q -> price.fen;
            }
//            struct record * l = p -> listHead;
//            while (l ->next != q) l = l -> next;
//            l -> next = q -> next;
//            q = (struct record *)malloc(sizeof(struct record));
//            int t;
//            printf("Enter the consume type:");
//            scanf("%d",&t);
//            q -> type = t;
//            struct Money m;
//            printf("Enter the money:");
//            scanf("%d",&m.yuan);scanf("%d",&m.jiao);scanf("%d",&m.fen);
//            p -> balance.yuan -= m.yuan;p -> balance.jiao -= m.jiao;p -> balance.fen -= m.fen;
//            if(p -> number / 100 > 10 && m.yuan >= 20) p -> balance.yuan += 5;
//            printf("Enter the store:");
//            scanf("%d",&(q -> store));
//            printf("Enter the shop:");
//            scanf("%d",&(q -> shop));
//            struct tm *c;
//            time_t t1 = time(0);
//            c = localtime(&t1);
//            q -> time.year = 1900 + c -> tm_year;
//            q -> time.month = 1 + c -> tm_mon;
//            q -> time.day = c -> tm_mday;
//            q -> time.hour = c -> tm_hour;
//            q -> time.minute = c -> tm_min;
//            q -> time.second = c -> tm_sec;
        }
    }
}















void print(struct card *cardHead){
    struct card * p = cardHead;
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    while(p -> number != n) p = p -> next;
    if(p == NULL) printf("Number not exists.");
    else{
        struct record * q = p -> listHead -> next;
        if(q == NULL) printf("No records.");
        else{
            while(q != NULL){
                printf("Time: %d-%d-%d %d:%d:%d\n",q -> time.year,q -> time.month,q -> time.day,q -> time.hour,q -> time.minute,q -> time.second);
                printf("Store: %d\n",q -> store);
                printf("Shop: %d\n",q ->shop);
                printf("Price: %d.%d.%d\n",q -> price.yuan,q -> price.jiao,q -> price.fen);
                q = q -> next;
            }
        }
    }
}




void Bathroom(struct card * cardHead){
    printf("Please enter your card number:");
    int n;
    scanf("%d",&n);
    struct card * p = cardHead;
    while(p -> number != n && p -> next != NULL) p = p -> next;
    if(p -> number != n) printf("Number not exists.");
    else{
        struct record * q = p -> listHead;
        while(q -> next != NULL) q = q -> next;
        struct record * r = (struct record * )malloc(sizeof(struct record));
        r -> type = 4;
        int w = 1;
        double a;
        printf("Enter the mount of water,2f:");
        scanf("%lf",&a);
        if(a > 1) w = a;
        w /= 2;
        r -> price.yuan = (int)w;
        r -> price.jiao = (int)((w - (r -> price.yuan)) * 10);
        r -> price.fen = (int)((w - (r -> price.yuan) - (r -> price.jiao)) * 100);
               
    }
    
    
}
void statistics(card* s){//task 5
	card* p=s;
	record* m=s->listHead;
	printf("what do you want to search?\n");
	printf("if you want to search the save");
	for(;p->next!=NULL;p = p->next)
	{
		for(;m-> next!=NULL;m = m->next)
		{
			
		}
	}
}
int main(){
	card* test=createCardList();
	get_subsidy(test);
	return 0;
}


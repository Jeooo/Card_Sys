//
//  main.c
//  c语言课设
//
//  Created by 褚佳琦 on 2018/3/17.
//  Copyright © 2018年 apple. All rights reserved.
//

//#include <stdio.h>
//#include <stdlib.h>
//typedef struct{     //时间
//    int year;
//    int month;
//    int day;
//    int hour;
//    int minute;
//    int second;
//}date;
//typedef struct deposit{    //存款
//    int money;
//    date dep_time;
//}deposit;
//typedef struct canteen{     //食堂
//    int canteen_num;
//    int seller_num;
//    int money;
//    date con_time;
//    struct canteen* next;
//}canteen;
//typedef struct supermarket{    //超市
//    int supermarket_num;
//    int seller_num;
//    int money;
//    date con_time;
//    struct supermarket* next;
//}supermarket;
//typedef struct bath{         //浴池
//    int bath_num;
//    int seller_number;
//    int coupons;
//    date con_time;
//    struct bath* next;
//}bath;
//typedef struct stu_card{       //学生卡
//    int card_num;
//    deposit* dep_head;;
//    canteen* can_head;
//    supermarket* sup_head;
//    bath* bat_head;
//    struct stu_card* next;
//}stu_card;
//stu_card * create_list(void){
//    int m = 3200;
//    stu_card * head;
//    head = (stu_card*)malloc(sizeof(stu_card));
//    stu_card * p = head;
//    stu_card * q = head;
//    head -> card_num = m;
//    int i = 0;
//    for(i = 0;i < 10;i++){
//        p = (stu_card*)malloc(sizeof(stu_card));
//        q -> next = p;
//        p -> card_num = q -> card_num + 1;
//        p -> dep_head = (deposit*)malloc(sizeof(deposit));
//        p -> can_head = (canteen*)malloc(sizeof(canteen));
//        p -> sup_head = (supermarket*)malloc(sizeof(supermarket));
//        p -> bat_head = (bath*)malloc(sizeof(bath));
//        q = p;
//    }
//    p = q = head;
//    return head;
//};
//void con_canteen(canteen* head){
//    canteen* p = (canteen*)malloc(sizeof(canteen));
//    printf("请输入食堂序号:");
//    scanf("%d",&(p->canteen_num));
//    printf("请输入窗口号:");
//    scanf("%d",&(p->seller_num));
//    printf("请输入消费金额:");
//    scanf("%d",&(p->money));
//    printf("请输入刷卡时间:");
//    scanf("%d %d %d %d %d %d",&(p->con_time.year),&(p->con_time.month),&(p->con_time.day),&(p->con_time.hour),&(p->con_time.minute),&(p->con_time.second));
//    if(head == NULL)head = p;
//    else{
//        canteen* q = head;
//        while(q->next != NULL)q = q->next;
//        q->next = p;
//    }
//}
//void consume_record(stu_card* head){
//    stu_card* p = head->next;
//    while(p != NULL){
//        if(p->can_head != NULL){
//            canteen* q = p->can_head;
//            while(q != NULL){
//                printf("%d %d %d\n",q->canteen_num,q->seller_num,q->money);
//                printf("%d %d %d %d:%d:%d\n",q->con_time.year,q->con_time.month,q->con_time.day,q->con_time.hour,q->con_time.minute,q->con_time.second);
//                q = q->next;
//            }
//        }else{
//            printf("暂无食堂消费记录.");
//        }
//        p = p->next;
//    }
//}
//
//
//
//
//
//int main(void)
//{
//    stu_card* stu_head = create_list();
//    con_canteen((stu_head->next)->can_head);
//    con_canteen((stu_head->next)->can_head);
//    consume_record(stu_head);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//




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
        if(i < 30){
            p -> number = 1001 + i;//st
            p -> wash_ticket = 100;
        }
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





int main(void){
    struct card * cardHead;
    cardHead = createCardList();
    AddMoney(cardHead);
//    Canteen(cardHead);
    print(cardHead);

    
    return 0;
    
}




















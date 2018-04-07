//
//  main.cpp
//  C语言课程设计
//
//  Created by 褚佳琦 on 2018/4/7.
//  Copyright © 2018年 apple. All rights reserved.
//








#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Money
{
    int yuan;
    int jiao;
    int fen;
};
struct Time
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};
struct card       //card_struct
{
    int number;        //card_number
    struct Money balance;     //balance
    struct Money wash_ticket;    //wash_ticket balance
    struct record * listHead;   // record_head
    struct card * next;
};
struct record      //consume_struct
{
    int type;     //consume_type
    struct Time time;    //consume_time
    int store;      //store
    int shop;       //shop
    struct Money price;      //consume_cost
    struct record * next;
};



void printList(card * cardHead){
    card * p = cardHead;
    while(p != NULL){
        cout<<p -> number<<endl;
        p = p -> next;
    }
}







card * createCardList (void){
    card * cardHead = new card;
    cardHead -> number = 0;
    cardHead -> balance.yuan = cardHead -> balance.jiao = cardHead -> balance.fen = 0;
    cardHead -> wash_ticket.yuan = cardHead -> wash_ticket.jiao = cardHead -> wash_ticket.fen = 0;
    cardHead -> next = NULL;
    cardHead -> listHead = new record;
    cardHead -> listHead -> type = 0;
    cardHead -> listHead -> time.year = cardHead -> listHead -> time.month = cardHead -> listHead -> time.day = cardHead -> listHead -> time.hour = cardHead -> listHead -> time.minute = cardHead -> listHead -> time.second = 0;
    cardHead -> listHead -> store = 0;
    cardHead -> listHead -> shop = 0;
    cardHead -> listHead -> price.yuan = cardHead -> listHead -> price.jiao = cardHead -> listHead -> price.fen = 0;
    cardHead -> listHead -> next = NULL;
    card * p = cardHead;
    card * q = cardHead;
    for(int i = 0;i < 90;i++){
        p = new card;
        p -> listHead = new record;
        if(i < 30){
            p -> number = 1001 + i;                                  //student
            p -> wash_ticket.yuan = 100;
            p -> wash_ticket.jiao = p -> wash_ticket.fen = 0;
        }
        else if((30 <= i) && (i < 60))p -> number = 1071 + i;        //teacher
        else p -> number = 1141 + i;                                 //employee
        p -> balance.yuan = cardHead -> balance.jiao = cardHead -> balance.fen = 0;
        p -> wash_ticket.yuan = p -> wash_ticket.jiao = p -> wash_ticket.fen = 0;
        p -> next = NULL;
        p -> listHead = new record;
        p -> listHead -> type = 0;
        p -> listHead -> time.year = cardHead -> listHead -> time.month = cardHead -> listHead -> time.day = cardHead -> listHead -> time.hour = cardHead -> listHead -> time.minute = cardHead -> listHead -> time.second = 0;
        p -> listHead -> store = 0;
        p -> listHead -> shop = 0;
        p -> listHead -> price.yuan = cardHead -> listHead -> price.jiao = cardHead -> listHead -> price.fen = 0;
        p -> listHead -> next = NULL;
        while(q -> next != NULL) q = q -> next;
        q -> next = p;
    }
    return cardHead;
}










int main(int argc, const char * argv[]) {
    card * cardHead = createCardList();
    printList(cardHead);
    return 0;
}

//
//  sapper.cpp
//  Sapper
//
//  Created by Илья Соловьёв on 03/06/2019.
//  Copyright © 2019 Илья Соловьёв. All rights reserved.
//
#include <iostream>
using namespace std;
#include "sapper.hpp"

const int N=10;
bool field_hidden[N][N];
char field[N][N];

void clear_field(char s='*'){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            field[i][j]=s;
            field_hidden[i][j]=0;
        }
    }
}

void set_mine_count(int count=10){
    int i=0;
    while (i<count){
        int x=rand()%10;
        int y=rand()%10;
        if (!field_hidden[x][y]){
            field_hidden[x][y]=1;
        }
        i++;
    }
}

void show_field(){
    cout<<"   ";
    for (int i=0;i<N;i++){
        cout<<i+1<<" ";
    }
    cout<<endl<<"  ---------------------"<<endl;
    
    for (int i=0;i<N;i++){
        cout<<(char)(i+65)<<"| ";
        for (int j=0;j<N;j++){
            cout<<field[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool shot(int x,int y){
    y=y-1;
    if (field_hidden[x][y]){
        return false;
    }else{
        int cnt=0;
        for (int i=x-1;(i<=x+1)&&(x<N);i++){
            for (int j=y-1;(j<=y+1)&&(y<N);j++){
                if ((i>=0)&&(j>=0)){
                    cnt+=field_hidden[i][j];
                }
            }
        }
        field[x][y]=cnt+0x30;
        return true;
    }
}

void game(){
    clear_field();
    set_mine_count();
   // show_field();
    char x;
    int y;
    do{
        show_field();
        cout<<"\nSHOT PLEASE\n";
        cin>>x>>y;
        x=x-97;
    }while (shot(x,y));
    cout<<"GAME OVER"<<endl;
        
    
    
}

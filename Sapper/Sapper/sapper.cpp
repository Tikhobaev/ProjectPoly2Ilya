//
//  sapper.cpp
//  Sapper
//
//  Created by Илья Соловьёв on 03/06/2019.
//  Copyright © 2019 Илья Соловьёв. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;
#include "sapper.hpp"

const int N=10;
const int NUMBOMBS=N;
bool field_hidden[N][N];
int field[N][N];
bool visited[N][N];


void clear_field(char s='*'){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            field[i][j]=0;
            field_hidden[i][j]=0;
            visited[i][j]=0;
        }
    }
}

bool check_end_game(){
    int sum=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (!field_hidden[i][j]){
                sum++;
            }
        }
    }
    if (sum==NUMBOMBS){
        return false;
    }
    else
    {
        return true;
    }
}


void set_mine_count(int count=NUMBOMBS){
    int i=0;
    while (i<count){
        int x=rand()%N;
        int y=rand()%N;
        if (!field[x][y]){
            field[x][y]=-1;
            i++;
        }
    }
}

void count_field(){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (field[i][j]!=-1){
                for (int ii=-1;ii<=1;ii++){
                    for (int jj=-1;jj<=1;jj++){
                        if ((i+ii>=0)&&(i+ii<N)&&(j+jj>=0)&&(j+jj<N)){
                            if (field[i+ii][j+jj]==-1){
                                field[i][j]+=1;
                            }
                        }
                    }
                }
            }
        }
    }
}

void start_game(){
    clear_field();
    set_mine_count();
    count_field();
}

void show_field(int c){
    system("clear");
    cout<<"   ";
    for (int i=0;i<N;i++){
        cout<<i+1<<" ";
    }
    cout<<endl<<"  ---------------------"<<endl;
    
    for (int i=0;i<N;i++){
        cout<<(char)(i+65)<<"| ";
        for (int j=0;j<N;j++){
            if ((!field_hidden[i][j])&&(c==1)){
                cout<<"* ";
            }
            else
            {
                switch (field[i][j]) {
                    case -1:
                        cout<<"B ";
                        break;
                        
                    case 0:
                        cout<<"  ";
                        break;
                        
                    default:
                        cout<<field[i][j]<<" ";
                        break;
                }
                
            }
        }
        cout<<endl;
    }
}

void clear_visited(){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            visited[i][j]=0;
        }
    }
}

void show_near_zeros(int x,int y){
    if ((field[x][y]==0)&&(visited[x][y]==false)){
        field_hidden[x][y]=true;
        visited[x][y]=1;
        for (int ii=-1;ii<=1;ii++){
            for (int jj=-1;jj<=1;jj++){
                if ((x+ii>=0)&&(x+ii<N)&&(y+jj>=0)&&(y+jj<N)&&((jj!=0)||(ii!=0))){
                    show_near_zeros(x+ii, y+jj);
                }
            }
        }
    }
}



bool shot(int x,int y){
    if ((x<0)||(x>=N)||(y<0)||(y>=N)){
        return true;
    }
        else
    {
        y=y;
        if (field[x][y]==-1){
            return false;
        }else{
            field_hidden[x][y]=true;
            if (field[x][y]==0){
                clear_visited();
                show_near_zeros(x,y);
            }
            
            return true;
        }
    }
}

bool game(){
    start_game();
//    for (int i=0;i<N;i++){
//        for (int j=0;j<N;j++){
//            cout<<field[i][j];
//        }
//        cout<<endl;
//    }
//    show_field();
    char x;
    int y;
    do{
//            for (int i=0;i<N;i++){
//                for (int j=0;j<N;j++){
//                    cout<<field[i][j];
//                }
//                cout<<endl;
//            }
        show_field(1);
        do{
            cout<<"\nSHOT PLEASE\n";
            string str,substr="";
            cin>>str;
            x=str[0]-97;
            for (int i=1;i<str.length();i++){
                substr+=str[i];
            }
            y=atoi(substr.c_str())-1;
        }while ((x<0)||(x>=N)||(y<0)||(y>=N));
    }while ((shot(x,y))&&(check_end_game()));
    
    if (!check_end_game()){
            show_field(0);
        cout<<endl<<"YOU WON :)"<<endl<<endl;
            return true;
        }
            else
        {
            show_field(0);
            cout<<endl<<"GAME OVER :("<<endl<<endl;
            return false;
        }
}

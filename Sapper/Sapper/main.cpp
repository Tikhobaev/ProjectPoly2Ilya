//
//  main.cpp
//  Sapper
//
//  Created by Илья Соловьёв on 17/05/2019.
//  Copyright © 2019 Илья Соловьёв. All rights reserved.
//

#include <iostream>
#include <time.h>
using namespace std;
#include "sapper.hpp"

int main() {
    double time_game[50];
    int num_games=0;
    srand( (unsigned int) time(NULL) );
    cout<<"Welcome to the SAPPER GAME"<<endl;
    cout<<"Press:"<<endl<<endl<<"s - to start the game"<<endl<<"e - to exit the game"<<endl<<endl;
    char choice;
    cin>>choice;
    switch (choice) {
        case 's':
        {
            clock_t begin = time(NULL);
            bool win=game();
            clock_t end = time(NULL);
            if (win){
                time_game[num_games]=difftime(end, begin);
            }
            else
            {
                time_game[num_games]=-1;
            }
            num_games+=1;
        }
            break;
            
        case 'e':
            return 0;
            break;
            
        default:
            break;
    }
    
    do{
        cout<<"Press:"<<endl<<endl<<"s - to start the game"<<endl<<"e - to exit the game"<<endl<<endl<<"l - to list your result for the session"<<endl;
        cin>>choice;
        
        switch (choice) {
            case 's':
            {
                clock_t begin = time(NULL);
                bool win=game();
                //system("clear");
                clock_t end = time(NULL);
                if (win){
                    time_game[num_games]=difftime(end, begin);
                }
                else
                {
                    time_game[num_games]=-1;
                }
                num_games+=1;
            }
                break;
                
            case 'e':
            {
                return 0;
            }
                break;
                
            case 'l':
            {
                cout<<endl<<"GAMES PLAYED: "<<num_games<<endl<<endl;
                for (int i=0;i<num_games;i++){
                    if (time_game[i]!=-1)
                    {
                        cout<<i+1<<") "<<time_game[i]<<endl;
                    }
                    else
                    {
                        cout<<i+1<<") FAIL"<<endl;
                    }
                }
                cout<<endl;
            }
                break;
                
            default:
            {
                break;
            }
        }
    }while (choice!='e');
    
    
    return 0;
}

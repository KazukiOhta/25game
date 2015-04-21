//
//  main.c
//  25
//
//  Created by 太田　一毅 on 2015/04/20.
//  Copyright (c) 2015年 太田一毅. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int A_ID;
    int B_ID;
    
    int record[100000][3];//勝敗分
    int l;
    for (l = 0; l < 100000; l ++) {
        record[l][0] = 0;
        record[l][1] = 0;
        record[l][2] = 0;
    }
    
    for (A_ID = 0; A_ID < 100000; A_ID ++) {
        if (A_ID%1000 == 0) {
            printf("%d\n",A_ID);
        }
        for (B_ID = 0; B_ID < 100000; B_ID ++) {
  
            

                
            
                    //input
                    int data_A;
                    int data_B;
                    
            
                    
                    data_A = A_ID;
                    data_B = B_ID;
                    
                    int A[5][2];
                    int B[5][2];
                    
                    int i;
                    
                    for (i = 0; i < 5; i ++) {
                        A[i][0] = 0;
                        A[i][1] = 0;
                        B[i][0] = 0;
                        B[i][1] = 0;
                    }
                    
                    for (i = 0; i < 5; i ++) {
                        A[i][0] = (data_A / pow(10, 4-i));
                        A[i][0] = A[i][0] % 10;
                        A[i][1] = A[i][0];
                        B[i][0] = (data_B / pow(10, 4-i));
                        B[i][0] = B[i][0] % 10;
                        B[i][1] = B[i][0];
                    }
            if (A[0][0] + A[1][0] + A[2][0] + A[3][0] + A[4][0] <= 25
                &&
                B[0][0] + B[1][0] + B[2][0] + B[3][0] + B[4][0] <= 25
                ){
                
//                printf("%d,%d",A_ID,B_ID);

                
                    //BattleStart
                    
                    //    printf("0round %d,%d,%d,%d,%dVS%d,%d,%d,%d,%d\n",
                    //           A[4][0],A[3][0],A[2][0],A[1][0],A[0][0],B[0][0],B[1][0],B[2][0],B[3][0],B[4][0]);
                    
                    int winner = 0;
                    
                    while (winner == 0) {
                        int round;
                        
                        for (round = 1; round <= 9; round ++) {
                            /*int A_howmany = 0;
                             int B_howmany = 0;
                             for (i = 0; i < 5; i ++) {
                             if (A[i][0] == round) {
                             A_howmany ++;
                             }
                             if (B[i][0] == round) {
                             B_howmany ++;
                             }
                             }
                             //DealDamage
                             while (A_howmany != 0) {
                             B[0][1] = B[0][1] - round;
                             if (B[0][1] <= 0) {
                             for (i = 0; i < 4; i ++) {
                             B[i][1] = B[i+1][1];
                             }
                             B[4][1] = 0;
                             }
                             A_howmany --;
                             }
                             
                             while (B_howmany != 0) {
                             A[0][1] = A[0][1] - round;
                             if (A[0][1] <= 0) {
                             for (i = 0; i < 4; i ++) {
                             A[i][1] = A[i+1][1];
                             }
                             A[4][1] = 0;
                             }
                             B_howmany --;
                             }*/
                            
                            int A_Attack[5];
                            int A_howmany;
                            int B_Attack[5];
                            int B_howmany;
                            
                            for (i = 0; i < 5; i ++) {
                                A_Attack[i] = 0;
                                B_Attack[i] = 0;
                            }
                            A_howmany = 0;
                            B_howmany = 0;
                            
                            
                            for (i = 0; i < 5; i ++) {
                                if (A[i][0] == round) {
                                    A_Attack[A_howmany] = A[i][1];
                                    A_howmany ++;
                                }
                                if (B[i][0] == round) {
                                    B_Attack[B_howmany] = B[i][1];
                                    B_howmany ++;
                                }
                            }
                            //DealDamage
                            int j;
                            
                            j = 0;
                            while (A_howmany != 0) {
                                B[0][1] = B[0][1] - A_Attack[j];
                                
                                if (B[0][1] <= 0) {
                                    for (i = 0; i < 4; i ++) {
                                        B[i][0] = B[i+1][0];
                                        B[i][1] = B[i+1][1];
                                    }
                                    B[4][0] = 0;
                                    B[4][1] = 0;
                                }
                                
                                A_howmany --;
                                j ++;
                            }
                            
                            j = 0;
                            while (B_howmany != 0) {
                                A[0][1] = A[0][1] - B_Attack[j];
                                
                                if (A[0][1] <= 0) {
                                    for (i = 0; i < 4; i ++) {
                                        A[i][0] = A[i+1][0];
                                        A[i][1] = A[i+1][1];
                                    }
                                    A[4][0] = 0;
                                    A[4][1] = 0;
                                }
                                
                                B_howmany --;
                                j ++;
                            }
                            
                            
                            
                            
                            //            printf("%dround %d,%d,%d,%d,%dVS%d,%d,%d,%d,%d\n",
                            //                   round,A[4][1],A[3][1],A[2][1],A[1][1],A[0][1],B[0][1],B[1][1],B[2][1],B[3][1],B[4][1]);
                        }
                        
                        for (i = 0; i < 5; i ++) {
                            A[i][0] = A[i][1];
                            B[i][0] = B[i][1];
                        }
                        
                        //        printf("\n\n");
                        
                        int A_lose = 0;
                        int B_lose = 0;
                        
                        if (A[0][0] == 0 && A[1][0] == 0 && A[2][0] == 0 && A[3][0] == 0 && A[4][0] == 0) {
                            A_lose = 1;
                        }
                        
                        if (B[0][0] == 0 && B[1][0] == 0 && B[2][0] == 0 && B[3][0] == 0 && B[4][0] == 0) {
                            B_lose = 1;
                        }
                        
                        switch (A_lose + 2*B_lose) {
                            case 0:
                                winner = 0;
                                break;
                                
                            case 1:
                                winner = -1;
                                break;
                                
                            case 2:
                                winner = 1;
                                break;
                                
                            case 3:
                                winner = 2;
                                break;
                                
                            default:
                                break;
                        }
                        
                        switch (winner) {
                            case 1:
//                                printf("A,won!!\n");
                                record[A_ID][0]++;
                                record[B_ID][1]++;
                                break;
                                
                            case -1:
//                                printf("B,won!!\n");
                                record[B_ID][0]++;
                                record[A_ID][1]++;
                                break;
                                
                            case 2:
//                                printf("Draw\n");
                                record[A_ID][2]++;
                                record[B_ID][2]++;
                                break;
                                
                            default:
                                break;
                        }
                        
                        
                        
                    }
                }
            
        }
    }
    
    
    printf("finished\n");
    int k;
    int most_winner = 0;
    int most_win = 0;
    
    for (k = 0; k < 100000; k ++) {
        if (record[k][0] > most_win) {
            most_winner = k;
            most_win = record[k][0];
        }
    }
    
    printf("most winner is %d\n",most_winner);

    
    return 0;
}

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    uint8_t T, M;
    uint16_t N;
    int valid=0, comb = 0;
    char matrix[5000][18];
    scanf("%hhu", &T);
    for (uint8_t i =0; i< T ; i++){
        scanf("%hu %hhu",&N, &M);
        
        for(uint16_t n =0; n< N; n++){
            scanf("%s", matrix[n]);}
            
            for(uint16_t a1 = 0; a1< N-2; a1++){                //aluno1
                for(uint16_t a2 = a1+1; a2< N-1; a2++){            //aluno2
                    for(uint16_t a3 = a2+1; a3< N; a3++){          //aluno3
                        for(uint8_t cnt = 0; cnt< M; cnt++){  //area
                           // printf("cond1:%d\n",(int)matrix[a1][cnt]);
                            // printf("cond2:%d\n",(int)matrix[a2][cnt]);
                            //  printf("cond3:%d\n",(int)matrix[a3][cnt]);
                            //printf("cond:%d\n",((int)matrix[a1][cnt]+(int)matrix[a2][cnt]+(int)matrix[a3][cnt])/3);
                            //if((((int)matrix[a1][cnt]+(int)matrix[a2][cnt]+(int)matrix[a3][cnt])/3) == 110){
                            if((matrix[a1][cnt]=='n') && (matrix[a2][cnt]=='n') &&(matrix[a3][cnt]=='n')){
                                valid = 0;
                                break;
                            }
                            valid = 1;
                            
                            /*for(uint8_t la = 0; la< 3; la++){  //column
                                if (matrix[a1][la]=='n'){
                                    valid = 0;
                                    break;
                                }
                            }*/
                        }
                        if(valid)
                            comb++;
                    }
                }
            } 
        printf("%d\n", comb);
        comb = 0;
    }
    return 0;
}
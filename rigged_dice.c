#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t T, N;
    scanf("%hu", &T);
    
    uint16_t alice, bob;
    uint8_t bob_tmp, alice_tmp;
    
    uint8_t pos;
    uint16_t n61, n62;
    
    for (uint16_t i = 0; i < T; i++){
        scanf("%hu", &N);
        alice=0;
        bob=0;
        n61=0;
        n62=0;
        pos = 1;
        for (uint16_t r = 0; r < N; r++){
            scanf("%hhd %hhd", &alice_tmp, &bob_tmp);
            alice  += alice_tmp;
            bob  += bob_tmp;
            if (alice_tmp==6){
                if(pos==1)
                    n61++;
                else
                    n62++;
            }
            if (bob_tmp==6){
                if(pos==1)
                    n62++;
                else
                    n61++;
            } 
            /printf("GAME: %hhd %hhd POS:%hhd nn61:%hu nn62:%hu\n", alice_tmp, bob_tmp, pos, n61, n62);
            if (alice != bob){
                pos = pos==1?2:1;
            }
        }
        if( ((double)n61)/N > ((double)n62)/N )
            printf("1\n");
        else
            printf("2\n");
            
        // printf("%lf %lf %d\n", ((double)n61)/N, ((double)n62)/N, N);
    }
    
    //printf("%d", a + b);
    return 0;
}
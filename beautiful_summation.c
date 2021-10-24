#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {
    uint16_t P, Q;
    uint64_t N, M;
    unsigned long sum=0;
    
    scanf("%hu %hu %lu %lu", &P, &Q, &N, &M);
    
    for (uint64_t k=1; k<=N; k++){
        //printf("%lf %lf", pow(P,k), pow(k,Q));
        sum += (unsigned long)(pow(P,k)*pow(k,Q))%M;
    }
    
    printf("%ld", sum%M);
}
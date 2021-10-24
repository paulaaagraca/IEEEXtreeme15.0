#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
  
// A structure to represent an adjacency list node
struct Node
{
    uint16_t spy;
    struct Node* senior;
};

struct Node* createNodeList(uint16_t Nr, uint16_t Nb){
    uint16_t i, j;
    struct Node* list = (struct Node*) malloc(sizeof(struct Node)*(Nr+Nb));
    for (i = 0; i < Nr; i++){
        list[i].spy = (i+1)|(1<<15);
        list[i].senior = NULL;
    }
    for (j = 0; j < Nb; j++){
        list[i+j].spy = j+1;
        list[i+j].senior = NULL;
    }
    return list;
}

struct Node* findNode(struct Node* nodes, uint16_t spy_ind){
    uint16_t i = 0;
    while (nodes[i].spy != spy_ind){
        i++;
    }
    return &nodes[i];
}

void assignSuperior(struct Node* nodes, uint16_t spy_ind, uint16_t senior)
{
    findNode(nodes, spy_ind)->senior = findNode(nodes, senior);
}

uint16_t parseSpyName(char* str){
    char subbuff[5];
    memcpy( subbuff, &str[1], strlen(str)-1);
    subbuff[strlen(str)-1] = '\0';
    //printf("s: %s s_v2: %s n: %d len: %d\n", str, subbuff, atoi(subbuff), (int)strlen(str));
    return ( str[0]=='R'?(1<<15):0 ) | atoi(subbuff);
}

uint16_t getSpyDelay(struct Node* nodes, uint16_t spy_ind){
    uint8_t R_found[1000] = {0};
    uint8_t B_found[1000] = {0};
    uint16_t delay = 0;
    struct Node* node = findNode(nodes, spy_ind);
    while (node->senior != NULL){
        if( (node->spy-1) & (1<<15)){
            if(R_found[node->spy-1-(1<<15)] == 1)
                return 0xFFFF;
            R_found[node->spy-1-(1<<15)] = 1;
        } else {
            if(B_found[node->spy-1] == 1)
                return 0xFFFF;
            B_found[node->spy-1] = 1;
        }
        delay++;
        node = node->senior;
    }
    return delay | (node->spy & (1<<15));
}

// Driver program to test above functions
int main()
{
  struct Node *nodes;
  uint8_t T;
  uint16_t Nr, Nb, E, d1, d2;
  char str[6], str2[6], op[2];
  
  scanf("%hhu", &T);
  
  for(uint8_t i = 0;  i<T; i++){
    scanf("%hu %hu %hu", &Nr, &Nb, &E);
    nodes = createNodeList(Nr, Nb);
    
    for(uint16_t i = 0; i < Nr-1;i++){
        scanf("%s", str);
        assignSuperior(nodes, (i+2)|(1<<15), parseSpyName(str));
    }
    
    for(uint16_t i = 0; i < Nb-1;i++){
        scanf("%s", str);
        assignSuperior(nodes, i+2, parseSpyName(str));
    }
        
      for (uint16_t i = 0; i < E; i++)
      {
          scanf("%s", op);
          if(op[0] == 'c'){
            scanf("%s", str);
            scanf("%s", str2);
            assignSuperior(nodes, parseSpyName(str), parseSpyName(str2));
          } else {
            scanf("%s", str);
            scanf("%s", str2);
            d1 = getSpyDelay(nodes, parseSpyName(str));
            d2 = getSpyDelay(nodes, parseSpyName(str2));
 
            //printf("d1:  %hu d2: %hu ", d1, d2);

            if((d1 == 0xFFFF) && (d2 ==  0xFFFF)){
                printf("NONE\n");

            } else if (d1 == 0xFFFF) {
                if(d2 & (1<<15))
                    printf("RED %d\n", (d2 & 0x7FFF));
                else
                    printf("BLUE %d\n", d2);

            } else if (d2 == 0xFFFF) {
                if(d1 & (1<<15))
                    printf("RED %d\n", (d2 & 0x7FFF));
                else
                    printf("BLUE %d\n", d2);

            } else if ( (d1 & 0x7FFF) < (d2 & 0x7FFF) ){
                //printf("%hu %hu\n", d1, d2);
                if(d1 & (1<<15))
                    printf("RED %d\n", (d1 & 0x7FFF));
                else
                    printf("BLUE %d\n", d1);

            } else if ( (d1 &  0x7FFF) > (d2 & 0x7FFF) ){
                if(d2 & (1<<15))
                    printf("RED %d\n", (d2 & 0x7FFF));
                else
                    printf("BLUE %d\n", d2);

            } else if ( (d1 &  0x7FFF) == (d2 & 0x7FFF) ){
                if((d1 & (1<<15)) && (d2 & (1<<15))){
                    printf("RED %d\n", 0x7FFF & d1);
                } else if ((d1 == (d1 & ~(1<<15))) && (d2 == (d2 & ~(1<<15)))) {
                    printf("BLUE %d\n", (0x7FFF & d1));
                } else {
                    printf("TIE %d\n", (0x7FFF & d1));
                }
            }
            
          }
      }
  }
  return 0;
}

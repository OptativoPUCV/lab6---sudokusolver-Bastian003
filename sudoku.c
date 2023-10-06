#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  

  for (int i=0;i<9;i++) {
    int fila[10]={0};
    int columna[10]={0};
  
    int submatriz[10]={0};
    
    for (int j=0;j<9;j++) {
      int dato=n->sudo[i][j];

      if(fila[dato]==0){
        fila[dato]=1;
      }

      int dato_columna=n->sudo[j][i];

      
      if(columna[dato_columna]==0) {
        columna[dato_columna]=1;
      }
      

      int submatriz_1=3*(i/3)+(j/3);
      int submatriz_2=3*(i%3)+(j%3);

      
      int submatriz_dato=n->sudo[submatriz_1 ][submatriz_2];

      if(submatriz[submatriz_dato]==0){
        submatriz[submatriz_dato]=1;
      }
      
    }
  }
  
  return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(n->sudo[i][j]==0){
        int aux;
        
        for(aux=1;aux<9;aux++){
          Node* adyacente=copy(n);
          adyacente->sudo[i][j]=aux;
          pushBack(list, adyacente);
        }
      return list;
      }
    }
  }
  
  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/
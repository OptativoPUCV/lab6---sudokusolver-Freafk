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

int leerMatriz(Node *n){

  

  return 1;
}


int is_valid(Node* n){
  int *lista=malloc(sizeof(int)*10);
  for(int i=0;i<10;i++){
    lista[i]=0;
  }
  int k,aux=0;
  while(k!=12){
    for(int i=k;i<9;i++){
      for(int j=k;j<3;j++){
        
        printf("%d",n->sudo[i][j]);
        if(n->sudo[i][j]!=0  && lista[n->sudo[i][j]]==0){
          lista[n->sudo[i][j]]=1;
        
        }
        else if(n->sudo[i][j]!=0  && lista[n->sudo[i][j]]==1){
          aux=1;
          break;
        }
        
      }
      printf("\n");
      if(i!=0 && (i+1)%3==0){
        for(int i=0;i<10;i++){
        lista[i]=0;
        }
      }
      if(aux==1){
        return 0;
      }
      
    }
    k+=3;
  }

  

  return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    int i,j;
    int aux=0;
    for(i=0;i<9;i++){
      for(j=0;i<9;i++){
        if(n->sudo[j][i]==0){
          aux=1;
          break;
        }
      }
      if(aux==1){
        break;
      }
    }

    if(aux==1){
      
    
      for( aux=1;aux<10;aux++){
        Node *nodo=createNode();
        nodo=copy(n);
        nodo->sudo[j][i]=aux;
        
        pushBack(list, nodo);  
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
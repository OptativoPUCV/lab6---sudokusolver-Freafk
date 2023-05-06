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
  int *lista=malloc(sizeof(int)*10);
  int *listaFila=malloc(sizeof(int)*10);
  int *listaColumna=malloc(sizeof(int)*10);
  for(int i=0;i<10;i++){
    lista[i]=0;
    listaFila[i]=0;
    listaColumna[i]=0;
  }
  int k=0,p;
  while(k<9){
    
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        if(n->sudo[i][j]!=0 && listaFila[n->sudo[i][j]]==0){
          listaFila[n->sudo[i][j]]=1;
        }
        else if(n->sudo[i][j]!=0) {
          return 0;
        }
      }
      for(int i=0;i<10;i++){
        lista[i]=0;
        listaFila[i]=0;
        listaColumna[i]=0;
      }
  }
      
    
     for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        if(n->sudo[j][i]!=0 && listaColumna[n->sudo[j][i]]==0){
          listaColumna[n->sudo[j][i]]=1;
        }
        else if(n->sudo[j][i]!=0) {
          return 0;
        }
      }
       for(int i=0;i<10;i++){
        lista[i]=0;
        listaFila[i]=0;
        listaColumna[i]=0;
      }
      
    }
  
    for(p=0;p<9;p++){
        int i=3*(k/3) + (p/3) ;
        int j=3*(k%3) + (p%3) ;
        
        if(n->sudo[i][j]!=0 && lista[n->sudo[i][j]]==0){
          lista[n->sudo[i][j]]=1;
        }
        else if(n->sudo[i][j]!=0) {
          return 0;
        }
        
    }
    for(int i=0;i<10;i++){
      lista[i]=0;
    }
    
    k++;
  }
  free(lista);
  free(listaFila);
  free(listaColumna);


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
        if(is_valid(nodo)){
          pushBack(list, nodo);  
        }
      }
    }
   
    return list;
}


int is_final(Node* n){

  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(n->sudo[i][j]==0){
        return 0;
      }
        
    }
  }
  
  return 1;
}

Node* DFS(Node* initial, int* cont){

  Stack *nodo=createStack();
  push(nodo, initial);
  
  while(nodo!=NULL)
    {
      
      Node *current=top(nodo);
      pop(nodo);
      if(is_final(current)==1){
        return current;
      }
      List *listaNodos=get_adj_nodes(current);
      Node *currentLista=first(listaNodos);
    
      while(currentLista!=NULL){
        push(nodo, currentLista);
        
        currentLista=next(listaNodos);
      }
      
    }
  free(nodo);
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
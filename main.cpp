#include <iostream>
#include <time.h> 
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct processos{
  string nome;
  int pid;
  int valor[10];
};

processos p1;
processos p2;
processos p3;
processos p4;
processos p5;
processos p6;
processos p7;
processos p8;
processos p9;
processos p10;
vector<int> RC(1000);
queue<processos> filaProc;
char auxChar[2];
int posRC = 0;

FILE *arq = fopen("/home/cc06902801142/Área de Trabalho/registro.txt", "wt");

bool Existe (int valores[], int tam, int valor){
  for(int i = 0; i < tam; i++){
    if(valores[i]==valor){
      return true;
    }
  }
  return false;
}

void GerarValoresAleatorios(int numeros[]){
  int v;
  for(int i = 0; i<10;i++){
    v = rand() % 10 + 1;
    while(Existe(numeros,i,v)){
      v = rand() % 10 + 1;
    }
  numeros[i] = v;
  }
}


void rodar(){

  processos aux;
  for(int i = 0; i < 5; i++){
    aux = filaProc.front();
    auxChar[0] = aux.nome[0];
    auxChar[1] = aux.nome[1];
        RC.insert(RC.begin(), aux.valor, aux.valor+10);	
	      for(int j=0; j<10; j++){
	    fprintf(arq,"o processo %s inseriu na regiao critica o valor:  %i\n",auxChar,aux.valor[j]);	
}
    filaProc.pop();
}
    
for(int i = 0; i < 5; i++){

      if(RC[0]==0){
	for(int j=0; j < 10; j++){
           fprintf(arq, "o processo %s tentou remover da regiao critica, mas ela estava vazia\n", auxChar);
        }
	  
      }
      else{
	vector<int>::iterator it;
	int auxInt;
        for(int j=0; j < 10; j++){
	  it = RC.begin();
	  auxInt = (int) * it;
	  fprintf(arq,"o processo %s removeu da regiao o valor:  %i\n",auxChar,auxInt);
          RC.erase(RC.begin());	
        }

}
filaProc.pop();
}

}



int main(){

int ordemAleatoria[10];

for(int k=0; k<200; k++){

GerarValoresAleatorios(ordemAleatoria);
int v1[10],v2[10],v3[10],v4[10],v5[10],v6[10],v7[10],v8[10],v9[10],v10[10];
GerarValoresAleatorios(v1);
GerarValoresAleatorios(v2);
GerarValoresAleatorios(v3);
GerarValoresAleatorios(v4);
GerarValoresAleatorios(v5);
GerarValoresAleatorios(v6);
GerarValoresAleatorios(v7);
GerarValoresAleatorios(v8);
GerarValoresAleatorios(v9);
GerarValoresAleatorios(v10);


p1.nome = "p1";
p1.pid = 1;
p2.nome = "p2";
p2.pid = 2;
p3.nome = "p3";
p3.pid = 3;
p4.nome = "p4";
p4.pid = 4;
p5.nome = "p5";
p5.pid = 5;
p6.nome = "p6";
p6.pid = 6;
p7.nome = "p7";
p7.pid = 7;
p8.nome = "p8";
p8.pid = 8;
p9.nome = "p9";
p9.pid = 9;
p10.nome = "p10";
p10.pid = 10;

for (int i = 0; i < 10; i ++){
p1.valor[i] = rand() % 100 + 1;
p2.valor[i] = rand() % 100 + 1;
p3.valor[i] = rand() % 100 + 1;
p4.valor[i] = rand() % 100 + 1;
p5.valor[i] = rand() % 100 + 1;
p6.valor[i] = 0;
p7.valor[i] = 0;
p8.valor[i] = 0;
p9.valor[i] = 0;
p10.valor[i] = 0;
}


for (int i = 0; i < 10; i ++){
    if(ordemAleatoria[i]==p1.pid){
      filaProc.push(p1);
    }
    else if(ordemAleatoria[i]==p2.pid){
      filaProc.push(p2);
    }
    else if(ordemAleatoria[i]==p3.pid){
      filaProc.push(p3);
    }
    else if(ordemAleatoria[i]==p4.pid){
      filaProc.push(p4);
    }
    else if(ordemAleatoria[i]==p5.pid){
      filaProc.push(p5);
    }
    else if(ordemAleatoria[i]==p6.pid){
      filaProc.push(p6);
    }
    else if(ordemAleatoria[i]==p7.pid){
      filaProc.push(p7);
    }
    else if(ordemAleatoria[i]==p8.pid){
      filaProc.push(p8);
    }
    else if(ordemAleatoria[i]==p9.pid){
      filaProc.push(p9);
    }
    else if(ordemAleatoria[i]==p10.pid){
      filaProc.push(p10);
    }
  }


rodar();

}
fclose(arq);
}


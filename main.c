#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Esta versão inclui cores. Pode ser que o compilador não as aceite.
// Linha de declaração de cores
//Texto normal
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Texto normal negrito
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Texto normal sublinhado
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Texto normal fundo
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//Fundo de alta intensidade
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//Texto de alta intensidade
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Texto de alta intensidade em negrito
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Resetar a cor normalmente
#define reset "\e[0m"


//
struct no {
  int info;
  struct no *prox;
};

struct no * inserirInicioLista(struct no *L,int v){
  struct no *n;

  //Aloca espaco de memoria para o novo no
  n = (struct no *) malloc(sizeof(struct no));
  //Coloca o valor a ser inserido no campo info do novo no
  n->info = v;
  //Coloca no campo prox do novo no o endereco do primeiro no da Lista que
  //passara a ser o segundo no
  n->prox = L;
  //Faz o L apontar para o novo no que passara a ser o primeiro
  L = n;

  return L;
}//Fim inserirInicioLista()

void mostrarLista(struct no *L){
  struct no *p;

  if (L==NULL){
    printf(RED "Lista Vazia!" reset);
    return;
  }

  p = L; //Aponta p para o primeiro nó
  while (p!=NULL){ //Enquanto p for diferente de NULL (último nó)
    printf("%i->",p->info); //Imprime a informação do nó
    p = p->prox; //Passa para o próximo nó
  }

}//Fim mostrarLista()

struct no * inserirFimLista(struct no *L, int v){
  struct no *n, *p;

  //Aloca espaco de memória  para o novo nó
  n = (struct no *) malloc(sizeof(struct no));
  n->info = v;//Coloca a informação no novo nó
  n->prox = NULL; //Como será o último, já coloca NULL no prox.

  if (L==NULL){//Caso especial de Lista Vazia
    L = n;
    return L;
  }

  //Localiza o último nó da lista
  p = L;
  while (p->prox!=NULL)
    p = p->prox;

  //Faz o Encadeamento
  p->prox = n;

  return L;

}//Fim inserirFimLista()

struct no * removerDoInicio(struct no *L,int *v){
  struct no *p;

  *v = L->info; //Coloquei a informacao do no a ser removido em val através de *v
  p = L->prox; //Aponta p para o segundo nó que passará a ser o primeiro
  free(L);  //Libera memória utilizada pelo nó removido
  L = p; //Faz L apontar para o segundo que passará a ser o primeiro
  return L;
}//Fim removerDoInicio()

struct no *removerDoFim(struct no *L,int *v){
  struct no *p, *q;

  //Localizar o ultimo nó da Lista
  p = L;
  while (p->prox!=NULL) //Coloca p no ultimo nó da Lista
    p = p->prox;

  *v = p->info; //Coloca a informacao do nó a ser removido em val atraves de *v
  if (L->prox==NULL){ //Caso Especial de Lista com somente 1 nó
    free(p);
    L=NULL;
    return L;
  }
  q = L;
  while (q->prox!=p)  //Coloca q no nó anterior ao p
    q = q->prox;

  q->prox = NULL;
  free(p);

  return L;

}//Fim removerDoFim()

int comprimento(struct no *L){
  struct no *p;
  int cont=0;

  p = L; //Aponta p para o início da Lista
  while(p!=NULL){
    cont++;
    p = p->prox; //Avança p para o próximo nó
  }

  return cont;
}//Fim comprimento()

int existe(struct no *L,int v){ //verifica s eo valor existe e envia como flag
  struct no *p;
  int achou=0;

  p=L;
  while ((!achou)&&(p!=NULL)){
    if (p->info==v)
      achou=1;
    p=p->prox;
  }

  if (achou==1)
    return 1;
  else
    return 0;

}//Fim existe()

struct no * removePrimeiraOcorrencia(struct no *L,int v){
  struct no *p, *q;

  p=L;
  while ((p!=NULL)&&(p->info!=v)) //posiciona p no primeiro nó que possui o valor, ou atinge o Fim
    p = p->prox;

  if (p==NULL)
    return;

  if (p==L){  //o nó a ser removido é o primeiro da Lista
    L = p->prox; //Faz o encadeamento
    free(p); //Libera memória
    return L;
  }

  q=L;
  while (q->prox!=p)  //Posiciona q no nó anterior ao p
    q = q->prox;

  q->prox = p->prox; //Faz o encadeamento

  free(p); //Libera memoria usada pelo nó removido

  return L;

}//Fim removePrimeiraOcorrencia()


struct no * removePosicaoPar(struct no *L){
  struct no *p, *q;
  int cont=0;

  p=L;
  while (p!=NULL){
    cont++;
	if(cont%2==0){
	q=L;
  while (q->prox!=p)  //Posiciona q no nó anterior ao p
    q = q->prox;

  q->prox = p->prox; //Faz o encadeamento

  free(p); //Libera memoria usada pelo nó removido

	}//Fim if
    p = p->prox;//Avança p para o próximo nó
	}//Fim while
	return L;
  if (p==NULL)
    return;


}//Fim removePrimeiraOcorrencia()



struct no * removeMaiorDaLista(struct no *L){
	struct no *p, *q;
	int maior = 0;
	p = L; //Aponta p para o primeiro nó

  while (p!=NULL){ //Enquanto p for diferente de NULL (último nó)
    if(p->info > maior){
    	maior = p->info;
	}
    p = p->prox; //Passa para o próximo nó
  }
  p=L;
  while ((p!=NULL)&&(p->info!=maior)) //posiciona p no primeiro nó que possui o valor, ou atinge o Fim
    p = p->prox;

  if (p==NULL)
    return;

  if (p==L){  //o nó a ser removido é o primeiro da Lista
    L = p->prox; //Faz o encadeamento
    free(p); //Libera memória
    return L;
  }

  q=L;
  while (q->prox!=p)  //Posiciona q no nó anterior ao p
    q = q->prox;

  q->prox = p->prox; //Faz o encadeamento

  free(p); //Libera memoria usada pelo nó removido

  return L;

}



void push(struct no **P,int v){
  struct no *n;

  n = (struct no *) malloc(sizeof(struct no));
  n->info = v;
  n->prox = *P;
  *P = n;

}//Fim push()

int pop(struct no **P){
  struct no *p;
  int v;

  p=*P; //aponta p para o no do TOPO
  v = p->info; //Peguei a informacao do no a ser removido
  *P = p->prox; //Faz o Pilha apontar p/ o proximo no
  free(p); //Libera memoria do no a ser removido
  return v; //retorna o valor do no removido

}//Fim pop()

void mostrarPilha1(struct no **Pilha1){
  struct no *Paux=NULL;
  int v;

  if (*Pilha1==NULL){
    printf(RED "Pilha Vazia!" reset);
    return;
  }
  //O primeiro estou removendo fora do while
  // para ficar na direcao certa quando imprimir
  v=pop(Pilha1);  //Retirei da Pilha Original
  printf(" %i\n",v); //Mostrei na tela
  push(&Paux,v); //Guarda na Pilha Auxiliar
  while(*Pilha1!=NULL){
    v=pop(Pilha1);  //Retirei da Pilha Original
    printf("        %i\n",v); //Mostrei na tela
    push(&Paux,v); //Guarda na Pilha Auxiliar
  }

  while (Paux!=NULL){
    v=pop(&Paux);  //Retira da Pilha Auxiliar
    push(Pilha1,v); //Coloca na Pilha Original
  }

}//Fim mostrarPilha()

struct no * copiaPilhaParaLista(struct no *L,struct no **Pilha1){
  struct no *n, *p;
  struct no *Paux=NULL;
	int v;
	int val;


	if (*Pilha1==NULL){
    printf(RED "Pilha Vazia!" reset);
    return;
  }


   while(*Pilha1!=NULL){
  v=pop(Pilha1);  //Retirei da Pilha Original
  //Aloca espaco de memória  para o novo nó
  n = (struct no *) malloc(sizeof(struct no));
  n->info = v;//Coloca a informação no novo nó
  n->prox = NULL; //Como será o último, já coloca NULL no prox.

  if (L==NULL){//Caso especial de Lista Vazia
    L = n;
    return L;
  }

  //Localiza o último nó da lista
  p = L;
  while (p->prox!=NULL)
    p = p->prox;

  //Faz o Encadeamento
  p->prox = n;

  push(&Paux,v);//Guarda na Pilha Auxiliar
}
  while (Paux!=NULL){
    v=pop(&Paux);  //Retira da Pilha Auxiliar
    push(Pilha1,v); //Coloca na Pilha Original
  }

  return L;

}//Fim copiaPilhaParaLista()
void mostrarPilha2(struct no **Pilha2){
  struct no *Paux=NULL;
  int v;

  if (*Pilha2==NULL){
    printf(RED "Pilha Vazia!" reset);
    return;
  }
  //O primeiro estou removendo fora do while
  // para ficar na direcao certa quando imprimir
  v=pop(Pilha2);  //Retirei da Pilha Original
  printf(" %i\n",v); //Mostrei na tela
  push(&Paux,v); //Guarda na Pilha Auxiliar
  while(*Pilha2!=NULL){
    v=pop(Pilha2);  //Retirei da Pilha Original
    printf("        %i\n",v); //Mostrei na tela
    push(&Paux,v); //Guarda na Pilha Auxiliar
  }

  while (Paux!=NULL){
    v=pop(&Paux);  //Retira da Pilha Auxiliar
    push(Pilha2,v); //Coloca na Pilha Original
  }

}//Fim mostrarPilha2()

struct no *duplicaParPilha(struct no **Pilha1){
  struct no *Paux=NULL;
  int v;

  if (*Pilha1==NULL){
    printf(RED "Pilha Vazia!" reset);
    return;
  }
  //O primeiro estou removendo fora do while
  // para ficar na direcao certa quando imprimir
  v=pop(Pilha1);  //Retirei da Pilha Original
  push(&Paux,v); //Guarda na Pilha Auxiliar
  while(*Pilha1!=NULL){
    v=pop(Pilha1);  //Retirei da Pilha Original
    push(&Paux,v); //Guarda na Pilha Auxiliar
  }

  while (Paux!=NULL){
    v=pop(&Paux);  //Retira da Pilha Auxiliar
    push(Pilha1,v); //Coloca na Pilha Original
    if (v%2==0) { push(Pilha1,v);}
  }

}
struct no *somaImparesPilha(struct no **Pilha1){
  struct no *Paux=NULL;
  int v,valueImp=0;

  if (*Pilha1==NULL){
    printf(RED "Pilha Vazia!" reset);
    return;
  }
  //O primeiro estou removendo fora do while
  // para ficar na direcao certa quando imprimir
  v=pop(Pilha1);  //Retirei da Pilha Original
  push(&Paux,v); //Guarda na Pilha Auxiliar
  while(*Pilha1!=NULL){
    v=pop(Pilha1);  //Retirei da Pilha Original
    push(&Paux,v); //Guarda na Pilha Auxiliar
  }

  while (Paux!=NULL){
    v=pop(&Paux);  //Retira da Pilha Auxiliar
    if (v % 2 == 0) { } else { valueImp = valueImp+v; }
    push(Pilha1,v); //Coloca na Pilha Original
  }
  printf ("\n A Soma de todos os valores impares da sua pilha eh %i", valueImp);
}




int main(){
  setlocale(LC_ALL, "Portuguese");
  struct no *Lista;
  struct no *Pilha1;
  struct no *Pilha2;
  struct no *Pilha3;
  int val,ret,impValue;
  int op, op1;


  Lista = NULL;  //Cria a lista Vazia
  Pilha1 = NULL; //Inicializa Pilha Vazia
  Pilha2 = NULL; //Inicializa Pilha Vazia
  Pilha3 = NULL; // Inicializa pilha vazia
  do{
    printf(WHTHB BHBLK "\n\n***************  Menu Lista  ******************** ");
    printf("\n**************************************************");
    printf("\n** 1)  Inserir no Inicio da Lista               **");
    printf("\n** 2)  Mostrar Lista                            **");
    printf("\n** 3)  Inserir no Fim da Lista                  **");
    printf("\n** 4)  Remover do Inicio da Lista               **");
    printf("\n** 5)  Remover do Fim da Lista                  **");
    printf("\n** 6)  Comprimento da Lista                     **");
    printf("\n** 7)  Existe valor na Lista?                   **");
    printf("\n** 8)  Remove a Primeira ocorrencia de um Valor **");
    printf("\n** 9)  Remove posições pares da lista           **");
    printf("\n** 10) Remove maior valor                       **");
    printf("\n**----------------------------------------------**");
    printf("\n** 11) Push() - Inserir na Pilha                **");
    printf("\n** 12) Pop() - Remover da Pilha                 **");
    printf("\n** 13) Mostrar Pilha                            **");
    printf("\n** 14) Copiar pilha para lista                  **");
    printf("\n** 15) Duplicar Pilha em pares                  **");
    printf("\n** 16) Somar Valores Impares da Pilha           **");
    printf("\n** 0) Sair                                      **\n");
    printf("**************************************************");
    printf("\n**************************************************\n\n"reset);
    printf( GRN "\nOpcao-> "reset);
    fflush(stdin); scanf("%i",&op);

    switch(op){
    case 1: //Inserir no Inicio da Lista
      printf( CYN "\nDigite o valor: " reset);
      fflush(stdin); scanf("%i",&val);
        Lista = inserirInicioLista(Lista,val);
        printf(GRN"\n Valor %i inserido no inicio lista", val);
      break;
    case 2:
      printf( YEL "\nLista-> " reset);
      mostrarLista(Lista);
      break;
    case 3:  //Inserir no Fim da Lista
      printf( CYN "\nDigite o valor: " reset);
      fflush(stdin); scanf("%i",&val);
      Lista = inserirFimLista(Lista,val);
      printf ( GRN "\n Valor %i inserido no final da lista", val);
      break;
    case 4: //Remover o No do Inicio da Lista
      if (Lista == NULL){
        printf( RED "\nLista Vazia. Impossivel Remover!!!" reset);
      }
      else {
        Lista = removerDoInicio(Lista,&val);
        printf( GRN "\nValor Removido: %i " reset ,val);
      }
      break;
    case 5: //Remover o No do Fim da Lista
      if (Lista == NULL){
        printf(RED "\nLista Vazia. Impossivel Remover!!!" reset);
      }
      else {
        Lista = removerDoFim(Lista,&val);
        printf( GRN "\nValor Removido: %i " reset ,val);
      }
      break;
    case 6:  //Comprimento da Lista
        ret = comprimento(Lista);
        printf( CYN "\nComprimento da Lista: %i" reset ,ret);
        break;
    case 7: //Verificar se Existe um valor na Lista
        printf(CYN"\nDigite o valor a ser Localizado: " reset);
        fflush(stdin); scanf("%i",&val);
        if(existe(Lista,val)){
          printf(GRN"O Valor %i existe na Lista." reset,val);
        }else{
          printf(RED"O Valor %i NAO existe na Lista." reset,val);
        }
        break;
    case 8: //Remover o nó que contém a primeira ocorrencia de um valor
        printf(CYN"\nDigite o valor a ser Removido: " reset);
        fflush(stdin); scanf("%i",&val);
        if (!existe(Lista,val)){
          printf(RED"\nO valor %i NAO foi localizado na Lista. Impossível Remover!" reset,val);
        }else{
          Lista = removePrimeiraOcorrencia(Lista,val);
          printf(GRN"\nA primeira ocorrencia do valor %i foi removido com Sucesso." reset,val);
        }
        break;
	case 9://Remover o nó em posições pares da lista
		Lista = removePosicaoPar(Lista);
        printf(GRN"\nRemovido da lista" reset);
	break;
	case 10://Remover maior valor

		Lista = removeMaiorDaLista(Lista);
		printf("\nRemovido da lista");
		break;
	case 11: //push() - Inserir no TOPO da Pilha
        printf("\n Digite o valor: ");
        fflush(stdin); scanf("%i",&val);
        push(&Pilha1,val);
		break;
	case 12: //pop() - Remove o valor do TOPO da Pilha
        if(Pilha1==NULL)
        	printf("\nPilha Vazia. Impossivel remover.");
    	else
       		 printf("\nValor Removido: %i", pop(&Pilha1));
		break;
	case 13://Mostra a Pilha
        printf(YEL"\nPilha->"reset);
        mostrarPilha1(&Pilha1);
		break;
	case 14:

		if((Lista = copiaPilhaParaLista(Lista,&Pilha1)))
		printf(GRN"\nPilha movida com sucesso!"reset);
		break;
	case 15:
		duplicaParPilha(&Pilha1);
		break;
    case 16:
        somaImparesPilha(&Pilha1);
        break;
    }
  }while (op!=0);
return 0;
}//Fim main()

#include <stdio.h>
#include <stdlib.h>
const int L=20;
const int N=4;

struct Prodotto{
  char Nome[L+1];
  int Quantita;
  char Tipo;
  int Codice;
  int Prezzo;
};

struct Ricerca(struct Magazzino[N],int i);

int main(){
	
	struct Prodotto Magazzino[N];
	int Scelta,PIns,flag=1;
	
	do{
		
		printf("\n *BENVENUTO NEL MAGAZZINO* \n Cosa vuoi fare? \n 1-Inserisci Nuovo Prodotto \n 2-Aggiorna Prodotto \n 3-Stampa Sottoscorta \n 4-Visualizza codici in ordine \n 5-Visualizza prodotti magazzino \n");
		scanf("%d",&Scelta);
		
		if(Scelta==1){
			printf("\n Quanti Prodotti vuoi inserire? \n");
			scanf("%d",&PIns);
			
			//INSERISCI NUOVO PRODOTTO
			for(int i=0;i<PIns;i++){
			printf("\n Inserire il Nome del prodotto N.%d: \n ",i);
			scanf("%s",&Magazzino[i].Nome);
			
			Ricerca(Magazzino[N])
		
			//controllo!!!!!!
			//printf("\n %s ",Magazzino[i].Nome);
		
			printf("\n Inserire la Quantita' del prodotto N.%d: \n ",i);
			scanf("%d",&Magazzino[i].Quantita);
		
			//controllo!!!!!!
			//printf("\n %d ",Magazzino[i].Quantita);
		
			fflush(stdin);
		
			printf("\n Inserire il Tipo del prodotto N.%d: \n ",i);
			scanf("%c",&Magazzino[i].Tipo);
			
			fflush(stdin);	
		
			//controllo!!!!!!
			//printf("\n %c ",Magazzino[i].Tipo);
		
			printf("\n Inserire il Codice del prodotto N.%d: \n ",i);
			scanf("%d",&Magazzino[i].Codice);
		
			fflush(stdin);
		
			//controllo!!!!!!
			//printf("\n %d ",Magazzino[i].Codice);
		
			printf("\n Inserire il Prezzo del prodotto N.%d: \n ",i);
			scanf("%d",&Magazzino[i].Prezzo);
			
			//controllo!!!!!!
			printf("\n %d ",Magazzino[i].Prezzo);
			}
		}
		else if(Scelta==2){	
		
		//AGGIORNA PRODOTTO	
		//ricerca se il prodotto è già presente
		//ricerca se il prodotto è di quantità 0
		
		}
		
		printf("\n Vuoi continuare? [Si=1] [No=0] \n");
		scanf("%d",&flag);
		
	
	
		//VISUALIZZA CODICI IN ORDINE
	
		//VISUALIZZA PRODOTTI DEL MAGAZZINO
		
	}while(flag==1);
	
}

struct Ricerca(struct Magazzino[N]){
	for(int x=0;x<N;x++){
		if(Magazzino[x].Nome==Magazzino[i]Nome){
			flagRicerca=1;
		}
	}
}



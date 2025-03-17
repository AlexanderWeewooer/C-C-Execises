#include <stdio.h>
#include <stdlib.h>

typedef struct Treno_s{
	int StaSal; //Stazione di salita
	int StaDis; //Stazione di discesa
	
	int CurrPass; //Passeggeri correnti

	int IstArr; //Istante di arrivo
	int IstPart; //Istante di partenza

	struct Treno_s * next; // Puntatore al nodo successivo
}Treno;

Treno* LetturaFileLista(Treno *first);
//void StampaLista(Treno *first);
int NewStazione(Treno* p, int Stazioni);


int main(){
	
	int Stazioni=0; //Deve arrivare a 27 è un contatore
	int Tempo=0; // Deve arrivare a 3600 secondi
	int Ora=3600;
	Treno *first = NULL; //puntatore al primo nodo
	Treno *p = first;
	first = LetturaFileLista(first);
//	StampaLista(first);
	
	while(Tempo!=Ora || Stazioni==27){
		Tempo = NewStazione(p,Stazioni);
		Stazioni++;
	}
	
}

Treno* LetturaFileLista(Treno * first){
	
	char caratterevuoto;
	FILE *finput;
	int NumeroPasseggieri=0;
	int i=0;
	
	printf("\n\n Inizio lettura del file. \n");
	
	printf("\n\n Inserire il numero di passeggieri totale: \n ");
	scanf("%d",&NumeroPasseggieri);
	
	// p è il file di lettura (altri nomi non li prendeva non so perché)
	if((finput=fopen("p.txt","r"))==NULL){
		printf("\n\n Errore \n\n");
	}
	else{
		printf("\n\n si è aperto \n\n");

		while(i!=NumeroPasseggieri){
			Treno* current = (Treno*)malloc(sizeof(Treno));
			printf("\n\n Nodo nuovo! ");
			fscanf(finput, "%d", &current->StaSal);
	        printf("\n Stazione di Salita: %d", current->StaSal);
        	fscanf(finput, "%d", &current->IstArr);
        	printf("\n Istante di Arrivo: %d", current->IstArr);
        	fscanf(finput, "%d", &current->StaDis);
        	printf("\n Stazione di Discesa: %d", current->StaDis);
        	current = current->next;
        	i++;
		}
	
	}
    
    return first;
    
}

/*void StampaLista(Treno *first) {
		while(i!=NumeroPasseggieri){
			printf("\n\n Nodo nuovo! ");
	        printf("\n Stazione di Salita: %d", current->StaSal);
        	printf("\n Istante di Arrivo: %d", current->IstArr);
        	printf("\n Stazione di Discesa: %d", current->StaDis);
        	current = current->next;
        	i++;
		}
}*/

int NewStazione(Treno* p, int Stazioni){

	while(p!=NULL){
		if(p->StaSal==Stazioni){
		printf("\n Stazione di Salita: %d", p->StaSal);
		}	
		p=p->next;
	}

	
}

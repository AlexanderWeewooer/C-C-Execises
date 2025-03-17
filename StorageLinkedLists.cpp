#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int L = 20;

// Struct
struct Lista {
    char nome[L + 1];
    int prezzo;
    int giacenza;
    
    struct Lista* next;
};

typedef struct Lista Nodo;

// Funzioni
Nodo* inserisciNodo(Nodo* testa, const char nom[], int pre, int gia);
void stampaLista(const Nodo* testa);
void Choice(const Nodo* lista, int L, int N, const Nodo* testa);

int main() {
    
    Nodo* lista = NULL;
    int pre = 0, Flag = 0, gia = 0, N = 20 ;
    char nom[L + 1];

    while (Flag == 0) {

        printf("\n \n Inserire il nome del Prodotto= ");
        scanf("%s", nom);

        printf("\n \n Inserire il Prezzo= ");
        scanf(" %d", &pre);

        printf("\n \n Inserire la Giacenza= ");
        scanf("%d", &gia);

        lista = inserisciNodo(lista, nom, pre, gia);

        printf("\n \n Vuoi continuare a inserire? (Si=0 / No=1) ");
        scanf("%d", &Flag);
    }

    stampaLista(lista);
    
    Choice(lista, L, N, lista);

    // Libera la memoria allocata per la lista
    while (lista != NULL) {
        Nodo* temp = lista;
        lista = lista->next;
        free(temp);
    }

    return 0;
}

Nodo* inserisciNodo(Nodo* testa, const char nom[], int pre, int gia) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo)); // Allocazione di memoria per il nuovo nodo
    if (nuovoNodo == NULL) {
        fprintf(stderr, "Errore di allocazione di memoria\n");
        exit(1);
    }

    strcpy(nuovoNodo->nome, nom);
    nuovoNodo->prezzo = pre;
    nuovoNodo->giacenza = gia;
    
    nuovoNodo->next = testa; // Imposta il puntatore 'next' al nodo precedente

    return nuovoNodo;
}

void stampaLista(const Nodo* testa) {
    const Nodo* nodoCorrente = testa;

    while (nodoCorrente != NULL) {
        printf("\n \n Prodotto: %s\n", nodoCorrente->nome);
        printf(" Prezzo: %d\n", nodoCorrente->prezzo);
        printf(" Giacenza: %d \n\n", nodoCorrente->giacenza);

        nodoCorrente = nodoCorrente->next;
    }
}

void Choice(const Nodo* lista, int L, int N, const Nodo* testa) {
    int PC = 0, Risposta = 0;
    printf("\n Per cosa si vuole filtrare il magazzino? \n 1) Prezzo\n 2) Giacenza\n Risposta: ");
    scanf("%d", &Risposta);

    if (Risposta == 1) {
        printf("\n \n 1 \n \n");
        printf("Per quale prezzo si vuole filtrare: \n Prezzo = ");
        scanf("%d", &PC);

        const Nodo* nodoCorrente = lista;

        while (nodoCorrente != NULL) {
            if (PC == nodoCorrente->prezzo) {
                printf("\n \n Prodotto: %s\n", nodoCorrente->nome);
                printf(" Prezzo: %d\n", nodoCorrente->prezzo);
                printf(" Giacenza: %d \n\n", nodoCorrente->giacenza);
            }

            nodoCorrente = nodoCorrente->next;
        }
    }
    else if(Risposta == 2){
    	printf("\n \n 2 \n \n");
        printf("Per quale giacenza si vuole filtrare: \n Prezzo = ");
        scanf("%d", &PC);

        const Nodo* nodoCorrente = lista;

        while (nodoCorrente != NULL) {
            if (PC == nodoCorrente->giacenza) {
                printf("\n \n Prodotto: %s\n", nodoCorrente->nome);
                printf(" Prezzo: %d\n", nodoCorrente->prezzo);
                printf(" Giacenza: %d \n\n", nodoCorrente->giacenza);
            }

            nodoCorrente = nodoCorrente->next;
        }
	}
    else {
        printf("\n \n  ERRORE \n \n ");
    }
}



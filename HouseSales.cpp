#include <stdio.h>
#include <stdlib.h>
#include <float.h>

const int L = 20;

struct Lista {
    int MetriQuadri;
    char ClasseE;
    float Costo;
    struct Lista* next;
};

typedef struct Lista Nodo;

Nodo* inserisciNodo(Nodo* testa, int metriQuadri, char classeE, float costo);
void stampaLista(const Nodo* testa);
Nodo* cercaMinimoPerMetroQuadro(const Nodo* testa);
void Choice(Nodo* lista); // Rimozione della costante 'const'
Nodo* cercaMiglioreClasseEnergetica(const Nodo* testa);

int main() {
    Nodo* lista = NULL;
    int mq = 0, Flag = 0;
    char ce = 'A';
    float cos = 0;

    while (Flag == 0) {
        printf("\n \n Inserire i Metri Quadri= ");
        scanf("%d", &mq);

        printf("\n \n Inserire la Classe Energetica= ");
        scanf(" %c", &ce);

        printf("\n \n Inserire il Costo= ");
        scanf("%f", &cos);

        lista = inserisciNodo(lista, mq, ce, cos);

        printf("\n \n Vuoi continuare a inserire? (Si=0 / No=1) ");
        scanf("%d", &Flag);
    }

    stampaLista(lista);

    Choice(lista);

    return 0;
}

Nodo* inserisciNodo(Nodo* testa, int metriQuadri, char classeE, float costo) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovoNodo == NULL) {
        fprintf(stderr, "Errore di allocazione di memoria\n");
        exit(1);
    }

    nuovoNodo->MetriQuadri = metriQuadri;
    nuovoNodo->ClasseE = classeE;
    nuovoNodo->Costo = costo;
    nuovoNodo->next = testa;

    return nuovoNodo;
}

void stampaLista(const Nodo* testa) {
    const Nodo* nodoCorrente = testa;

    while (nodoCorrente != NULL) {
        printf("\n \n Metri Quadri: %d\n", nodoCorrente->MetriQuadri);
        printf("Classe Energetica: %c\n", nodoCorrente->ClasseE);
        printf("Costo: %.2f \n\n", nodoCorrente->Costo);

        nodoCorrente = nodoCorrente->next;
    }
}

Nodo* cercaMiglioreClasseEnergetica(const Nodo* testa) {
    const Nodo* nodoCorrente = testa;
    Nodo* nodoClasse = NULL;
    float min = FLT_MAX;

    while (nodoCorrente != NULL) {
        float lav; 

        switch (nodoCorrente->ClasseE) {
            case 'A':
                lav = 20.0;
                break;
            case 'B':
                lav = 40.0;
                break;
            case 'C':
                lav = 60.0;
                break;
            case 'D':
                lav = 80.0;
                break;
            case 'E':
                lav = 110.0;
                break;
            case 'F':
                lav = 140.0;
                break;
            default:
                lav = 160.0;
                break;
        }

        if (lav < min) {
            min = lav;
            nodoClasse = (Nodo*)nodoCorrente;
        }

        nodoCorrente = nodoCorrente->next;
    }

    return nodoClasse;
}

Nodo* cercaMinimoPerMetroQuadro(const Nodo* testa) {
    const Nodo* nodoCorrente = testa;
    Nodo* nodoMinimo = NULL;
    float minimo = FLT_MAX;

    while (nodoCorrente != NULL) {
        float costoPerMetroQuadro = nodoCorrente->Costo / nodoCorrente->MetriQuadri;

        if (costoPerMetroQuadro < minimo) {
            minimo = costoPerMetroQuadro;
            nodoMinimo = (Nodo*)nodoCorrente; 
        }

        nodoCorrente = nodoCorrente->next;
    }

    return nodoMinimo;
}

void Choice(Nodo* lista) { // Rimozione della costante 'const'
    int Risposta = 0;

    printf("\n Per cosa si vuole filtrare le Case? \n 1) Metri Quadri \n 2) Classe Energetica \n 3) Ricerca per range di metri quadri \n 4) Ricerca per classe energetica data \n \n Risposta: ");
    scanf("%d", &Risposta);

    if (Risposta == 1) {
        Nodo* nodoMinimo = cercaMinimoPerMetroQuadro(lista);

        if (nodoMinimo != NULL) {
            printf("\n \n Casa con il minor costo per metro quadro:\n");
            printf(" Metri Quadri: %d\n", nodoMinimo->MetriQuadri);
            printf(" Classe Energetica: %c\n", nodoMinimo->ClasseE);
            printf(" Costo: %.2f \n\n", nodoMinimo->Costo);
        } else {
            printf("Nessuna casa trovata nella lista.\n");
        }
    }
    else if (Risposta == 2) {
        Nodo* nodoClasse = cercaMiglioreClasseEnergetica(lista);

        if (nodoClasse != NULL) {
            printf("\n \n Casa con la miglior classe energetica:\n");
            printf(" Metri Quadri: %d\n", nodoClasse->MetriQuadri);
            printf(" Classe Energetica: %c\n", nodoClasse->ClasseE);
            printf(" Costo: %.2f \n\n", nodoClasse->Costo);
        } else {
            printf("Nessuna casa trovata nella lista.\n");
        }
    }
    else if (Risposta == 3) {
        int min, max;
        printf("Inserisci il range minimo di metri quadri: ");
        scanf("%d", &min);
        printf("Inserisci il range massimo di metri quadri: ");
        scanf("%d", &max);

        printf("\nCase con metri quadri nel range %d - %d:\n", min, max);

        int found = 0;
        Nodo* current = lista;
        while (current != NULL) {
            if (current->MetriQuadri >= min && current->MetriQuadri <= max) {
                printf(" Metri Quadri: %d\n", current->MetriQuadri);
                printf(" Classe Energetica: %c\n", current->ClasseE);
                printf(" Costo: %.2f \n\n", current->Costo);
                found = 1;
            }
            current = current->next;
        }

        if (!found) {
            printf("Nessuna casa trovata nel range specificato.\n");
        }
    } 
    else if (Risposta == 4) {
        char classeEnergetica;
        printf("Inserisci la classe energetica desiderata (A, B, C, etc.): ");
        scanf(" %c", &classeEnergetica);

        printf("\nCase con classe energetica %c:\n", classeEnergetica);

        int found = 0;
        Nodo* current = lista;
        while (current != NULL) {
            if (current->ClasseE == classeEnergetica) {
                printf(" Metri Quadri: %d\n", current->MetriQuadri);
                printf(" Classe Energetica: %c\n", current->ClasseE);
                printf(" Costo: %.2f \n\n", current->Costo);
                found = 1;
            }
            current = current->next;
        }

        if (!found) {
            printf("Nessuna casa trovata con la classe energetica specificata.\n");
        }
    }
    else {
        printf("Scelta non valida.\n");
    }
}


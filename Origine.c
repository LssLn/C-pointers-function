#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct s_studente {
    char cognome[128];
    char nome[128];
    char matricola[12];
    char cf[20];
} t_studente;
int confronta_nome(t_studente a, t_studente b) {
    int risultato;
    risultato = strcmp(a.cognome, b.cognome);
    if (risultato == 0) {
        return strcmp(a.nome, b.nome);
    }
    else
        return risultato;
}
int confronta_matricola(t_studente a, t_studente b) {
    return strcmp(a.matricola, b.matricola);
}
int ricerca_matricola(t_studente archivio[], int dim, t_studente s) {
    for (int i = 0; i < dim; ++i) {
        if (confronta_matricola(s, archivio[i]) == 0)
            return i;
    }
    return -1;
}
int ricerca(t_studente archivio[], int dim, int (*confronta)(t_studente a, t_studente b), t_studente s) {
    for (int i = 0; i < dim; ++i) {
        if (confronta(s, archivio[i]) == 0)
            return i;
    }
    return -1;
}
//typedef t_vettore(*t_puntatore_funzione)(t_vettore a, t_vettore b);
int main(void) {
    float x = 10.0;
    float y = 20.0;
    float z;
    int (*puntatore_funzione)(t_studente a, t_studente b) = NULL;
    t_studente a, b;
    t_studente elenco[100];
    int numero_elementi = 100;
    // confronta nome
    confronta_nome(a, b);
    // 
    confronta_matricola(a, b);
    //
    // voglio fare la ricerca
    ricerca(elenco, numero_elementi, confronta_matricola, a);
}

int main(void) {
    float * vettore = NULL; // Variabile puntatore da associare ad un vettore

  // utilizzo di malloc per allocare un vettore di 50 elementi
  vettore = (float *) malloc( 50 * sizeof(float));
  // esempio di inizialiazzione e stampa
  for(int i = 0; i < 50; ++i)
    vettore[i] = 0.0;

  for(int i = 0; i < 50; ++i)
    printf("vettore[%d] = %f\n", i, vettore[i]);
  // dopo l'uso utilizzo free per liberare la memoria
  free(vettore);
  vettore = NULL; // per evidenziare che l'area non � usata

  // utilizzo di calloc per allocare un vettore di 50 elementi
  vettore = (float *) calloc( 50, sizeof(float));
  // il vettore � gi� inizializzato a 0.0
  for(int i = 0; i < 50; ++i)
    printf("vettore[%d] = %f\n", i, vettore[i]);
  // dopo l'uso utilizzo free per liberare la memoria
  free(vettore);
  vettore = NULL; // per evidenziare che l'area non � usata
}
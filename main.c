/*
   # *******************************************************
   # Nom ......... : main.c
   # Rôle ........ : Exercices sur les commodités en C
   # Auteur ...... : Jeremy Fouquet
   # Version ..... : V1 2022
   # Licence ..... : Réalisé dans le cadre du cours de La Licence Informatique de L IED
   # Compilation :  gcc main.c
   # Execution : ./a.out
   # *******************************************************
*/

#include <stdio.h> // puts(), printf()
#include <stdlib.h> // exit()
#include <string.h> // strlen()

#define string char *
#define car(doublet) ((doublet)->car)
#define cdr(doublet) ((doublet)->cdr)
#define cadr(doublet) car(cdr(doublet))
#define caar(doublet) car(car(doublet))

typedef struct Doublet {struct Doublet * car ; struct Doublet * cdr ;} * list ; // structure de base ; list est un pointeur sur un doublet

void exercice_C(const string) ; // prototype
void usage(const string); // prototype
list cons(void *, const list) ; // prototype de la fonction cons
list push(void *, list); // prototype
void carUse(list, void *);
void cdrUse(list, void *);

int main(int argc, const char * argv[]) {
    exercice_C("C. Exercices sur les commodités");
    puts("");
    return 0;
}

void exercice_C(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "Construire en C une liste L à quatre éléments, dans le code du programme, à l’aide de cons. Testez car(L), car(cdr(L), car(cdr(cdr L)), car(cdr(cdr(cdr L))), en affichant leur résultat.");
    puts("");
    list L;
    int num[4] = {2, 4, 6, 8};
    for (int i = 0; num[i]; i++) {
        L = push(num[i], L);
    }
    printf("car(L) : %d\n", car(L));
    printf("car(cdr(L)) : %d\n", car(cdr(L)));
    printf("car(cdr(cdr(L))) : %d\n", car(cdr(cdr(L))));
    printf("car(cdr(cdr(cdr(L)))) : %d\n", car(cdr(cdr(cdr(L)))));

    printf("\n%s\n", "Définir en C, à l’aide de #define, caar et cadr. Construisez une liste pour les tester et afficher leur résultat.");
    puts("");
    printf("cadr(L) : %d\n", cadr(L));
    L = push(L, L);
    printf("caar(L) : %d\n", caar(L));
    printf("\n%s\n", "Définir en C car et cdr sans utiliser #define, comme des fonctions ordinaires. Reprenez la définition de la fonction cons() du cours ; qu’observez-vous ? Pourquoi ? Réécrivez la fonction cons() pour qu’elle soit compatible avec cette définition de car et cdr.");
}

void usage(const string D) {
    printf("Erreur en provenance de : %s\n", D);
    exit(1) ;
}
list push(void * elt, list L) {
    list Cons = malloc(sizeof(struct Doublet)) ; // allocation mémoire d'un doublet
//    car(Cons) = elt ;
//    cdr(Cons) = L ;
    carUse(Cons, elt) ;
    cdrUse(Cons, L) ;
    return Cons ;
}

void carUse(list Cons, void * elt){
    Cons->car = elt;
}
void cdrUse(list Cons, void * L){
    Cons->cdr = L;
}

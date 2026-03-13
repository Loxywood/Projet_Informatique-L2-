#include "include/plateau.h"
#include "include/entite.h"

void initRat(Entite *e){
    e->c = "R" ;
    e->PV = 3 ;
    e->bloque = true ;
    e->vitesse = 3 ;
    e->attaque = 1 ; 
    e->portee = 1 ;
}

void initJoueur(Entite *e){
    e->c = "J" ;
    e->PV = 5 ;
    e->bloque = true ;
    e->vitesse = 3 ;
    e->attaque = 2 ;
    e->portee = 1 ;
}


void initMur(Entite *e){
    e->c = "M" ;
    e->PV = 0 ;
    e->bloque = true ;
    e->vitesse = 0 ;
    e->attaque = 0 ;
    e->portee = 0 ;
}

void initVide(Entite *e){
    e->c = "V" ;
    e->PV = 0 ;
    e->bloque = false ;
    e->vitesse = 0 ;
    e->attaque = 0 ;
    e->portee = 0 ;
}

void conversion(Plateau P, int x, int y){


}
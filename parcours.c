
#include <stddef.h>
#include <stdlib.h>
#include "parcours.h"


void createDataMouv(dataMove *D){
    initAcces(D);    
    initKnown(D);   
    initNext(D);   
}

void initAcces(dataMove *D){
    D->acces = calloc( PLATEAU_WIDTH * PLATEAU_HEIGHT, sizeof(Vector) ) ;
    for (int i = 0 ; i < PLATEAU_WIDTH * PLATEAU_HEIGHT ; i++){
        D->acces[i].x = -1 ;
        D->acces[i].y = -1 ;
    }
    D->cursor_a = 0 ;
}

void initKnown(dataMove *D){
    D->known = calloc( PLATEAU_WIDTH * PLATEAU_HEIGHT, sizeof(Vector) ) ;
    for (int i = 0 ; i < PLATEAU_WIDTH * PLATEAU_HEIGHT ; i++){
        D->known[i].x = -1 ;
        D->known[i].y = -1 ;
    }
    D->cursor = 0 ;
}


void initNext(dataMove *D){
    D->next = calloc( PLATEAU_WIDTH * PLATEAU_HEIGHT, sizeof(Vector) ) ;
    for (int i = 0 ; i < PLATEAU_WIDTH * PLATEAU_HEIGHT ; i++){
        D->next[i].x = -1 ;
        D->next[i].y = -1 ;
    }
    D->cursor_n = 0 ;
}


void addKnown(dataMove *D, int x, int y){
    D->known[D->cursor].x = x ;
    D->known[D->cursor].y = y ;
    D->cursor++ ;
}


void addAcces(dataMove *D, int x, int y){
    D->acces[D->cursor_a].x = x ;
    D->acces[D->cursor_a].y = y ;
    D->cursor_a++ ;
}

void addNext(dataMove *D, int x, int y){
    D->next[D->cursor_n].x = x ;
    D->next[D->cursor_n].y = y ;
    D->cursor_n++ ;
}

int isIn(Vector * liste, int size, int x, int y){

    for (int i = 0 ; i < size ; i++){
        if (liste[i].x  == -1 && liste[i].y == -1 ) {
            return 0 ; //false : innexploré
        }
        else if(liste[i].x  == x && liste[i].y == y){
            return 1 ; //true : exploré
        }
    }
    return 0 ; //defaut
}


void procedure(dataMove *D, int x, int y){
    
    if (! (x > -1 && x < PLATEAU_WIDTH && y > -1 && y < PLATEAU_HEIGHT) ){ //déborde
        return ;
    }
    //hors plateau

    if ( isIn(D->acces, D->cursor_a, x, y) ){
        return ;
    }
    //deja traversé

    //on ajoutera les obstacles après

    addAcces(D, x, y) ;

    addNext(D, x-1, y) ;
    addNext(D, x+1, y) ;
    addNext(D, x, y-1) ;
    addNext(D, x, y+1) ;

}


void findAcces(dataMove *D, int x, int y, int mouvement){ //coordonnées et vitesse de deplacment restante
    
    procedure(D, x, y) ;

    for (int i = 0 ; i < mouvement ; i++ ){
        //déplace la liste pour qu'elle ne soit pas modifier quand on ajouter les elements suivants
        for (int elem = 0 ; elem < PLATEAU_WIDTH * PLATEAU_HEIGHT ; elem++){
            D->known[elem] = D->next[elem] ;
            D->cursor = D->cursor_n ;
        }

        initNext(D) ;

        //parcours la liste présente
        for (int n = 0 ; n < D->cursor ; n++){
            procedure(D, D->known[n].x , D->known[n].y ) ;
            //ajout des elements
        }
    }
}


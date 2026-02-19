#ifndef PARCOURS_H
#define PARCOURS_H


#include "tile.h"
#include "plateau.h"
#include <string.h>

typedef struct {
    int x ;
    int y ;
} Vector ;


typedef struct {
    Vector *acces ;
    int cursor_a  ;
    Vector *known ;
    int cursor ;
    Vector *next ;
    int cursor_n ;
} dataMove ;

void createDataMouv(dataMove *D) ;

void initAcces(dataMove *D) ;

void initKnown(dataMove *D) ;

void initNext(dataMove *D) ;

void addKnown(dataMove *D, int x, int y);

void addAcces(dataMove *D, int x, int y) ;

void addNect(dataMove *D, int x, int y) ;

int isIn(Vector * liste, int size, int x, int y) ; //pas besoin de data supplementaire

void procedure(dataMove *D, int x, int y) ;

void findAcces(dataMove *D, int x, int y, int mouvement) ;


#endif

#ifndef ENTITE_H
#define ENTITE_H




typedef struct Entite
{
    char c ; //pour qu'on puisse récuperer un elem qui dit en quoi convertir le void *
    int x ; int y ;
    bool bloque ;
    int PV ;
    int attaque ;
    int portee ;
    int vitesse ;
} Entite;

void initRat(Entite *e) ;

void initJoueur(Entite *e) ;

void initMur(Entite *e) ;

void mouvement(int posx, int posy, int dirx, int diry, Plateau *P) ;

void pousse(int posx, int posy, int dirx, int diry, Plateau *P) ;

void attaque() ;

#endif
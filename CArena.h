//
// Created by deloa on 10/28/2019.
//


#define UNTITLED22_CARENA_H

#include <vector>
#include <iostream>
using namespace std;
typedef int Tipo_tablero;
using namespace std;

class CArena{
private:
    Tipo_tablero alto;
    Tipo_tablero ancho;
    Tipo_tablero tr;
    Tipo_tablero*** tabo;
public:
    CArena(Tipo_tablero _alto, Tipo_tablero _ancho);
    void generar_puntos();//no recordaba que nombre le pondriamos
    Tipo_tablero getalto();
    Tipo_tablero getancho();
    void imprimir_Tab();
    void encaminar_bot(Tipo_tablero pos, vector<Tipo_tablero> Labierta, vector<Tipo_tablero> Lcerrada);
    bool comprobador(vector<Tipo_tablero> lista_cerrada, Tipo_tablero num);
    void removedor (vector<Tipo_tablero> lista_abierta, Tipo_tablero num);
    void dibujar_camino(Tipo_tablero _alto, Tipo_tablero _ancho);
    Tipo_tablero comparador (vector<Tipo_tablero> lista_abierta);};

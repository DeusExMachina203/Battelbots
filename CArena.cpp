#include "CArena.h"
#include <vector>
#include <cmath>
using namespace std;
typedef int Tipo_tablero;
CArena::CArena(Tipo_tablero _alto, Tipo_tablero _ancho){
    tr=5;
    if (_alto>=1 and _ancho>=1) {
        alto = _alto;
        ancho = _ancho;

        auto ***taba = new Tipo_tablero **[alto];

        for (Tipo_tablero i = 0; i < alto; i++)
            taba[i] = new Tipo_tablero *[ancho];

        for (Tipo_tablero j = 0; j < alto; j++) {
            for (Tipo_tablero i = 0; i < ancho; i++)
                taba[j][i] = new Tipo_tablero[tr];
        }
        Tipo_tablero nom = 0;
        for (Tipo_tablero i = 0; i < alto; i++) {
            for (Tipo_tablero j = 0; j < ancho; j++) {

                for (Tipo_tablero k = 0; k < tr; k++) {
                    taba[i][j][k] = 0;
                }
            }
        }

        for (Tipo_tablero i = 0; i < alto; i++) {
            for (Tipo_tablero j = 0; j < ancho; j++) {
                taba[i][j][0] = nom;
                tabo = taba;
            }
        }
    }
    else
        cerr<< "invalid input";
}

void CArena::generar_puntos(){

}

Tipo_tablero CArena:: getalto(){return alto;}

Tipo_tablero CArena:: getancho(){return ancho;}

Tipo_tablero CArena::comparador(vector<Tipo_tablero> lista_abierta){
     Tipo_tablero saca= -1;
     for (int i = 0; i< lista_abierta.size(); i++){
        int alto1=(int)lista_abierta[i]/ancho;
        int ancho1=lista_abierta[i]-(((int)lista_abierta[i]/ancho)*ancho);
        if (tabo[alto1][ancho1][2]+tabo[alto1][ancho1][1]> saca)
            saca=lista_abierta[i];
    }
     return saca;
}
bool CArena:: comprobador(vector<Tipo_tablero> lista_cerrada, Tipo_tablero num){
    int verdura=0;
    bool valor=false;
    for (int i = 0 ; lista_cerrada.size()>i;i++){
        if(num == lista_cerrada[i])
            verdura=1;
    }
    if(verdura==1)
        valor = true;
    else
        valor = false;
    return valor;
}
void CArena:: removedor (vector <Tipo_tablero> lista_abierta, Tipo_tablero num){
    Tipo_tablero tal=-1;
    for(int i=0; i< lista_abierta.size(); i++){
        if (lista_abierta[i]==num)
            tal=i;
    lista_abierta.erase(lista_abierta.begin()+tal);
    }

}

void CArena:: imprimir_Tab(){
    for (Tipo_tablero i=0; i < alto; i++){
        for (Tipo_tablero j=0; j < ancho; j++) {
            cout << tabo[i][j][3] << " ";
        }
        cout<< endl;
    }
}
vector<Tipo_tablero> Labierta;
vector<Tipo_tablero> Lcerrada;

void CArena:: encaminar_bot(Tipo_tablero pos) {
    Tipo_tablero posfinal= (ancho * alto)-1;
    if (((int)pos/ancho) == 0 and pos-(((int)pos/ancho)*ancho) == 0) {
        if (!comprobador(Lcerrada, pos + ancho) and tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4] > tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            else {
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] = abs(
                        (((int)posfinal/ancho) - (((int) pos / ancho)+1))+ ((posfinal-(((int)pos/ancho)*ancho)) - (pos - (((int) pos / ancho) * ancho))));
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] += 10;
                Labierta.push_back(tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][0]);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][3] = ((int) pos / ancho);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][4] = pos - (((int) pos / ancho) * ancho);
            }
        }
        if (!comprobador(Lcerrada, pos + 1) and tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)+1))));
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);

        }

    } else if (((int)pos/ancho == 0 and pos-(((int)pos/ancho)*ancho) == ancho - 1)) {
        if (!comprobador(Lcerrada, pos + ancho) and tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4] > tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            else {
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] = abs(
                        (((int)posfinal/ancho) - (((int) pos / ancho)+1))+ ((posfinal-(((int)pos/ancho)*ancho)) - (pos - (((int) pos / ancho) * ancho))));
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] += 10;
                Labierta.push_back(tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][0]);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][3] = ((int) pos / ancho);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][4] = pos - (((int) pos / ancho) * ancho);
            }
        }

        if (!comprobador(Lcerrada, pos -ancho)and tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }

            tabo[((int)pos/ancho) - 1][(pos-(((int)pos/ancho)*ancho))][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)-1))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)))));
            tabo[((int)pos/ancho) - 1][pos-((int)pos/ancho)][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);

        }
    } else if (((int)pos/ancho) == alto - 1 and pos-(((int)pos/ancho)*ancho) == 0) {
        if (!comprobador(Lcerrada, pos -ancho)and tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }

            tabo[((int)pos/ancho) - 1][(pos-(((int)pos/ancho)*ancho))][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)-1))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)))));
            tabo[((int)pos/ancho) - 1][pos-((int)pos/ancho)][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);

        }
        if (!comprobador(Lcerrada, pos + 1) and tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)+1))));
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);

        }

    } else if (((int)pos/ancho) == alto - 1 and pos-(((int)pos/ancho)*ancho) == ancho - 1) {
        if (!comprobador(Lcerrada, pos -ancho)and tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }

            tabo[((int)pos/ancho) - 1][(pos-(((int)pos/ancho)*ancho))][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)-1))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)))));
            tabo[((int)pos/ancho) - 1][pos-((int)pos/ancho)][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);

        }
        if (!comprobador(Lcerrada, pos -1) and tabo[((int)pos/ancho) ][pos-(((int)pos/ancho)*ancho)-1][0]< alto*ancho+1) {

            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]+tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) - 1][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)-1))));
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) - 1][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][0]);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]=((int)pos/ancho);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][4]=pos-(((int)pos/ancho)*ancho);

        }
    } else if (((int)pos/ancho) == 0) {
        if (!comprobador(Lcerrada, pos + ancho) and tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4] > tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            else {
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] = abs(
                        (((int)posfinal/ancho) - (((int) pos / ancho)+1))+ ((posfinal-(((int)pos/ancho)*ancho)) - (pos - (((int) pos / ancho) * ancho))));
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] += 10;
                Labierta.push_back(tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][0]);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][3] = ((int) pos / ancho);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][4] = pos - (((int) pos / ancho) * ancho);
            }
        }
        if (!comprobador(Lcerrada, pos + 1) and tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)+1))));
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);

        }
        if (!comprobador(Lcerrada, pos -1) and tabo[((int)pos/ancho) ][pos-(((int)pos/ancho)*ancho)-1][0]< alto*ancho+1) {

            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]+tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) - 1][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)-1))));
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) - 1][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][0]);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]=((int)pos/ancho);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][4]=pos-(((int)pos/ancho)*ancho);

        }
    } else if (((int)pos/ancho) == alto - 1) {
        if (!comprobador(Lcerrada, pos -ancho)and tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }

            tabo[((int)pos/ancho) - 1][(pos-(((int)pos/ancho)*ancho))][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)-1))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)))));
            tabo[((int)pos/ancho) - 1][pos-((int)pos/ancho)][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);

        }
        if (!comprobador(Lcerrada, pos + 1) and tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)+1))));
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);

        }
        if (!comprobador(Lcerrada, pos -1) and tabo[((int)pos/ancho) ][pos-(((int)pos/ancho)*ancho)-1][0]< alto*ancho+1) {

            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]+tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) - 1][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)-1))));
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) - 1][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][0]);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]=((int)pos/ancho);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][4]=pos-(((int)pos/ancho)*ancho);

        }
    } else if (((int)pos/ancho) == 0) {
        if (!comprobador(Lcerrada, pos + ancho) and tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4] > tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            else {
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] = abs(
                        (((int)posfinal/ancho) - (((int) pos / ancho)+1))+ ((posfinal-(((int)pos/ancho)*ancho)) - (pos - (((int) pos / ancho) * ancho))));
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] += 10;
                Labierta.push_back(tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][0]);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][3] = ((int) pos / ancho);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][4] = pos - (((int) pos / ancho) * ancho);
            }
        }
        if (!comprobador(Lcerrada, pos + 1) and tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)+1))));
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);

        }
        if (!comprobador(Lcerrada, pos -ancho)and tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }

            tabo[((int)pos/ancho) - 1][(pos-(((int)pos/ancho)*ancho))][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)-1))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)))));
            tabo[((int)pos/ancho) - 1][pos-((int)pos/ancho)][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);

        }

    } else if (((int)pos/ancho) == ancho - 1) {
        if (!comprobador(Lcerrada, pos + ancho) and tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4] > tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            else {
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] = abs(
                        (((int)posfinal/ancho) - (((int) pos / ancho)+1))+ ((posfinal-(((int)pos/ancho)*ancho)) - (pos - (((int) pos / ancho) * ancho))));
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] += 10;
                Labierta.push_back(tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][0]);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][3] = ((int) pos / ancho);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][4] = pos - (((int) pos / ancho) * ancho);
            }
        }
        if (!comprobador(Lcerrada, pos -1) and tabo[((int)pos/ancho) ][pos-(((int)pos/ancho)*ancho)-1][0]< alto*ancho+1) {

            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]+tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) - 1][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)-1))));
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) - 1][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][0]);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]=((int)pos/ancho);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][4]=pos-(((int)pos/ancho)*ancho);

        }
        if (!comprobador(Lcerrada, pos -ancho)and tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }

            tabo[((int)pos/ancho) - 1][(pos-(((int)pos/ancho)*ancho))][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)-1))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)))));
            tabo[((int)pos/ancho) - 1][pos-((int)pos/ancho)][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);

        }
    } else {
        if (!comprobador(Lcerrada, pos + ancho) and tabo[((int)pos / ancho) + 1][pos - (((int)pos / ancho) * ancho)][0] < alto * ancho + 1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4] > tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            else {
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] = abs(
                        (((int)posfinal/ancho) - (((int) pos / ancho)+1))+ ((posfinal-(((int)pos/ancho)*ancho)) - (pos - (((int) pos / ancho) * ancho))));
                tabo[((int) pos / ancho) + 1][(pos - (((int) pos / ancho) * ancho))][2] += 10;
                Labierta.push_back(tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][0]);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][3] = ((int) pos / ancho);
                tabo[((int) pos / ancho) + 1][pos - (((int) pos / ancho) * ancho)][4] = pos - (((int) pos / ancho) * ancho);
            }
        }
        if (!comprobador(Lcerrada, pos -1) and tabo[((int)pos/ancho) ][pos-(((int)pos/ancho)*ancho)-1][0]< alto*ancho+1) {

            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]+tabo[((int)pos/ancho) + 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) - 1][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)-1))));
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) - 1][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][0]);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][3]=((int)pos/ancho);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)-1][4]=pos-(((int)pos/ancho)*ancho);

        }
        if (!comprobador(Lcerrada, pos -ancho)and tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)-1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);
                }
            }

            tabo[((int)pos/ancho) - 1][(pos-(((int)pos/ancho)*ancho))][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)-1))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)))));
            tabo[((int)pos/ancho) - 1][pos-((int)pos/ancho)][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][0]);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][3]=((int)pos/ancho);
            tabo[((int)pos/ancho) - 1][pos-(((int)pos/ancho)*ancho)][4]=pos-(((int)pos/ancho)*ancho);

        }
        if (!comprobador(Lcerrada, pos + 1) and tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]< alto*ancho+1) {
            if (comprobador(Labierta,pos+ancho)){
                if(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4] < tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][3]+tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)][4]+10){
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
                    tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);
                }
            }
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] = abs(
                    ((((int)posfinal/ancho) - (((int) pos / ancho)))) + ((posfinal-(((int)pos/ancho)*ancho)) - (pos - ((((int) pos / ancho) * ancho)+1))));
            tabo[((int)pos/ancho)][(pos-(((int)pos/ancho)*ancho)) + 1][2] += 10;
            Labierta.push_back(tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][0]);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][3]=((int)pos/ancho);
            tabo[((int)pos/ancho)][pos-(((int)pos/ancho)*ancho)+1][4]=pos-(((int)pos/ancho)*ancho);

        }
    }
    if (Labierta.empty()){
        cout<<"nay, no hay camino";
    }
    else {

        Tipo_tablero proxpos;
        proxpos = comparador(Labierta);
        if (proxpos + ancho == ((alto*ancho)-1) or proxpos + 1 == ((alto*ancho)-1)){
            tabo[alto-1][ancho-1][3]= ((int)proxpos/ancho);
            tabo[alto-1][ancho-1][4]= proxpos-(((int)proxpos/ancho)*ancho);
            Lcerrada.push_back(proxpos);
            removedor(Labierta, proxpos);
        }
        else {
            Lcerrada.push_back(proxpos);
            removedor(Labierta, proxpos);
            encaminar_bot(proxpos);
        }
    }

}


void CArena:: dibujar_camino( Tipo_tablero _alto ,Tipo_tablero _ancho){
    if (_alto!=0 and _ancho!=0) {
        cout << tabo[tabo[_alto][_ancho][3]][tabo[_alto][_ancho][3]][0] << endl;
        dibujar_camino(tabo[_alto][_ancho][3], tabo[_alto][_ancho][4]);
    }
}



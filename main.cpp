#include "CArena.h"

int main() {
    int a=10;
    int b=10;
    CArena Tablerobo(a, b);

    Tablerobo.encaminar_bot(0);
    Tablerobo.imprimir_Tab();
    Tablerobo.dibujar_camino(a,b);
    Tablerobo.imprimir_Tab();
    return 0;
}
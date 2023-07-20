#include <iostream>
#include <QApplication>

#include "window.h"

int main( int argc, char *argv[] ) {

    QApplication app ( argc, argv );
    Window widget;

    return app.exec();

}

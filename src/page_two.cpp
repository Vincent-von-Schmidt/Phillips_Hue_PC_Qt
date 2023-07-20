#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "page_two.h"
#include "QSideBar.h"

Page_Two::Page_Two() {

    QWidget* widget1 = new QWidget;
    QVBoxLayout* layout1 = new QVBoxLayout;
    QLabel* text1 = new QLabel( "page one" );
    layout1 -> addWidget( text1 );
    widget1 -> setLayout( layout1 );

    QWidget* widget2 = new QWidget;
    QVBoxLayout* layout2 = new QVBoxLayout;
    QLabel* text2 = new QLabel( "page two" );
    layout2 -> addWidget( text2 );
    widget2 -> setLayout( layout2 );

    QSideBar* side = new QSideBar;
    side -> add_widget( "page one", widget1 );
    side -> add_widget( "page two", widget2 );

    QVBoxLayout* layout = new QVBoxLayout;
    layout -> addWidget( side );

    this -> setLayout( layout );

}

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QScrollArea>
#include <QScrollBar>
#include <QFrame>
#include <QString>

#include "QSideBar.h"

QSideBar::QSideBar() {

    this -> counter = 0;

    this -> layout.addWidget( &side, 0 );
    this -> layout.addWidget( &stack, 1 );

    this -> setLayout( &this -> layout );

    connect( &this -> side, SIGNAL( currentRowChanged(int) ),
             &this -> stack, SLOT( setCurrentIndex(int) ));

}

void QSideBar::add_widget( const QString &text, QWidget* widget ) {

    // add visible text entry to side bar
    QListWidgetItem *item = new QListWidgetItem( text );
    this -> side.insertItem( this -> counter, item );

    QFrame* content = new QFrame;
    QVBoxLayout* layout = new QVBoxLayout;

    layout -> addWidget( widget );
    content -> setLayout( layout );

    /* QScrollArea* scroll_area = new QScrollArea; */
    /* QScrollBar* scroll_bar = new QScrollBar; */
    /* scroll_area -> setVerticalScrollBar( true ); */
    /* scroll_area -> setWidget( content ); */

    /* this -> stack.addWidget( scroll_area ); */
    this -> stack.addWidget( content );
    this -> counter++;

}

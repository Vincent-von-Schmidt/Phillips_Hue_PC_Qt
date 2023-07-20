#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include "window.h"
#include "QSideBar.h"
#include "page_one.h"
#include "page_two.h"

Window::Window() {

    QVBoxLayout* layout = new QVBoxLayout;

    Page_One* one = new Page_One;
    Page_Two* two = new Page_Two;

    /* Page_One one; */
    /* Page_Two two; */

    QSideBar* menu = new QSideBar;    
    menu -> add_widget( "one", one );
    menu -> add_widget( "two", two );
    layout -> addWidget( menu );

    this -> setLayout( layout );
    this -> resize( 1280, 720 );
    this -> show();

}

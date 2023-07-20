#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include "page_one.h"

using json = nlohmann::json;

Page_One::Page_One() {

    this -> state_light = false;

    QLabel *hello_world = new QLabel ( "Page One" );
    QPushButton *test_button = new QPushButton;

    test_button -> setText( "Test Button" );
    connect( test_button, &QPushButton::clicked, this, &Page_One::handle_button );
    /* connect( */
    /*     test_button, SIGNAL( clicked ), */
    /*     this, SLOT( this -> handle_button ) */
    /* ); */

    QVBoxLayout *layout = new QVBoxLayout;
    layout -> addWidget( hello_world );
    layout -> addWidget( test_button );

    this -> setLayout( layout );

}

void Page_One::handle_button() {

    cpr::Response response = cpr::Get(
        cpr::Url{"http://192.168.178.37/api/UoghabPi6o43qbmxud5U76fjgKF6BPtgznFCM-FT/lights/14"}
        /* cpr::Header{{"on", "state"}} */
    );

    std::string* response_text = &response.text;
    json response_json = json::parse( *response_text );

    std::cout << response_json["state"]["on"] << std::endl;

}

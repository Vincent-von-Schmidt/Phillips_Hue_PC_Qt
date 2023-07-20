#ifndef page_one_H
#define page_one_H

#include <QWidget>

class Page_One: public QWidget {

    private:

        bool state_light;

        void handle_button();

    public:

        Page_One();

};

#endif

#ifndef QSideBar_H
#define QSideBar_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QListWidget>
#include <QString>

class QSideBar: public QWidget {

    private:

        int counter;

        QHBoxLayout layout;
        QStackedWidget stack;
        QListWidget side;

    public:

        QSideBar();
        void add_widget( const QString &text, QWidget* widget );

};

#endif

//#include <QCoreApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
//#include <iostream>
int main(int argc, char *argv[])
{
    //QCoreApplication app(argc, argv);
    QApplication app(argc, argv);
    QLabel lbl("Hello, world!");
    lbl.show();
    return app.exec();

    return 0;
}

#ifndef DIFERENCIACION_H
#define DIFERENCIACION_H

#include <QMainWindow>

namespace Ui {
class diferenciacion;
}

class diferenciacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit diferenciacion(QWidget *parent = 0);
    ~diferenciacion();
    double funcion(double v);//funtion that we use for derivation

private:
    Ui::diferenciacion *ui;
public slots:
   void metodo8();//slot that proccess the method of derivation
   void deletes();//slot that clear the spinboxes and textbrowser
};

#endif // DIFERENCIACION_H

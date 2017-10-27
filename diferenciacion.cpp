#include "diferenciacion.h"
#include "ui_diferenciacion.h"
#include <QString>  //Header to use strings
#include <cmath>    //Header for the use of mathematical funtions.
diferenciacion::diferenciacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::diferenciacion)
{
    ui->setupUi(this);
    // Conexions
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(metodo8()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(deletes()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
}

diferenciacion::~diferenciacion()
{
    delete ui;
}
double diferenciacion::funcion(double v)
{
    return
 (0.1*pow(v,4))+(0.25*pow(v,3))+(0.5*pow(v,2)+(0.25*v)+1.2);
}

void diferenciacion::metodo8()
{
    QString temp,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10,temp11,temp12,
    temp13,temp14,temp15,temp16,temp17,temp18,temp19,temp20,temp21,temp22,temp23,temp24,temp25; //Strings for temporal use.

    double xi=ui->doubleSpinBox->value();   //Recovers the value of Xi  from the spinbox.
    double fxi=ui->doubleSpinBox_2->value();   //Recovers the value of  X(i+1) from the spinbox.
    double xi_mas_1=ui->doubleSpinBox_3->value();   //Recovers the value of Xi  from the spinbox.
    double fx_i_mas_1=ui->doubleSpinBox_4->value();   //Recovers the value of Xi  from the spinbox.
    double x_i_mas_2=ui->doubleSpinBox_5->value();   //Recovers the value of Xi  from the spinbox.
    double fx_i_mas_2=ui->doubleSpinBox_6->value();   //Recovers the value of Xi  from the spinbox.
    double x_i_menos_1=ui->doubleSpinBox_7->value();   //Recovers the value of Xi  from the spinbox.
    double fx_i_menos_1=ui->doubleSpinBox_8->value();   //Recovers the value of Xi  from the spinbox.
    double x_i_menos_2=ui->doubleSpinBox_9->value();   //Recovers the value of Xi  from the spinbox.
    double fx_i_menos_2=ui->doubleSpinBox_10->value();   //Recovers the value of Xi  from the spinbox.
    double x_i_menos_3=ui->doubleSpinBox_12->value();   //Recovers the value of Xi  from the spinbox.
    double fx_i_menos_3=ui->doubleSpinBox_13->value();   //Recovers the value of Xi  from the spinbox.
    double x_i_mas_3=ui->doubleSpinBox_14->value();   //Recovers the value of Xi  from the spinbox.
    double fx_i_mas_3=ui->doubleSpinBox_15->value();   //Recovers the value of Xi  from the spinbox.
    double x_i_mas_4=ui->doubleSpinBox_16->value();   //Recovers the value of Xi  from the spinbox.
    double fx_i_mas_4=ui->doubleSpinBox_17->value();
    double x_i_menos_4=ui->doubleSpinBox_18->value();   //Recovers the value of Xi  from the spinbox.
    double fx_i_menos_4=ui->doubleSpinBox_19->value();

    double h=ui->doubleSpinBox_11->value();   //Recovers the value of Xi  from the spinbox.

    double derivada1,derivada2,derivada3,derivada4,derivada5,derivada6,derivada7,derivada8,derivada9,derivada10,derivada11,derivada12;
    double error1,error2,error3,error4,error5,error6,error7,error8,error9,error10,error11,error12;

    derivada1= (fxi-fx_i_menos_1)/h;
    error1= abs(derivada1-funcion(x_i_menos_1));
    derivada2= (fxi-2*fx_i_menos_1+fx_i_menos_2)/(h*h);
    error2= abs(derivada2-funcion(x_i_menos_2));
    derivada3= fxi-3*fx_i_menos_1+3*fx_i_menos_2-fx_i_menos_3/(h*h*h);
    error3= abs(derivada2-funcion(x_i_menos_3));
    derivada4= (fxi-4*fx_i_menos_1+6*fx_i_menos_2-4*fx_i_menos_3+fx_i_menos_4)/(h*h*h*h);
    error4= abs(derivada4-funcion(x_i_menos_4));

    derivada5= (fx_i_mas_1-fx_i_menos_1)/2*h;
    error5= abs(derivada5-funcion(xi));
    derivada6= (fx_i_mas_1-2*fxi+fx_i_menos_1)/(h*h);
    error6= abs(derivada6-funcion(xi));
    derivada7= (fx_i_mas_2-2*fx_i_mas_1+2*fx_i_menos_1-fx_i_menos_2)/2*(h*h*h);
    error7= abs(derivada7-funcion(xi));
    derivada8= (fx_i_mas_2-4*fx_i_mas_1+6*fxi-4*fx_i_menos_1+fx_i_menos_2)/(h*h*h*h);
    error8= abs(derivada8-funcion(xi));

    derivada9=(fx_i_mas_1-fxi)/h;
    error9=abs(derivada9-funcion(xi_mas_1));
    derivada10=(fx_i_mas_2-2*fx_i_mas_1+fxi)/(h*h);
    error10=abs(derivada10-funcion(x_i_mas_2));
    derivada11=(fx_i_mas_3-3*fx_i_mas_2+3*xi_mas_1-fxi)/(h*h*h);
    error11=abs(derivada11-funcion(x_i_mas_3));
    derivada12=(fx_i_mas_4-(4*fx_i_mas_3)+(6*x_i_mas_2)-(4*fx_i_mas_1+3*fxi))/(h*h*h*h);
    error12=abs(derivada12-funcion(x_i_mas_4));


temp
        .append("\nPRIMERA DERIVADA\n")
            .append("Derivada trasera\n")
                .append("f(x)'=").append(temp2.setNum(derivada1)).append("\tError=").append(temp3.setNum(error1))
            .append("\nDerivada centrada\n")
                .append("f(x)'=").append(temp4.setNum(derivada2)).append("\tError=").append(temp5.setNum(error2))
            .append("\nDerivada delantera\n")
                .append("f(x)'=").append(temp6.setNum(derivada3)).append("\tError=").append(temp7.setNum(error3))
       .append("\n\nSEGUNDA DERIVADA\n")
            .append("Derivada trasera\n")
                .append("f(x)''=").append(temp8.setNum(derivada4)).append("\tError=").append(temp9.setNum(error4))
            .append("\nDerivada centrada\n")
                .append("f(x)''=").append(temp10.setNum(derivada5)).append("\tError=").append(temp11.setNum(error5))
            .append("\nDerivada delantera\n")
                .append("f(x)''=").append(temp12.setNum(derivada6)).append("\tError=").append(temp13.setNum(error6))
        .append("\n\nTERCERA DERIVADA\n")
            .append("Derivada trasera\n")
                .append("f(x)'''=").append(temp14.setNum(derivada7)).append("\tError=").append(temp15.setNum(error7))
            .append("\nDerivada centrada\n")
                .append("f(x)'''=").append(temp16.setNum(derivada8)).append("\tError=").append(temp17.setNum(error8))
            .append("\nDerivada delantera\n")
                .append("f(x)'''=").append(temp18.setNum(derivada9)).append("\tError=").append(temp19.setNum(error9))
        .append("\n\nCUARTA DERIVADA\n")
             .append("Derivada trasera\n")
                 .append("f(x)''''=").append(temp20.setNum(derivada10)).append("\tError=").append(temp21.setNum(error10))
             .append("\nDerivada centrada\n")
                 .append("f(x)''''=").append(temp22.setNum(derivada11)).append("\tError=").append(temp23.setNum(error11))
             .append("\nDerivada delantera\n")
                 .append("f(x)''''=").append(temp24.setNum(derivada12)).append("\tError=").append(temp25.setNum(error12));  //It prepare the text to be display

ui->textBrowser->setText(temp);  //It presents the text.
}
void diferenciacion::deletes()
{
    ui->doubleSpinBox->setValue(0.0);  //clears the spinboxes
    ui->doubleSpinBox_2->setValue(0.0);
    ui->doubleSpinBox_3->setValue(0.0);
    ui->doubleSpinBox_4->setValue(0.0);
    ui->doubleSpinBox_5->setValue(0.0);
    ui->doubleSpinBox_6->setValue(0.0);
    ui->doubleSpinBox_7->setValue(0.0);
    ui->doubleSpinBox_8->setValue(0.0);
    ui->doubleSpinBox_9->setValue(0.0);
    ui->doubleSpinBox_10->setValue(0.0);
    ui->doubleSpinBox_11->setValue(0.0);
    ui->doubleSpinBox_12->setValue(0.0);  //clears the spinboxes
    ui->doubleSpinBox_13->setValue(0.0);
    ui->doubleSpinBox_14->setValue(0.0);
    ui->doubleSpinBox_15->setValue(0.0);
    ui->doubleSpinBox_16->setValue(0.0);
    ui->doubleSpinBox_17->setValue(0.0);
    ui->doubleSpinBox_18->setValue(0.0);
    ui->doubleSpinBox_19->setValue(0.0);

    ui->textBrowser->clear();     //clear textbowser
}

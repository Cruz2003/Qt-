#include "widget.h"
#include "./ui_widget.h"
QString num1;
QString num2;
QString res;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_7_clicked()
{
    ui->lineEdit->insert("1");
    num1.insert("1");
}


void Widget::on_Widget_customContextMenuRequested(const QPoint &pos)
{

}


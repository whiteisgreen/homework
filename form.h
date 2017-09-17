#ifndef FORM_H
#define FORM_H
#include"form2.h"
#include "BST.h"

#include <QWidget>
#include <QPaintEvent>
#include <QLabel>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);


    BST<int> *bst;
    Form2 *c;

    void paintEvent(QPaintEvent *);
    void visit(BinNode<int>&);

    ~Form();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

     void on_pushButton_4_clicked();

      void on_pushButton_5_clicked();
      void on_pushButton_6_clicked();

      void on_pushButton_7_clicked();

      void on_pushButton_8_clicked();

      void on_pushButton_9_clicked();


private:
    Ui::Form *ui;
    QLabel*leaves;
    int paintsign;//在paintevent中重绘

};

#endif // FORM_H

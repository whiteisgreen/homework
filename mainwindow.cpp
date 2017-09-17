#include "mainwindow.h"
#include "form.h"
#include "ui_mainwindow.h"


#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()  //点击建立二叉树
{
    bool ok;
    //d = new DrawWidget;
    if(!list2.isEmpty())
    {d=new Form;
    //d::BST(bst);
    //QString num = elem->text();
    //int n = num.toInt();

    for(int i=0;i<sizeof_tree;i++)
    d->bst->insert(list2[i].toInt(&ok,10));
    d->show();
    d->update();
    }
    else if(ok==false)
      {  D=new Dialog;
    D->show();
    }
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{

    // list2;
    list2= arg1.split(",");
    sizeof_tree=list2.size();
    bool ok;
    for(int i=0;i<sizeof_tree;i++)
        cout<<i<<"  "<<(list2[i].toInt(&ok,10))<<endl;
}


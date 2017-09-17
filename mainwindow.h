#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLineEdit>
#include <QPushButton>
#include <QTextStream>
#include <QStringList>

#include "Form.h"
#include"dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Form *d;
     Dialog*D;
    int sizeof_tree;
     QStringList list2;
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_pushButton_clicked();
    void on_lineEdit_textEdited(const QString &arg1);

};

#endif // MAINWINDOW_H

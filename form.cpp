#include "form.h"
#include "ui_form.h"
#include"side_function.h"


#include <QPainter>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    bst = new BST<int>;
}

Form::~Form()
{
    delete ui;
}


void Form::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if (!bst->empty())
    {
        bst->display(); //调用命令行显示 从而计算结点位置

        //层次遍历第一遍 画线
        Queue<BinNodePosi(int)> q;
        BinNodePosi(int) x = bst->root();
        q.enqueue(x);
        while (!q.empty())
        {
            x = q.dequeue();
            if (x)
            {
                if(paintsign==1)
                    painter.setPen(Qt::red);
                if (x && x->parent)
                    painter.drawLine(30*x->horizontal_position+30, 30+100 * x->distance_to_root, 30*x->parent->horizontal_position+30, 30+100 * x->parent->distance_to_root);
            }
            if (x->lchild) q.enqueue(x->lchild);
            if (x->rchild) q.enqueue(x->rchild);
        }

        //层次遍历第二遍 画结点
        x = bst->root();
        q.enqueue(x);
        while (!q.empty())
        {
            x = q.dequeue();
            if (x)
            {

                painter.setBrush(Qt::yellow);
                painter.drawEllipse(30*x->horizontal_position, 100 * x->distance_to_root, 60, 60);
                painter.drawText(30*x->horizontal_position+20, 100 * x->distance_to_root+30, QString::number(x->data));
            }

            if (x->lchild) q.enqueue(x->lchild);

            if (x->rchild) q.enqueue(x->rchild);
        }
    }

}



void Form::on_pushButton_clicked()
{

   int count_leaves=bst->size();
   QString s = QString::number(count_leaves, 10);
    leaves=new QLabel(s,this);
    leaves->setGeometry(930,50,50,20);
    leaves->show();

}


void Form::on_pushButton_2_clicked()
{

    //QPainter painter(this);
    Stack<BinNodePosi(int)> stk;
    BinNodePosi(int) x = bst->root();
    x = bst->root();
    if (x) stk.push(x);

    // Queue<BinNodePosi(int)> q;
    //q.enqueue(x);
    while (!stk.empty())
    {
        if (x->parent != stk.top())
        {
            while ((x = stk.top()) != NULL)
            {
                if (x->lchild)
                {
                    if (x->rchild)
                        stk.push(x->rchild);
                    stk.push(x->lchild);
                }
                else
                {
                    stk.push(x->rchild);
                }
            }
            stk.pop();
        }
        x = stk.pop();

            //painter.setBrush(Qt::yellow);
            //painter.drawEllipse(30*x->horizontal_position, 100 * x->distance_to_root, 60, 60);
            //painter.drawText(30*x->horizontal_position+20, 100 * x->distance_to_root+30, QString::number(x->data));
            QLabel*l_data;
           l_data=new QLabel(" "+QString::number(x->data),this);
            l_data->setGeometry(30*x->horizontal_position+16, 100 * x->distance_to_root+18,30,20);
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::white);
            l_data->setPalette(pe);
            l_data->setStyleSheet("background-color:red");
            l_data->show();
            stopforawhile(400);
    }

    stopforawhile(1000);
    Queue<BinNodePosi(int)> q;
   x = bst->root();
    q.enqueue(x);
    while (!q.empty())
    {
        x = q.dequeue();
        if (x)
        {

            QLabel*l_data;
           l_data=new QLabel(" "+QString::number(x->data),this);
            l_data->setGeometry(30*x->horizontal_position+16, 100 * x->distance_to_root+18,30,20);
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::black);
            l_data->setPalette(pe);
            l_data->setStyleSheet("background-color:yellow");
            l_data->show();        }

        if (x->lchild) q.enqueue(x->lchild);

        if (x->rchild) q.enqueue(x->rchild);
    }
    }

void Form::on_pushButton_3_clicked()
{

    Stack<BinNodePosi(int)> stk;
    BinNodePosi(int) x = bst->root();
    x = bst->root();
    if (x) stk.push(x);

    x = x->lchild;

    while (true)
    {
        while (x != NULL)
        {
            stk.push(x);
            x = x->lchild;
        }

        if (stk.empty()) break;

        x = stk.pop();
        //visit(x->data);



            //painter.setBrush(Qt::yellow);
            //painter.drawEllipse(30*x->horizontal_position, 100 * x->distance_to_root, 60, 60);
            //painter.drawText(30*x->horizontal_position+20, 100 * x->distance_to_root+30, QString::number(x->data));
            QLabel*l_data;
           l_data=new QLabel(" "+QString::number(x->data),this);
            l_data->setGeometry(30*x->horizontal_position+16, 100 * x->distance_to_root+18,30,20);
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::white);
            l_data->setPalette(pe);
            l_data->setStyleSheet("background-color:blue");
            l_data->show();
            stopforawhile(400);

            x = x->rchild;
    }
    stopforawhile(1000);
    Queue<BinNodePosi(int)> q;
   x = bst->root();
    q.enqueue(x);
    while (!q.empty())
    {
        x = q.dequeue();
        if (x)
        {

            QLabel*l_data;
           l_data=new QLabel(" "+QString::number(x->data),this);
            l_data->setGeometry(30*x->horizontal_position+16, 100 * x->distance_to_root+18,30,20);
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::black);
            l_data->setPalette(pe);
            l_data->setStyleSheet("background-color:yellow");
            l_data->show();        }

        if (x->lchild) q.enqueue(x->lchild);

        if (x->rchild) q.enqueue(x->rchild);
    }

  }

void Form::on_pushButton_4_clicked()
{
    Stack<BinNodePosi(int)> stk;
    BinNodePosi(int) x = bst->root();
    x = bst->root();

    stk.push(x);
    while (!stk.empty())
    {
        x = stk.pop();
        if (x != NULL) {
            QLabel*l_data;
           l_data=new QLabel(" "+QString::number(x->data),this);
            l_data->setGeometry(30*x->horizontal_position+16, 100 * x->distance_to_root+18,30,20);
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::white);
            l_data->setPalette(pe);
            l_data->setStyleSheet("background-color:green");
            l_data->show();
            stopforawhile(400);


        }
        if (x->rchild) stk.push(x->rchild);
        if (x->lchild) stk.push(x->lchild);
    }

    stopforawhile(1000);
    Queue<BinNodePosi(int)> q;
   x = bst->root();
    q.enqueue(x);
    while (!q.empty())
    {
        x = q.dequeue();
        if (x)
        {

            QLabel*l_data;
           l_data=new QLabel(" "+QString::number(x->data),this);
            l_data->setGeometry(30*x->horizontal_position+16, 100 * x->distance_to_root+18,30,20);
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::black);
            l_data->setPalette(pe);
            l_data->setStyleSheet("background-color:yellow");
            l_data->show();        }

        if (x->lchild) q.enqueue(x->lchild);

        if (x->rchild) q.enqueue(x->rchild);
    }

}


void Form::on_pushButton_5_clicked()
{
    stopforawhile(200);
   //bst->InThreading();
   c=new Form2;
   c->show();
}

void Form::on_pushButton_6_clicked()
{
    Stack<BinNodePosi(int)> stk;
    BinNodePosi(int) x = bst->root();
    x = bst->root();

    stk.push(x);
    while (!stk.empty())
    {
        x = stk.pop();
        if (x != NULL) {
            QLabel*l_data;
           l_data=new QLabel(" "+QString::number(x->data),this);
            l_data->setGeometry(30*x->horizontal_position+16, 100 * x->distance_to_root+18,30,20);
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::white);
            l_data->setPalette(pe);
            l_data->setStyleSheet("background-color:black");
            l_data->show();
            stopforawhile(400);


        }
        if (x->rchild) stk.push(x->rchild);
        if (x->lchild) stk.push(x->lchild);
    }

    stopforawhile(1000);
    Queue<BinNodePosi(int)> q;
   x = bst->root();
    q.enqueue(x);
    while (!q.empty())
    {
        x = q.dequeue();
        if (x)
        {

            QLabel*l_data;
           l_data=new QLabel(" "+QString::number(x->data),this);
            l_data->setGeometry(30*x->horizontal_position+16, 100 * x->distance_to_root+18,30,20);
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::black);
            l_data->setPalette(pe);
            l_data->setStyleSheet("background-color:yellow");
            l_data->show();        }

        if (x->lchild) q.enqueue(x->lchild);

        if (x->rchild) q.enqueue(x->rchild);
    }

}

void Form::on_pushButton_7_clicked()
{
    stopforawhile(200);
   //bst->InThreading();
   c=new Form2;
   c->show();
}

void Form::on_pushButton_8_clicked()
{
    Stack<BinNodePosi(int)> stk;
    BinNodePosi(int) x = bst->root();
    x = bst->root();
    if (x) stk.push(x);

    x = x->lchild;

    while (true)
    {
        while (x != NULL)
        {
            stk.push(x);
            x = x->lchild;
        }

        if (stk.empty()) break;

        x = stk.pop();
        //visit(x->data);



            //painter.setBrush(Qt::yellow);
            //painter.drawEllipse(30*x->horizontal_position, 100 * x->distance_to_root, 60, 60);
            //painter.drawText(30*x->horizontal_position+20, 100 * x->distance_to_root+30, QString::number(x->data));
            QLabel*l_data;
           l_data=new QLabel(" "+QString::number(x->data),this);
            l_data->setGeometry(30*x->horizontal_position+16, 100 * x->distance_to_root+18,30,20);
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::white);
            l_data->setPalette(pe);
            l_data->setStyleSheet("background-color:gray");
            l_data->show();
            stopforawhile(400);

            x = x->rchild;
    }
    stopforawhile(1000);
    Queue<BinNodePosi(int)> q;
   x = bst->root();
    q.enqueue(x);
    while (!q.empty())
    {
        x = q.dequeue();
        if (x)
        {

            QLabel*l_data;
           l_data=new QLabel(" "+QString::number(x->data),this);
            l_data->setGeometry(30*x->horizontal_position+16, 100 * x->distance_to_root+18,30,20);
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::black);
            l_data->setPalette(pe);
            l_data->setStyleSheet("background-color:yellow");
            l_data->show();        }

        if (x->lchild) q.enqueue(x->lchild);

        if (x->rchild) q.enqueue(x->rchild);
    }

}

void Form::on_pushButton_9_clicked()
{
    stopforawhile(200);
   //bst->PostThreading();
   c=new Form2;
   c->show();
}

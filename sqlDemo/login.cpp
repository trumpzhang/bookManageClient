#include "login.h"
#include "ui_login.h"
#include<QDebug>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    //为按钮添加背景图片
    ui->btn_login->setIcon(QIcon("://image/登陆.png"));
    ui->btn_login->setIconSize(QSize(25,25));
    ui->btn_cancelLogin->setIcon(QIcon("://image/取消.png"));
    ui->btn_cancelLogin->setIconSize(QSize(25,25));



}

login::~login()
{
    delete ui;
}

void login::on_btn_login_clicked()
{
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
        //设置数据库
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("book");
        db.setUserName("root");
        db.setPassword("123456");

        //打开mysql数据库
        if(!db.open() )
        {
            qDebug()<<"连接失败";
        }
        else
        {
            qDebug()<<"连接成功";

        }
        QSqlQuery query;
        //得到用户输入的字段
    QString account=ui->lineEdit_account->text();
    QString password=ui->lineEdit_password->text();
    if(account=="")
    {
        QMessageBox::warning(this,"警告","用户名不能为空！！！");
    }
    else if(password=="")
    {
        QMessageBox::warning(this,"警告","密码不能为空！！！");
    }
    else
    {
        /*使用数据库表中的记录登陆
        //组包方式1
        //QString sql=QString("select * from admin where account='%1' and password='%2' ").arg(account).arg(password);
        //组包方式2
        QString sql=QString("select * from admin where account='%1' and password='%2' ").arg(account,password);
        query.exec(sql);
        if(query.next())
        {
            qDebug()<<"登陆成功";
           // 生成主窗口test的一个对象
            mainWindow=new test();
            mainWindow->show();
            this->close();
            db.close();
        }

        */
        if(account=="admin" && password=="123456")
        {
            // 生成主窗口test的一个对象
             mainWindow=new test();
             mainWindow->show();
             this->close();
             db.close();
        }
        else
        {
            QMessageBox::warning(this,"Error","用户名或密码错误！！！");
             db.close();
        }

    }

}

void login::on_btn_cancelLogin_clicked()
{
    this->close();
}

void login::on_lineEdit_password_returnPressed()
{
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
        //设置数据库
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("book");
        db.setUserName("root");
        db.setPassword("123456");

        //打开mysql数据库
        if(!db.open() )
        {
            qDebug()<<"连接失败";
        }
        else
        {
            qDebug()<<"连接成功";

        }
        QSqlQuery query;
        //得到用户输入的字段
    QString account=ui->lineEdit_account->text();
    QString password=ui->lineEdit_password->text();
    if(account=="")
    {
        QMessageBox::warning(this,"警告","用户名不能为空！！！");
    }
    else if(password=="")
    {
        QMessageBox::warning(this,"警告","密码不能为空！！！");
    }
    else
    {
        //组包方式1
        //QString sql=QString("select * from admin where account='%1' and password='%2' ").arg(account).arg(password);
        //组包方式2
        QString sql=QString("select * from admin where account='%1' and password='%2' ").arg(account,password);
        query.exec(sql);
        if(query.next())
        {
            qDebug()<<"登陆成功";
           // 生成主窗口test的一个对象
            mainWindow=new test();
            mainWindow->show();
            this->close();
            db.close();
        }
        else
        {
            QMessageBox::warning(this,"Error","用户名或密码错误！！！");
             db.close();
        }

    }
}

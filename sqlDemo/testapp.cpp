#include "testapp.h"
#include "ui_testapp.h"

testApp::testApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testApp)
{
    ui->setupUi(this);
}

testApp::~testApp()
{
    delete ui;
}

void testApp::on_pushButton_clicked()
{
    tab=new TableWidget();
    tab->show();
}

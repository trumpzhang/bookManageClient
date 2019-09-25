#include "test.h"

#include "ui_test.h"
#include<QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QSqlTableModel>
#include<QSqlRecord>


test::test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
    //连接数据库
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
    //设置数据库
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("book");
    db.setUserName("root");
    db.setPassword("123456");

    //打开时数据库
    if(!db.open() )
    {
        qDebug()<<"连接失败";
    }
    else
    {
        qDebug()<<"连接成功";

    }

    //图书选项卡添加图标
    ui->tabWidget->setTabIcon(0,QIcon("://image/图书.png"));
    ui->tabWidget->setTabIcon(1,QIcon("://image/职工.png"));
    ui->tabWidget->setTabIcon(2,QIcon("://image/客户.png"));
    ui->tabWidget->setTabIcon(3,QIcon("://image/销售订单.png"));
    ui->tabWidget->setIconSize(QSize(25,25));
    qDebug()<<"iconSIze:"<<ui->tabWidget->iconSize();


    ui->btnAddBook->setIcon(QIcon("://image/新增.png"));
    ui->btnAddBook->setIconSize(QSize(25,25));

    ui->btn_delBook->setIcon(QIcon("://image/删 除 .png"));
    ui->btn_delBook->setIconSize(QSize(25,25));

    ui->btn_ok->setIcon(QIcon("://image/确定.png"));
    ui->btn_ok->setIconSize(QSize(25,25));

    ui->btn_cancel->setIcon(QIcon("://image/取消.png"));
    ui->btn_cancel->setIconSize(QSize(25,25));

    ui->btn_searchBook->setIcon(QIcon("://image/查找.png"));
    ui->btn_searchBook->setIconSize(QSize(25,25));

    ui->btnShowAllBook->setIcon(QIcon("://image/所有.png"));
    ui->btnShowAllBook->setIconSize(QSize(25,25));

    //职工选项卡添加图标
    ui->btn_add_worker->setIcon(QIcon("://image/新增.png"));
    ui->btn_add_worker->setIconSize(QSize(25,25));

    ui->btn_del_worker->setIcon(QIcon("://image/删 除 .png"));
    ui->btn_del_worker->setIconSize(QSize(25,25));

    ui->btn_ok_2->setIcon(QIcon("://image/确定.png"));
    ui->btn_ok_2->setIconSize(QSize(25,25));

    ui->btn_cancel_2->setIcon(QIcon("://image/取消.png"));
    ui->btn_cancel_2->setIconSize(QSize(25,25));

    ui->btn_search->setIcon(QIcon("://image/查找.png"));
    ui->btn_search->setIconSize(QSize(25,25));

    ui->btn_showAllWorker->setIcon(QIcon("://image/所有.png"));
    ui->btn_showAllWorker->setIconSize(QSize(25,25));
    //职工选项卡添加图标
    ui->btnAddCustomer->setIcon(QIcon("://image/新增.png"));
    ui->btnAddCustomer->setIconSize(QSize(25,25));

    ui->btn_delCus->setIcon(QIcon("://image/删 除 .png"));
    ui->btn_delCus->setIconSize(QSize(25,25));

    ui->btnOk->setIcon(QIcon("://image/确定.png"));
    ui->btnOk->setIconSize(QSize(25,25));
    ui->btn_cancel_3->setIcon(QIcon("://image/取消.png"));
    ui->btn_cancel_3->setIconSize(QSize(25,25));

    ui->pushButton_search_cus->setIcon(QIcon("://image/查找.png"));
     ui->pushButton_search_cus->setIconSize(QSize(25,25));

     ui->pushButton_allCus->setIcon(QIcon("://image/所有.png"));
     ui->pushButton_allCus->setIconSize(QSize(25,25));

    //销售信息选项卡添加图标
    ui->btnAddSale->setIcon(QIcon("://image/新增.png"));
    ui->btnAddSale->setIconSize(QSize(25,25));

    ui->btn_DelsaleInfo->setIcon(QIcon("://image/删 除 .png"));
    ui->btn_DelsaleInfo->setIconSize(QSize(25,25));

    ui->btn_ok_3->setIcon(QIcon("://image/确定.png"));
    ui->btn_ok_3->setIconSize(QSize(25,25));

    ui->pushButton_saleCancel->setIcon(QIcon("://image/取消.png"));
    ui->pushButton_saleCancel->setIconSize(QSize(25,25));

    ui->btn_saleSearch->setIcon(QIcon("://image/查找.png"));
    ui->btn_saleSearch->setIconSize(QSize(25,25));

    ui->btn_showAllSale->setIcon(QIcon("://image/所有.png"));
    ui->btn_showAllSale->setIconSize(QSize(25,25));

    ui->btnSaleInfo->setIcon(QIcon("://image/统计.png"));
    ui->btnSaleInfo->setIconSize(QSize(30,30));
    //设置模型，为模型使用构造函数

    bookModel=new QSqlTableModel();
    workerModel=new QSqlTableModel();
    cusModel=new QSqlTableModel();
    saleModel=new QSqlTableModel();
//   QSqlTableModel *saleModel=new QSqlTableModel();


    //指定表
    bookModel->setTable("book");
    workerModel->setTable("worker");
    cusModel->setTable("customer");
    saleModel->setTable("sale");

    //显示model里的所有数据
    bookModel->select();
    workerModel->select();
    cusModel->select();
    saleModel->select();

    //设置book的表头
    bookModel->setHeaderData(0,Qt::Horizontal,"图书编号");
    bookModel->setHeaderData(1,Qt::Horizontal,"书名");
    bookModel->setHeaderData(2,Qt::Horizontal,"作者");
    bookModel->setHeaderData(3,Qt::Horizontal,"版次");
    bookModel->setHeaderData(4,Qt::Horizontal,"单价（元）");
    bookModel->setHeaderData(5,Qt::Horizontal,"出版社");
    bookModel->setHeaderData(6,Qt::Horizontal,"所属类别");
    //设置worker的表头
    workerModel->setHeaderData(0,Qt::Horizontal,"职工号");
    workerModel->setHeaderData(1,Qt::Horizontal,"姓名");
    workerModel->setHeaderData(2,Qt::Horizontal,"性别");
    workerModel->setHeaderData(3,Qt::Horizontal,"电话");
    //设置customer的表头
    cusModel->setHeaderData(0,Qt::Horizontal,"客户编号");
    cusModel->setHeaderData(1,Qt::Horizontal,"姓名");
    cusModel->setHeaderData(2,Qt::Horizontal,"性别");
    cusModel->setHeaderData(3,Qt::Horizontal,"所在单位");
    cusModel->setHeaderData(4,Qt::Horizontal,"住址");
    cusModel->setHeaderData(5,Qt::Horizontal,"电话");
    //设置sale的表头
    saleModel->setHeaderData(0,Qt::Horizontal,"订单号");
    saleModel->setHeaderData(1,Qt::Horizontal,"图书号");
    saleModel->setHeaderData(2,Qt::Horizontal,"顾客号");
    saleModel->setHeaderData(3,Qt::Horizontal,"职工号");
    saleModel->setHeaderData(4,Qt::Horizontal,"销售日期");
    saleModel->setHeaderData(5,Qt::Horizontal,"售价（元）");
    saleModel->setHeaderData(6,Qt::Horizontal,"数量（本）");

    //把model放在view里面
    ui->tvBook->setModel(bookModel);
    ui->tvWorker->setModel(workerModel);
    ui->tvCus->setModel(cusModel);
    ui->tvSale->setModel(saleModel);
//  ui->tvBook->show();

    //设置model的编辑策略 为 手动提交修改
    bookModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    workerModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    cusModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    saleModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //设置不允许在view里直接修改数据
    //ui->tvBook->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

test::~test()
{

    delete ui;
}

void test::on_btnAddBook_clicked()
{
    //添加空记录
    QSqlRecord record=bookModel->record();

    int row=bookModel->rowCount();
    bookModel->insertRecord(row,record);

}

void test::on_btn_ok_clicked()
{
    bookModel->submitAll();
}

void test::on_btn_cancel_clicked()
{
    //取消完再提交一次
    bookModel->revertAll();
    bookModel->submitAll();
}

void test::on_btn_delBook_clicked()
{
    //获取选中的模型
     QItemSelectionModel *smodel=ui->tvBook->selectionModel();
     //获取模型中的索引
     QModelIndexList list=smodel->selectedRows();
     //删除所有选中的行
     for(int i=0;i<list.size();i++)
     {
         bookModel->removeRow(list.at(i).row());
     }

}

void test::on_btn_searchBook_clicked()
{
    QString name=ui->lineEditBookName->text();
    QString id=ui->lineEdit_BookId->text();
    QString author=ui->lineEdit_author->text();
    //组包
    QString str=QString("name like '%1' and id like '%2' and author like '%3' ").arg("%"+name+"%","%"+id+"%","%"+author+"%");
    //添加过滤器
    bookModel->setFilter(str);
    bookModel->select();

}

void test::on_btnShowAllBook_clicked()
{
    bookModel->setTable("book");//重新关联表
    bookModel->select();//再次显示所有数据
}


void test::on_btnSaleInfo_clicked()
{
    //此处的父对象不可填写 this，否则将不显示
    tableWidget=new TableWidget();


    tableWidget->show();
}

void test::on_btn_add_worker_clicked()
{
    //添加空记录
    QSqlRecord record=workerModel->record();

    int row=workerModel->rowCount();
    workerModel->insertRecord(row,record);
}

void test::on_btn_del_worker_clicked()
{
    //获取选中的模型
     QItemSelectionModel *smodel=ui->tvWorker->selectionModel();
     //获取模型中的索引
     QModelIndexList list=smodel->selectedRows();
     //删除所有选中的行
     for(int i=0;i<list.size();i++)
     {
        workerModel->removeRow(list.at(i).row());
     }
}

void test::on_btn_ok_2_clicked()
{
    workerModel->submitAll();
}

void test::on_btn_cancel_2_clicked()
{
    //取消完再提交一次
    workerModel->revertAll();
    workerModel->submitAll();
}

void test::on_btn_search_clicked()
{
    QString name=ui->lineEdit_workerName->text();
    QString id=ui->lineEdit_workerId->text();
    //组包
    QString str=QString("name like'%1' and id like'%2'").arg("%"+name+"%","%"+id+"%");
    //添加过滤器
    workerModel->setFilter(str);
    workerModel->select();

}

void test::on_btn_showAllWorker_clicked()
{
    workerModel->setTable("worker");//重新关联表
    workerModel->select();//再次显示所有数据
}

void test::on_btnAddCustomer_clicked()
{
    //添加空记录
    QSqlRecord record=cusModel->record();

    int row=cusModel->rowCount();
    cusModel->insertRecord(row,record);
}

void test::on_btn_delCus_clicked()
{
    //获取选中的模型
     QItemSelectionModel *smodel=ui->tvCus->selectionModel();
     //获取模型中的索引
     QModelIndexList list=smodel->selectedRows();
     //删除所有选中的行
     for(int i=0;i<list.size();i++)
     {
        cusModel->removeRow(list.at(i).row());
     }
}

void test::on_btnOk_clicked()
{
     cusModel->submitAll();
}

void test::on_btn_cancel_3_clicked()
{
    //取消完再提交一次
    cusModel->revertAll();
    cusModel->submitAll();
}

void test::on_pushButton_search_cus_clicked()
{
    QString name=ui->lineEditcusName->text();
    QString id=ui->lineEdit_2_cusId->text();
    QString addr=ui->lineEdit_addr->text();
    //组包
    QString str=QString("name like'%1' and id like'%2' and addr like'%3' ").arg("%"+name+"%","%"+id+"%","%"+addr+"%");
    //添加过滤器
    cusModel->setFilter(str);
    cusModel->select();
}

void test::on_pushButton_allCus_clicked()
{
    cusModel->setTable("customer");//重新关联表
    cusModel->select();//再次显示所有数据
}

void test::on_btn_saleSearch_clicked()
{
    QString book_id=ui->lineEdit_book_id_sale->text();
    QString customer_id=ui->lineEdit_cus_id_sale->text();
    QString worker_id=ui->lineEdit_worker_id->text();
    //组包
    QString str=QString("book_id like'%1' and customer_id like'%2' and "
                        "worker_id like '%3'").arg("%"+book_id+"%","%"+customer_id+"%","%"+worker_id+"%");
    //添加过滤器
    saleModel->setFilter(str);
    saleModel->select();
}

void test::on_btn_showAllSale_clicked()
{
    saleModel->setTable("sale");//重新关联表
    saleModel->select();//再次显示所有数据
}

void test::on_btnAddSale_clicked()
{
    //添加空记录
    QSqlRecord record=saleModel->record();

    int row=saleModel->rowCount();
    saleModel->insertRecord(row,record);
}

void test::on_btn_DelsaleInfo_clicked()
{
    //获取选中的模型
     QItemSelectionModel *smodel=ui->tvSale->selectionModel();
     //获取模型中的索引
     QModelIndexList list=smodel->selectedRows();
     //删除所有选中的行
     for(int i=0;i<list.size();i++)
     {
        saleModel->removeRow(list.at(i).row());
     }
}

void test::on_btn_ok_3_clicked()
{
     saleModel->submitAll();
}

void test::on_pushButton_saleCancel_clicked()
{
    //取消完再提交一次
    saleModel->revertAll();
    saleModel->submitAll();
}

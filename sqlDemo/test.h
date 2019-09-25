#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include<QSqlTableModel>
#include<QSqlDatabase>
#include"tablewidget.h"


namespace Ui {
class test;
}

class test : public QMainWindow
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = nullptr);


    ~test();

private slots:
    void on_btnAddBook_clicked();

    void on_btn_ok_clicked();

    void on_btn_cancel_clicked();

    void on_btn_delBook_clicked();

    void on_btn_searchBook_clicked();

    void on_btnShowAllBook_clicked();

    void on_btnSaleInfo_clicked();

    void on_btn_add_worker_clicked();

    void on_btn_del_worker_clicked();

    void on_btn_ok_2_clicked();

    void on_btn_cancel_2_clicked();

    void on_btn_search_clicked();

    void on_btn_showAllWorker_clicked();

    void on_btnAddCustomer_clicked();

    void on_btn_delCus_clicked();

    void on_btnOk_clicked();

    void on_btn_cancel_3_clicked();

    void on_pushButton_search_cus_clicked();

    void on_pushButton_allCus_clicked();

    void on_btn_saleSearch_clicked();

    void on_btn_showAllSale_clicked();

    void on_btnAddSale_clicked();

    void on_btn_DelsaleInfo_clicked();

    void on_btn_ok_3_clicked();

    void on_pushButton_saleCancel_clicked();

private:
    Ui::test *ui;
    TableWidget *tableWidget;

     QSqlTableModel *bookModel;
     QSqlTableModel *workerModel;
     QSqlTableModel *cusModel;
     QSqlTableModel *saleModel;

};

#endif // TEST_H

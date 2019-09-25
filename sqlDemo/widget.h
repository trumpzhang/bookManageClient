#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSqlTableModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_buttonAdd_clicked();

    void on_buttonOk_clicked();

    void on_buttonCancel_clicked();

    void on_buttonDel_clicked();

    void on_buttonQuery_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *model;
};

#endif // WIDGET_H

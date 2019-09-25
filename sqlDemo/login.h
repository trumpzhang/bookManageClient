#ifndef LOGIN_H
#define LOGIN_H


//将test主窗口的头文件包含进来，以便在用户登陆成功时生成主窗口
#include"test.h"
#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_btn_login_clicked();

    void on_btn_cancelLogin_clicked();

    void on_lineEdit_password_returnPressed();

private:
    test *mainWindow;
    Ui::login *ui;
};

#endif // LOGIN_H

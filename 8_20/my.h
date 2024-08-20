#ifndef MY_H
#define MY_H
#include "query.h"
#include "modify.h"
#include <QMainWindow>
#include "add_passenger.h"
namespace Ui {
class My;
}

class My : public QMainWindow
{
    Q_OBJECT

public:
    explicit My(QWidget *parent = nullptr);
    ~My();
    Modify *modify = NULL;
    Query *query = NULL;
    add_passenger *ad =NULL;
    void initialize();
    int delete_row ;

public slots:
    void updateOnBWindowClosed(); // 槽函数

signals:
    void back();
private slots:
    void on_back2_clicked();

    void on_look_clicked();

    void on_pushButton_clicked();

    void on_PassengerView_clicked(const QModelIndex &index);

private:
    Ui::My *ui;
};

#endif // MY_H

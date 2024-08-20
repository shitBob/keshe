#ifndef ITEMADMIN_H
#define ITEMADMIN_H

#include <QMainWindow>

namespace Ui {
class itemAdmin;
}

class itemAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit itemAdmin(QWidget *parent = nullptr);
    ~itemAdmin();
    void setTrainInfo(QString no,QString type,QString time,QString start,QString end,int price,int carriage);
private slots:
    void on_delete_2_clicked();

    void on_modify_clicked();

private:
    Ui::itemAdmin *ui;
};

#endif // ITEMADMIN_H

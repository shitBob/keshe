#ifndef MY_H
#define MY_H
#include "query.h"
#include "modify.h"
#include <QMainWindow>
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

signals:
    void back();
private slots:
    void on_back2_clicked();

    void on_modify_clicked();

private:
    Ui::My *ui;
};

#endif // MY_H

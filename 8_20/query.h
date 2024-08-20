#ifndef QUERY_H
#define QUERY_H

#include <QMainWindow>

namespace Ui {
class Query;
}

class Query : public QMainWindow
{
    Q_OBJECT

public:
    explicit Query(QWidget *parent = nullptr);
    ~Query();
signals:
    void back();
private slots:
    void on_back6_clicked();

private:
    Ui::Query *ui;
};

#endif // QUERY_H

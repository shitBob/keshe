#ifndef ADDTRAIN_H
#define ADDTRAIN_H

#include <QMainWindow>

namespace Ui {
class Addtrain;
}

class Addtrain : public QMainWindow
{
    Q_OBJECT

public:
    explicit Addtrain(QWidget *parent = nullptr);
    ~Addtrain();
signals:
    void back();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Addtrain *ui;
};

#endif // ADDTRAIN_H

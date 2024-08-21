#ifndef MODIFY_H
#define MODIFY_H

#include <QMainWindow>

namespace Ui {
class Modify;
}

class Modify : public QMainWindow
{
    Q_OBJECT

public:
    explicit Modify(QWidget *parent = nullptr);
    ~Modify();
signals:
    void back();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Modify *ui;
};

#endif // MODIFY_H

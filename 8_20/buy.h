#ifndef BUY_H
#define BUY_H

#include <QMainWindow>

namespace Ui {
class buy;
}

class buy : public QMainWindow
{
    Q_OBJECT

public:
    explicit buy(QWidget *parent = nullptr);
    ~buy();
    void initialize(QString no);
private:
    Ui::buy *ui;
};

#endif // BUY_H

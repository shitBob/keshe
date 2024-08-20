#ifndef MODIFYTRAIN_H
#define MODIFYTRAIN_H

#include <QMainWindow>

namespace Ui {
class Modifytrain;
}

class Modifytrain : public QMainWindow
{
    Q_OBJECT

public:
    explicit Modifytrain(QWidget *parent = nullptr);
    ~Modifytrain();

private:
    Ui::Modifytrain *ui;
};

#endif // MODIFYTRAIN_H

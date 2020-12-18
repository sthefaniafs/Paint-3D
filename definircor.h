#ifndef DEFINIRCOR_H
#define DEFINIRCOR_H

#include <QDialog>

namespace Ui {
class DefinirCor;
}

class DefinirCor : public QDialog
{
    Q_OBJECT

public:
    explicit DefinirCor(QWidget *parent = nullptr);
    ~DefinirCor();
    int getColorR();
    int getColorG();
    int getColorB();

private:
    Ui::DefinirCor *ui;
};

#endif // DEFINIRCOR_H

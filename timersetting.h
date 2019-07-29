#ifndef TIMERSETTING_H
#define TIMERSETTING_H

#include <QDialog>

namespace Ui {
class TimerSetting;
}

class TimerSetting : public QDialog
{
    Q_OBJECT

public:
    explicit TimerSetting(QWidget *parent = nullptr);
    ~TimerSetting();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::TimerSetting *ui;
};

#endif // TIMERSETTING_H

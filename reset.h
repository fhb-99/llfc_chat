#ifndef RESET_H
#define RESET_H

#include <QDialog>
#include <QJsonObject>
#include <QTimer>
#include "global.h"

namespace Ui {
class Reset;
}

class Reset : public QDialog
{
    Q_OBJECT

public:
    explicit Reset(QWidget *parent = nullptr);
    ~Reset();

private slots:
    void on_getVarifyC_clicked();
    void on_yes_btn_clicked();
    void on_no_btn_clicked();
    void slot_req_mod_finish(ReqId id, QString res, ErrorCodes err);

private:
    void initHttpHandlers();
    void showTip(QString str, bool b_ok);
    
    Ui::Reset *ui;
    QMap<ReqId, std::function<void(const QJsonObject&)>> m_handlers;

signals:
    void sigSwitchLogin();
};

#endif // RESET_H

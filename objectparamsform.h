#ifndef OBJECTPARAMSFORM_H
#define OBJECTPARAMSFORM_H

#include <QWidget>
#include <gp_Pnt.hxx>
namespace Ui {
class ObjectParamsForm;
}
class ObjectParamsForm : public QWidget
{
    Q_OBJECT
public:
    explicit ObjectParamsForm(QWidget *parent = nullptr, QString t="");
    ~ObjectParamsForm();
signals:
    void boxReady(gp_Pnt p, double dx, double dy, double dz, bool newObj);
    void coneReady(gp_Pnt p, double r1, double r2, double h, bool newObj);
    void sphereReady(gp_Pnt p, double r, bool newObj);
    void cylinderReady(gp_Pnt p, double r,double h, double angle, bool newObj);
    void torusReady(gp_Pnt p, double r1,double r2, double angle, bool newObj);
private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    void hideWidgets();
    Ui::ObjectParamsForm *ui;
    QString _type;
};

#endif // OBJECTPARAMSFORM_H

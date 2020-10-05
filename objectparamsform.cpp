#include "objectparamsform.h"
#include "ui_objectparamsform.h"
#include <gp_Pnt.hxx>
ObjectParamsForm::ObjectParamsForm(QWidget *parent, QString t) :
    QWidget(parent),
    ui(new Ui::ObjectParamsForm), _type(t)
{
   /* switch (_type) {
    case BOX:
        // выбор нужных layout-ов
        break;
    case CONE:
        break;
    case SPHERE:
        break;
    case CYLINDER:
        break;
    case TORUS:
        break;
    } */
    ui->setupUi(this);
}

ObjectParamsForm::~ObjectParamsForm()
{
    delete ui;
}

void ObjectParamsForm::on_okButton_clicked()
{
    double xs=ui->xsEdit->text().toInt(),
            ys=ui->ysEdit->text().toInt(),
            zs=ui->zsEdit->text().toInt(),
            xf=ui->xfEdit->text().toInt(),
            yf=ui->yfEdit->text().toInt(),
            zf=ui->zfEdit->text().toInt();
    double px= xs<xf?xs:xf,
            py=ys<yf?ys:yf,
            pz=zs<zf?zs:zf;
    double dx=abs(xf-xs),
            dy=abs(yf-ys),
            dz=abs(zf-zs);
    gp_Pnt P(px,py,pz);
    if (_type=="BOX") emit boxReady(P, dx, dy, dz);
    /*    break;
    case CONE:
        break;
    case SPHERE:
        break;
    case CYLINDER:
        break;
    case TORUS:
        break;
    }*/
    close();
}

void ObjectParamsForm::on_cancelButton_clicked()
{
    close();
}

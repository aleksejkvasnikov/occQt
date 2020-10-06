#include "objectparamsform.h"
#include "ui_objectparamsform.h"
#include <gp_Pnt.hxx>
ObjectParamsForm::ObjectParamsForm(QWidget *parent, QString t) :
    QWidget(parent),
    ui(new Ui::ObjectParamsForm), _type(t)
{
    ui->setupUi(this);
    hideWidgets();
    if (_type=="BOX") {
        ui->BoxWidget->show();
    } else if(_type=="CONE"){
        ui->ConeWidget->show();
    } else if(_type=="SPHERE"){

    } else if(_type=="CYLINDER"){

    } else if(_type=="TORUS"){

    }
}

ObjectParamsForm::~ObjectParamsForm()
{
    delete ui;
}

void ObjectParamsForm::on_okButton_clicked()
{
    if (_type=="BOX") {
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
        emit boxReady(P, dx, dy, dz, true);
    }
    else if (_type=="CONE") {
        double px = ui->xConEdit->text().toInt(),
                py=ui->yConEdit->text().toInt(),
                pz= ui->zConEdit->text().toInt();
        gp_Pnt P(px,py,pz);
        double r1 = ui->R1ConEdit->text().toInt(),
               r2 = ui->R2ConEdit->text().toInt(),
               h = ui->HConEdit->text().toInt();
        emit coneReady(P, r1, r2, h, true);
    }
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

void ObjectParamsForm::hideWidgets()
{
     ui->BoxWidget->hide();
     ui->ConeWidget->hide();
}

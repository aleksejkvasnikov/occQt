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
    } else {
        ui->PointWidget->show();
        if(_type=="CONE"){
            ui->ConeWidget->show();
        } else if(_type=="SPHERE"){
            ui->SphereWidget->show();
        } else if(_type=="CYLINDER"){
            ui->CylinderWidget->show();
        } else if(_type=="TORUS"){
            ui->TorusWidget->show();
        }
    }
    adjustSize();
}

ObjectParamsForm::~ObjectParamsForm()
{
    delete ui;
}

void ObjectParamsForm::on_okButton_clicked()
{
    if (_type=="BOX") {
        double xs=ui->xsEdit->text().toDouble(),
            ys=ui->ysEdit->text().toDouble(),
            zs=ui->zsEdit->text().toDouble(),
            xf=ui->xfEdit->text().toDouble(),
            yf=ui->yfEdit->text().toDouble(),
            zf=ui->zfEdit->text().toDouble();
        double px= xs<xf?xs:xf,
            py=ys<yf?ys:yf,
            pz=zs<zf?zs:zf;
        double dx=abs(xf-xs),
            dy=abs(yf-ys),
            dz=abs(zf-zs);
        gp_Pnt P(px,py,pz);
        emit boxReady(P, dx, dy, dz);
    } else {
        double px = ui->xEdit->text().toDouble(),
            py=ui->yEdit->text().toDouble(),
            pz= ui->zEdit->text().toDouble();
        gp_Pnt P(px,py,pz);
        if (_type=="CONE") {
            double r1 = ui->R1ConEdit->text().toDouble(),
            r2 = ui->R2ConEdit->text().toDouble(),
            h = ui->HConEdit->text().toDouble();
            emit coneReady(P, r1, r2, h);
        } else if(_type=="SPHERE"){
            double r = ui->RSphEdit->text().toDouble();
            emit sphereReady(P, r);
        } else if(_type=="TORUS"){
            double r1 = ui->R1TorEdit->text().toDouble();
            double r2 = ui->R2TorEdit->text().toDouble();
            double angle = ui->AnTorEdit->text().toDouble();
            emit torusReady(P, r1, r2, angle);
        } else if(_type=="CYLINDER"){
            double r = ui->RCylEdit->text().toDouble();
            double h = ui->HCylEdit->text().toDouble();
            double angle = ui->AnCylEdit->text().toDouble();
            emit cylinderReady(P, r, h, angle);
        }
    }
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
     ui->SphereWidget->hide();
     ui->PointWidget->hide();
     ui->TorusWidget->hide();
     ui->CylinderWidget->hide();
}

#include "mymodel.h"

MyModel::MyModel(QObject *parent) :QAbstractListModel(parent){}

MyModel::~MyModel()
{

}

int MyModel::rowCount(const QModelIndex &parent) const
{

}

QVariant MyModel::data(const QModelIndex &index, int role) const
{

}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{

}

#include "mymodel.h"

MyModel::MyModel(QObject *parent) :QAbstractListModel(parent){}

MyModel::~MyModel()
{
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return _items.size();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    auto row = _items[index.row()];
    switch (role) {
        case NameRole:
                return row->getName();
        case ColorRole:
                return row->getColorCode();
    }

    return QVariant();
}

QHash<int, QByteArray> MyModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ColorRole] = "colorCode";
    return roles;
}

#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractListModel>
#include "../dataobject.h"

class MyModel: public QAbstractListModel
{
    Q_OBJECT
public:
    enum{
            NameRole = Qt::UserRole + 1000,
            ColorRole = Qt::UserRole + 1001
        };
    MyModel(QObject *parent=nullptr);
    ~MyModel();
    void addITem( DataObject* item )
    {
        int n_items = _items.size();
        beginInsertRows(QModelIndex(), n_items, n_items);
        _items.append( item );
        endInsertRows();
    }
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<DataObject*> _items;
};

#endif // MYMODEL_H

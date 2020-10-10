#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractListModel>

class MyModel: public QAbstractListModel
{
    Q_OBJECT
public:
    enum{
            PositionRole = Qt::UserRole + 1000
        };
    MyModel(QObject *parent=nullptr);
    ~MyModel();
    void addITem( QObject* item )
    {
        int n_items = _items.size();
        _items.append( item );
        //emit dataChanged( n_items, n_items+1 );
    }
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QList<QObject*> _items;
};

#endif // MYMODEL_H

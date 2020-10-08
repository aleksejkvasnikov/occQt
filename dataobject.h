#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QObject>

class DataObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString colorCode READ getColorCode WRITE setcolorCode NOTIFY colorCodeChanged)

    QString m_name;

    QString m_colorCode;

public:
    DataObject(QString name0, QString colorCode0) : m_name(name0), m_colorCode(colorCode0)
    {

    }
    QString getName() const
    {
        return m_name;
    }
    QString getColorCode() const
    {
        return m_colorCode;
    }

public slots:
    void setName(QString name)
    {
        if (m_name == name)
            return;

        m_name = name;
        emit nameChanged(m_name);
    }
    void setcolorCode(QString colorCode)
    {
        if (m_colorCode == colorCode)
            return;

        m_colorCode = colorCode;
        emit colorCodeChanged(m_colorCode);
    }

signals:
    void nameChanged(QString name);
    void colorCodeChanged(QString colorCode);
};

#endif // DATAOBJECT_H

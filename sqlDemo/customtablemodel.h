#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QAbstractTableModel>

#include <QtCore/QAbstractTableModel>
#include <QtCore/QHash>
#include <QtCore/QRect>
#include<QSqlDatabase>

class customTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit customTableModel(QObject *parent = nullptr);
    virtual ~customTableModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void addMapping(QString color, QRect area);
    void clearMapping() { m_mapping.clear(); }

private:
    QList<QVector<qreal> * > m_data;
    QHash<QString, QRect> m_mapping;
    int m_columnCount;
    int m_rowCount;
};

#endif // CUSTOMTABLEMODEL_H

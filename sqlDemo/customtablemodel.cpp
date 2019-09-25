#include "customTableModel.h"
#include <QtCore/QVector>
#include <QtCore/QTime>
#include <QtCore/QRect>
#include <QtCore/QRandomGenerator>
#include <QtGui/QColor>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QSqlTableModel>
#include<QSqlRecord>
#include<QSqlDatabase>
#include<QSqlQuery>


customTableModel::customTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    //连接数据库
//    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
//    //设置数据库
//    db.setHostName("127.0.0.1");
//    db.setPort(3306);
//    db.setDatabaseName("book");
//    db.setUserName("root");
//    db.setPassword("123456");

//    //打开时数据库
//    if(!db.open() )
//    {
//        qDebug()<<"连接失败";

//        return;
//    }
//    else
//    {
//        qDebug()<<"连接成功";
//    }

    QSqlQuery query;


    //////
    m_columnCount = 2;
    m_rowCount = 12;
    QString a[]={"2018","2019"};
    // m_data
    for (int i = 0; i < m_rowCount; i++)
    {
        //类型为qreal的一维向量
        QVector<qreal>* dataVec = new QVector<qreal>(m_columnCount);
        for (int k = 0; k < dataVec->size(); k++)
        {
//            if (k % 2 == 0)
//                dataVec->replace(k, i * 50 + QRandomGenerator::global()->bounded(20));
//            else
//                dataVec->replace(k, QRandomGenerator::global()->bounded(100));

            //用YEAR、Month这两个数据库中内置函数，分别统计每月的书籍销售量
            QString sql=QString("select SUM(count) from sale where YEAR(saledate)='%1' and"
                        " MONTH(saledate)='%2' ").arg(a[k],QString::number(i+1));
//            qDebug()<<sql<<"\n";
            query.exec(sql);
            while(query.next())
            {
               int count=query.value(0).toInt();
//                qDebug()<<count;
               //销售量插入到dataVec
                dataVec->replace(k,count);
            }

         }
        //向m_data追加dataVec
        m_data.append(dataVec);
//        QVector<qreal>::iterator iter;

//        for(iter=dataVec->begin();iter!=dataVec->end();iter++)
//        {
//            qDebug()<<*iter<<" ";
//        }
//        qDebug()<<"\n";

    }
}

customTableModel::~customTableModel()
{
    qDeleteAll(m_data);
}

int customTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.count();
}

int customTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_columnCount;
}

QVariant customTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("201%1").arg(section+8);
    else
        return QString("%1").arg(section + 1);
}

QVariant customTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return m_data[index.row()]->at(index.column());
    } else if (role == Qt::EditRole) {
        return m_data[index.row()]->at(index.column());
    } else if (role == Qt::BackgroundRole) {
        for (const QRect &rect : m_mapping) {
            if (rect.contains(index.column(), index.row()))
                return QColor(m_mapping.key(rect));
        }

        // cell not mapped return white color
        return QColor(Qt::white);
    }
    return QVariant();
}

bool customTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        m_data[index.row()]->replace(index.column(), value.toDouble());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags customTableModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void customTableModel::addMapping(QString color, QRect area)
{
    m_mapping.insertMulti(color, area);
}


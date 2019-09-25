#include "tablewidget.h"
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTableView>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QVXYModelMapper>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QVBarModelMapper>
#include <QtWidgets/QHeaderView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include<QDebug>

QT_CHARTS_USE_NAMESPACE

TableWidget::TableWidget(QWidget *parent)
    : QWidget(parent)
{

    //链接数据库
    qDebug()<<"窗口已生成";
    // create simple model for storing data
    // user's table data model
    //! [1]
    m_model = new customTableModel;
    //! [1]

    //! [2]
    // create table view and add model to it
    QTableView *tableView = new QTableView;
    tableView->setModel(m_model);
    tableView->setMinimumWidth(300);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_model->setParent(tableView);
    //! [2]

    //! [3]
    QChart *chart = new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);
    //! [3]

    // series 1
    //! [4]
    QBarSeries *series = new QBarSeries;

    int first = 0;
    int count = 12;
    QVBarModelMapper *mapper = new QVBarModelMapper(this);
    mapper->setFirstBarSetColumn(0);
    mapper->setLastBarSetColumn(1);
    mapper->setFirstRow(first);
    mapper->setRowCount(count);
    mapper->setSeries(series);
    mapper->setModel(m_model);
    chart->addSeries(series);
    //! [4]

    //! [5]
    // for storing color hex from the series
    QString seriesColorHex = "#000000";

    // get the color of the series and use it for showing the mapped area
    QList<QBarSet *> barsets = series->barSets();
    for (int i = 0; i < barsets.count(); i++) {
        seriesColorHex = "#" + QString::number(barsets.at(i)->brush().color().rgb(), 16).right(6).toUpper();
        m_model->addMapping(seriesColorHex, QRect(1 + i, first, 1, barsets.at(i)->count()));
    }
    //! [5]

    //! [6]
    QStringList categories;
    categories << "1月" << "2月" << "3月" << "4月" <<"5月"<<"6月"<<"7月"
               <<"8月"<<"9月"<<"10月"<<"11月"<<"12月";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    //! [6]

    //! [7]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(800, 600);
    //! [7]

    //! [8]
    // create main layout
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(tableView, 1, 0);
    mainLayout->addWidget(chartView, 1, 1);
    mainLayout->setColumnStretch(1, 1);
    mainLayout->setColumnStretch(0, 0);
    setLayout(mainLayout);
    //! [8]
}

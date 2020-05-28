#include "mainwindow.h"
#include <QLabel>
#include <QFrame>
#include <QStatusBar>
#include <QGridLayout>
#include <QLineEdit>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QFrame *frame = new QFrame(this);
    setCentralWidget(frame);

    QLabel* label1 = new QLabel("Input new variant:", frame);
    label1->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel* label2 = new QLabel("Variants:", frame);
    label2->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    input = new QLineEdit(frame);

    QGridLayout *grid = new QGridLayout(frame);

    addBtn = new QPushButton("Add", frame);

    variants = new QComboBox();

    grid->addWidget(label1, 0, 0, 1, 1);
    grid->addWidget(input, 0, 1, 1, 1);
    grid->addWidget(addBtn, 1, 1, 1, 2);
    grid->addWidget(label2, 2, 0, 1, 1);
    grid->addWidget(variants, 2, 1, 1, 1);

    statusBar();

    connect(addBtn, &QPushButton::clicked, this, &MainWindow::addVariant);
    connect(variants, static_cast<void(QComboBox::*)(const QString &)>
            (&QComboBox::activated), this, &MainWindow::changeStatus);
}

void MainWindow::addVariant() {
    variants->addItem(input->text());
    input->clear();
}

void MainWindow::changeStatus(const QString& str)
{
    statusBar()->showMessage(str);
}

MyDialog::MyDialog(QWidget* parent) : QDialog(parent)
{
    okbtn = new QPushButton("OK", this);
    cancelbtn = new QPushButton("Cancel", this);

    QLabel* label = new QLabel("Do you want to close app?", this);

    QGridLayout* grid = new QGridLayout();
    grid->addWidget(label, 0, 0, 1, 2);
    grid->addWidget(okbtn, 1, 0, 1, 1);
    grid->addWidget(cancelbtn, 1, 1, 1, 1);

    setWindowTitle("End");

    setLayout(grid);

    connect(okbtn, &QPushButton::clicked, this,
            &MyDialog::onOKButtonClicked);
    connect(cancelbtn, &QPushButton::clicked, this,
            &MyDialog::onCancelButtonClicked);
}

void MyDialog::onOKButtonClicked()
{
    accept();
}

void MyDialog::onCancelButtonClicked()
{
    reject();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    MyDialog* d = new MyDialog();
    int flag = d->exec();

    if(flag == QDialog::Accepted)
    {
        event->accept();
    }
    if(flag == QDialog::Rejected)
    {
        event->ignore();
    }
}

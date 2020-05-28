#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private slots:
    void addVariant();
    void changeStatus(const QString&);

protected:
    void closeEvent(QCloseEvent*);

private:
    QPushButton* addBtn;
    QComboBox* variants;
    QLineEdit* input;
};

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    MyDialog(QWidget* parent = 0);

private slots:
    void onOKButtonClicked();
    void onCancelButtonClicked();

private:
    QPushButton* okbtn;
    QPushButton* cancelbtn;
};

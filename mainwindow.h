#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPdfWriter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void generatePdf(QPdfWriter &pdfWriter, QPainter &painter,QFont getFont,
                     const QString &text,int currentY,int noHeight);

private:
    Ui::MainWindow *ui;
    int lineHeight = 100;
    int currentY;
    int pageNo;
};
#endif // MAINWINDOW_H

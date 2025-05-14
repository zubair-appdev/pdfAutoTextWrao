#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPdfWriter>
#include <QPainter>
#include <QFont>
#include <cmath>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pageNo = 1;

    QPdfWriter pdfWriter("demo1.pdf");
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);

    QFont normalFont;
    normalFont.setFamily("Courier New");
    normalFont.setPointSize(32);

    QFont boldFont;
    boldFont.setFamily("Courier New");
    boldFont.setPointSize(12);
    boldFont.setBold(true);


    painter.drawText(100,200,"HEADING");
    generatePdf(pdfWriter,painter,boldFont,"Start the pdf",600,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------second line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Third line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Fourth line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Fourth line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Fourth line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Fourth line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Fourth line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Fourth line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Fourth line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Fourth line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Fourth line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Fourth line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Fourth line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont," ",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Nine line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont," ",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------10th line end",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------End line end",currentY,0);
    generatePdf(pdfWriter,painter,boldFont,"-----------End the pdf : ",currentY,1);
    generatePdf(pdfWriter,painter,normalFont,"                                 Can you write normal text in same line",currentY,0);
    generatePdf(pdfWriter,painter,normalFont,"-----------Samapth",currentY,0);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generatePdf(QPdfWriter &pdfWriter,QPainter &painter,QFont getFont,
                             const QString &text,int currentY,int noHeight)
{

    painter.setFont(getFont);
    if(currentY >= 3200)
    {
        painter.drawText(2000,currentY,"pg : "+QString::number(pageNo));
        pageNo++;
        pdfWriter.newPage();
        currentY = 200;
        this->currentY = currentY;
    }

    int k = 0;
    int p = 80;

    for(int i=1;i<=ceil(text.length()/80.0);i++)
    {
        int x = 100;
        for(int j=k;j<=p*i;j++)
        {
            if(currentY >= 3200)
            {
                painter.drawText(2000,currentY,"pg : "+QString::number(pageNo));
                pageNo++;
                pdfWriter.newPage();
                currentY = 200;
                this->currentY = currentY;
            }

            if(j==text.length())
            {
                break;
            }
            painter.drawText(x+=27,currentY,text[j]);
        }
        if(noHeight == 1)
        {
            //do nothing
        }
        else
        {
        currentY += lineHeight;
        }
        this->currentY = currentY;
        k+=80;
    }

    qDebug()<<currentY;




}


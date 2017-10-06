#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cv::Mat inputImage = cv::imread("lena.png");
    if(!inputImage.empty())
        cv::imshow("Display Image", inputImage);
    else
        qDebug()<<"Image not found";
}

MainWindow::~MainWindow()
{
    delete ui;
}

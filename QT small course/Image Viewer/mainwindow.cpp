#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QEvent>
#include <QMimeData>


class QDragEnterEvent;
class QDropEvent;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpenFile, SIGNAL(triggered()), this, SLOT(openFile()));
    setAcceptDrops(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::resizeEvent()
//{
//    this->size().height();
//    this->size().width();
//}

void MainWindow::openFile() {
    QPixmap pixmap;
    QString f = QFileDialog::getOpenFileName(this, "Open Image");
    if (f != "") {
        if (!pixmap.load(f))
            QMessageBox::critical(this, "Error", "Impossible to open image from this file");
        else {
            pixmap.scaled(ui->label->size().width(), ui->label->size().height(), Qt::KeepAspectRatio, Qt::FastTransformation);
            ui->label->setPixmap(pixmap);
            setWindowTitle("Image Viewing -- " + f);
        }
    }
  }

//void QLabel(QLabel* label){
//    label->resize(label->sizeHint());
//}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasUrls()) event->accept();
}

void MainWindow::dropEvent(QDropEvent *event) {
    if (event->mimeData()->hasUrls()) {
        QPixmap pixmap;
        QString f = event->mimeData()->urls().at(0).toLocalFile();
        if (!pixmap.load(f)) {
            QMessageBox::critical(this, "Error", "Impossible to open image from this file");
        }
        else {
            pixmap.scaled(ui->label->size().width(), ui->label->size().height(), Qt::KeepAspectRatio, Qt::FastTransformation);
            ui->label->setPixmap(pixmap);
            setWindowTitle("Image Viewing -- " + f);
        }
}
event->accept();
}



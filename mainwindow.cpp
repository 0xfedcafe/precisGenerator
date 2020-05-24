#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_settings.h"
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QDebug>
#include <QFileDialog>
#define TEXTBOX_MAX_HEIGHT 120

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::DrawSettings();
    this->parameters->newSettings = new QWidget(this->currentScreen);
    connect(this->activeButton,SIGNAL(clicked()), this, SLOT(handleButton()));
    this->currentScreen->setMinimumSize(QSize{496,200});
    setCentralWidget(this->currentScreen);
}

void MainWindow::DrawSettings() {
    auto currentParameters = this->parameters;
    auto currentSettings = currentParameters->newSettings;
    auto currentLayout = currentParameters->settingsLayout;


    if(this->height()/2 > 120) {
        currentSettings->setMaximumHeight(1.25*TEXTBOX_MAX_HEIGHT);
        currentSettings->setMaximumWidth(this->size().rwidth()/3);
    }
    else {
         currentSettings->setMaximumSize(this->size()/2);
    }

    currentParameters->changeDistortion->setMinimumSize(QSize{60,40});
    currentParameters->changeWidth->setMinimumSize(QSize{60,40});
    currentParameters->changeHeight->setMinimumSize(QSize{60,40});

    currentLayout->addWidget(currentParameters->changeDistortion);
    currentLayout->addWidget(currentParameters->changeHeight);
    currentLayout->addWidget(currentParameters->changeWidth);
    currentLayout->addWidget(this->activeButton);

    currentSettings->setLayout(currentLayout);
    currentSettings->move(this->size().width()-currentParameters->changeDistortion->width(),
                          this->size().height()/2-2*currentParameters->changeDistortion->height());
    currentSettings->show();

}

void MainWindow::handleButton() {

    QFileDialog* getFiles = new QFileDialog();
    getFiles->setFileMode(QFileDialog::ExistingFiles);
    connect(getFiles, &QFileDialog::filesSelected, this, &MainWindow::handleFiles);
    getFiles->show();

}

void MainWindow::handleFiles(const QStringList &selected) {

    auto params = this->parameters;
    GenerateImage process(params->changeDistortion->text().toDouble(),
                          params->changeWidth->text().toDouble(),
                          params->changeHeight->text().toDouble());
    for(const auto& photo : selected) {
        qDebug() << photo << '\n';
    }
    process.inputImage(selected);
    process.generateImage();
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    DrawSettings();
    qDebug() << this->size() << '\n';
}

MainWindow::~MainWindow()
{
    delete ui;
}

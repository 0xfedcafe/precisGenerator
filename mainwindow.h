#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "smallMenu.h"
#include <generateimage.h>

namespace Ui {
    class MainWindow;
}

namespace tl {
    template <typename T> int sgn(const T& val) {
        return (T(0) < val) - (val < T(0));
    }

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    SmallMenu* parameters = new SmallMenu(this);
    QWidget* currentScreen = new QWidget(this);
    void DrawSettings();
    void resizeEvent(QResizeEvent* event);
    void startProcess();
    QPushButton* activeButton = new QPushButton("Start");

private:

    Ui::MainWindow* ui;

private slots:
    void handleButton();
    void handleFiles(const QStringList &selected);

};


#endif // MAINWINDOW_H

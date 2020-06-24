#ifndef SMALLMENU_H
#define SMALLMENU_H

#include <QTextEdit>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QLabel>
class SmallMenu {
    public:
        SmallMenu(QWidget* parent = nullptr);
        QWidget* newSettings;
        QLabel* label;
        QVBoxLayout* settingsLayout = new QVBoxLayout;
        QLineEdit* changeDistortion = new QLineEdit("3");
        QLineEdit* changeHeight = new QLineEdit("10");
        QLineEdit* changeWidth = new QLineEdit("10");
};

#endif // SMALLMENU_H

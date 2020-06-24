#include <smallMenu.h>

SmallMenu::SmallMenu(QWidget* parent) {
            this->newSettings = new QWidget(parent);
            changeDistortion->setValidator(new QDoubleValidator(0, 100, 10));
            changeHeight->setValidator(new QDoubleValidator(0, 100, 10));
            changeWidth->setValidator(new QDoubleValidator(0, 100, 10));
}

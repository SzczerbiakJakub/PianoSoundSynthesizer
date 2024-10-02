#include "visualiseritemgui.h"



VisualiserItem::VisualiserItem(QWidget* parent, int height) : QLabel(parent) {

    setStyleSheet("background-color: white; border-radius: 5px");
    setFixedSize(10, height);
    move(1180, 150 - int(height / 2));
    setVisible(true);
}
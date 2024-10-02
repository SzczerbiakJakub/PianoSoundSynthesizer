#include "visualisergui.h"



Visualiser::Visualiser(QWidget* parent) : QLabel(parent) {

    viewModel = new VisualiserViewModel();

    QObject::connect(viewModel, &VisualiserViewModel::newItemHeightSignal, this, &Visualiser::handleNewItem);

    setStyleSheet("background-color: blue;");
    setFixedSize(1200, 300);
}


Visualiser::~Visualiser() {
    delete viewModel;
}


void Visualiser::addNextSoundVisualization(Sound* sound) {
    int itemHeight = viewModel->getNextSoundVisualizationHeight(sound);
    VisualiserItem* newItem = new VisualiserItem(this, itemHeight);
    viewModel->getVisualiserItemsPtr()->push_back(newItem);
}


void Visualiser::plotNextSoundVisualization(int height) {
    VisualiserItem* newItem = new VisualiserItem(this, height);
    viewModel->getVisualiserItemsPtr()->push_back(newItem);

}
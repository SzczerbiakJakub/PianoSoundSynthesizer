#include "visualiserviewmodel.h"



VisualiserViewModel::VisualiserViewModel() {
    items = new std::vector<VisualiserItem*>;
    newItemTimer = new QTimer(this);
    connect(newItemTimer, &QTimer::timeout, this, &VisualiserViewModel::sendNewItemHeightSignal);
    newItemTimer->start(32);
    currentSound = nullptr;
}


VisualiserViewModel::~VisualiserViewModel() {
    for (VisualiserItem* item : *items)
        delete item;
    delete items;
}


int VisualiserViewModel::getNextSoundVisualizationHeight(Sound* sound) {

    if (!items->empty())
    {
        if (items->size() > 80)
            items->erase(items->begin());
        for (VisualiserItem* item : *items)
        {
            item->move(item->x() - 15, item->y());
        }
    }

    int itemHeight;
    if (sound != nullptr)
        itemHeight = (int)(250 * sound->frequency / 1047);
    else
        itemHeight = 8;
    return itemHeight;
}
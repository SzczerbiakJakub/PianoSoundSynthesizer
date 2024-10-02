#pragma once
#include <QLabel>
#include <QWidget>

/// <summary>
/// Widget odpowiadający poszczególnej pionowej linii znajdującej się na wizualiserze.
/// </summary>
class VisualiserItem : public QLabel
{
public:
    /// <summary>
    /// Konstruktor obiektu klasy VisualiserItem.
    /// </summary>
    /// <param name="parent"> Wskaźnik do nadrzędnego widgetu, do którego będzie przypisany będzie obiekt.</param>
    /// <param name="height"> Wysokość obiektu w pikselach. </param>
    VisualiserItem(QWidget* parent, int height);

    /// <summary>
    /// Destruktor obiektu klasy VisualiserItem.
    /// </summary>
    ~VisualiserItem() {};
};
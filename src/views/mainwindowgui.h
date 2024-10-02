#pragma once

#include <QtWidgets/QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QPushButton>
#include <QElapsedTimer>
#include <pianogui.h>
#include <visualisergui.h>
#include <mainwindowviewmodel.h>

//#include <sound.h>




/// <summary>
/// Okno programu.
/// </summary>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// <summary>
    /// Kontruktor obiektu klasy MainWindow.
    /// </summary>
    /// <param name="parent"> Wskaźnik do nadrzędnego widgetu, do którego będzie przypisany utworzony widget.</param>
    MainWindow(QWidget* parent = nullptr);

    /// <summary>
    /// Destruktor obiektu klasy MainWindow.
    /// </summary>
    ~MainWindow();

private:
    MainWindowViewModel* viewModel;

    void buildMainWindow();

    /// <summary>
    /// Metoda wywoływana w czasie naciśnięcia przycisku na klawiaturze komputera w trakcie działania programu. 
    /// Umożliwia interakcję z programem.
    /// </summary>
    /// <param name="event"> Wskaźnik do zarejestrowanego eventu wciśnięcia przycisku z klawiatury. </param>
    void keyPressEvent(QKeyEvent* event) override;


    /// <summary>
    /// Metoda wywoływana w czasie puszczenia przycisku na klawiaturze komputera w trakcie działania programu. 
    /// Umożliwia interakcję z programem.
    /// </summary>
    /// <param name="event"> Wskaźnik do zarejestrowanego eventu puszczenia przycisku z klawiatury. </param>
    void keyReleaseEvent(QKeyEvent* event) override;



private slots:

    /// <summary>
    /// metoda wywoływana podczas odkliknięcia przycisku nagrywania utworu.
    /// </summary>
    void onRecordButtonReleased();

    /// <summary>
    /// metoda wywoływana podczas odkliknięcia przycisku odtwarzania utworu.
    /// </summary>
    void onPlayButtonReleased();
};
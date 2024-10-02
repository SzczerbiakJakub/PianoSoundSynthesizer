#include "mainwindowgui.h"



MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    viewModel = new MainWindowViewModel(nullptr);
    buildMainWindow();
}


MainWindow::~MainWindow() {
    delete viewModel;
}


void MainWindow::buildMainWindow() {

    setGeometry(0, 0, 1500, 750);

    QWidget* centralWidget = new QWidget(this);
    QHBoxLayout* layout = new QHBoxLayout(centralWidget);
    centralWidget->setFixedSize(1500, 750);
    setCentralWidget(centralWidget);

    QLabel* leftSideLabel = new QLabel(centralWidget);
    QVBoxLayout* leftSideLabelLayout = new QVBoxLayout(leftSideLabel);
    leftSideLabel->setFixedSize(1200, 750);

    Visualiser* visualiser = new Visualiser(leftSideLabel);
    viewModel->setVisualizer(visualiser);

    Piano* piano = new Piano(leftSideLabel);
    viewModel->setPiano(piano);

    leftSideLabelLayout->addWidget(visualiser);
    leftSideLabelLayout->addWidget(piano);

    layout->addWidget(leftSideLabel);

    QLabel* rightSideLabel = new QLabel(centralWidget);
    QVBoxLayout* rightSideLabelLayout = new QVBoxLayout(rightSideLabel);
    rightSideLabel->setFixedSize(280, 750);

    QPushButton* recordButton = new QPushButton("RECORD REPLAY", rightSideLabel);
    recordButton->setFixedSize(280, 370);
    recordButton->setFont(QFont("Arial", 20, QFont::Bold));
    connect(recordButton, &QPushButton::released, this, &MainWindow::onRecordButtonReleased);

    viewModel->setRecordButton(recordButton);

    QPushButton* playButton = new QPushButton("DISPLAY REPLAY", rightSideLabel);
    playButton->setFixedSize(280, 370);
    playButton->setFont(QFont("Arial", 20, QFont::Bold));
    connect(playButton, &QPushButton::released, this, &MainWindow::onPlayButtonReleased);

    viewModel->setPlayButton(playButton);

    rightSideLabelLayout->addWidget(recordButton);
    rightSideLabelLayout->addWidget(playButton);

    layout->addWidget(rightSideLabel);
}


void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->isAutoRepeat())
        return;
    viewModel->pressKey(event->key());
}


void MainWindow::keyReleaseEvent(QKeyEvent* event) {
    if (event->isAutoRepeat())
        return;
    viewModel->releaseKey(event->key());
}


void MainWindow::onRecordButtonReleased() {
    viewModel->toggleRecordingAudio();
}


void MainWindow::onPlayButtonReleased() {
    viewModel->displayAudioReplay();
}
#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QListWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
private:
    QListWidget *sidebar;
    QStackedWidget *stack;
    void setupUi();
};

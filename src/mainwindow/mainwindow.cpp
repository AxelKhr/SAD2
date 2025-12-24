#include "MainWindow.h"
#include <QHBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi();
    resize(800, 600);
}

void MainWindow::setupUi() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // 1. Sidebar
    sidebar = new QListWidget();
    sidebar->setFixedWidth(150);
    sidebar->setIconSize(QSize(40, 40));
    sidebar->setStyleSheet(
        "QListWidget { background-color: #4A769B; border: none; }"
        "QListWidget::item { color: white; padding: 15px; border: none; }"
        "QListWidget::item:selected { background-color: #3A5F7E; border-left: 5px solid #FFFFFF; }"
        );

    // Элементы меню (Иконки заменить на реальные пути)
    new QListWidgetItem(QIcon(":/icons/start.svg"), "Старт", sidebar);
    new QListWidgetItem(QIcon(":/icons/configurator.svg"), "Конфигуратор", sidebar);
    new QListWidgetItem("Test", sidebar); // Текстовый элемент

    // Нижний элемент (Настройки) - можно реализовать через Spacer или отдельный виджет
    sidebar->addItem(new QListWidgetItem(QIcon(":/icons/settings.svg"), "Настройки"));

    // 2. Stacked Content
    stack = new QStackedWidget();
    stack->setStyleSheet("background-color: #6D9AC1;");

    // Начальная страница
    QLabel *startPage = new QLabel("Стартовая страница", stack);
    startPage->setAlignment(Qt::AlignCenter);
    startPage->setStyleSheet("color: white; font-size: 24px; font-weight: bold;");
    stack->addWidget(startPage);

    // Добавление в Layout
    mainLayout->addWidget(sidebar);
    mainLayout->addWidget(stack);

    // Logic
    connect(sidebar, &QListWidget::currentRowChanged, stack, &QStackedWidget::setCurrentIndex);
}

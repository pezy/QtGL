#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "itemtree.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	void treeStatusChanged(QTreeWidgetItem* pItem, int column);

private:
	Ui::MainWindowClass ui;
	ItemTree m_tree;
};

#endif // MAINWINDOW_H

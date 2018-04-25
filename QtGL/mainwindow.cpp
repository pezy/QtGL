#include "mainwindow.h"
#include "gltriangleitem.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.openGLWidget->AddItem(new GLTriangleItem());
}

MainWindow::~MainWindow()
{

}

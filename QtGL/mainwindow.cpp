#include "mainwindow.h"
#include "gltriangleitem.h"
#include "gltrianglemeshitem.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	/*QVector3D vertex1[3] = { QVector3D(0.5f, 0.5f, 0.0f), QVector3D(0.5f, -0.5f, 0.0f), QVector3D(-0.5f, 0.5f, 0.0f) };
	auto pTriangle1 = new GLTriangleItem;
	pTriangle1->SetVertex(vertex1);
	ui.openGLWidget->AddItem(pTriangle1);

	QVector3D vertex2[3] = { QVector3D(0.5f, -0.5f, 0.0f), QVector3D(-0.5f, -0.5f, 0.0f), QVector3D(-0.5f, 0.5f, 0.0f) };
	auto pTriangle2 = new GLTriangleItem;
	pTriangle2->SetVertex(vertex2);
	ui.openGLWidget->AddItem(pTriangle2);*/

	ui.openGLWidget->AddItem(new GLTriangleMeshItem);
}

MainWindow::~MainWindow()
{

}

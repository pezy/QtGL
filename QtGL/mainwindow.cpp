#include "mainwindow.h"

#include <QVector3D>
#include "gltrianglemeshitem.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.treeWidget, &QTreeWidget::itemChanged, this, &MainWindow::treeStatusChanged);

	m_tree.Init(*ui.treeWidget);
}

MainWindow::~MainWindow()
{

}

void MainWindow::treeStatusChanged(QTreeWidgetItem* pItem, int column)
{
	GLItem* pGLItem = m_tree.GetOrCreateGLItem(pItem, ui.openGLWidget);

	if (pItem->checkState(column) == Qt::Checked)
	{
		ui.openGLWidget->AddItem(pGLItem);
	}
	else
	{
		ui.openGLWidget->DelItem(pGLItem);
	}
}

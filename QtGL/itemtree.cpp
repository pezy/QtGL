#include "itemtree.h"
#include "gltriangleitem.h"
#include "gltrianglemeshitem.h"
#include <QTreeWidget>

void ItemTree::Init(const QTreeWidget& treeWidget)
{
    QTreeWidgetItem* pRootItem = treeWidget.topLevelItem(0);
	pRootItem->setExpanded(true);

    m_itemFactory.AddFunctor(pRootItem->child(0), [this]() { return createTriangleDemoItem(); });
    m_itemFactory.AddFunctor(pRootItem->child(1), []() { return new GLTriangleMeshItem; });
}

GLItem* ItemTree::GetOrCreateGLItem(QTreeWidgetItem* pTreeWidgetItem, QOpenGLWidget* pGLWidget)
{
    auto found = m_tableItems.find(pTreeWidgetItem);
	if (found != m_tableItems.end())
		return found->second;

	GLItem* pNewItem = m_itemFactory.Create(pTreeWidgetItem);
	if (pNewItem)
	{
		pNewItem->InitializeGL(pGLWidget);
		m_tableItems.emplace(pTreeWidgetItem, pNewItem);
	}

	return pNewItem;
}

GLItem* ItemTree::createTriangleDemoItem()
{
	QVector3D vertex[3] = { QVector3D(-0.5f, -0.5f, 0.0f), QVector3D(0.5f, -0.5f, 0.0f), QVector3D(0.0f,  0.5f, 0.0f) };
	auto pDemoTriangle = new GLTriangleItem;
	pDemoTriangle->SetVertex(vertex);
	return pDemoTriangle;
}

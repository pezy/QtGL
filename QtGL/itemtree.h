#ifndef ITEMTREE_H
#define ITEMTREE_H

#include <unordered_map>
#include "itemfactory.h"

class GLItem;
class QTreeWidgetItem;
class QTreeWidget;
class QOpenGLWidget;

class ItemTree
{
public:
	void Init(const QTreeWidget& treeWidget);
	GLItem* GetOrCreateGLItem(QTreeWidgetItem* pTreeWidgetItem, QOpenGLWidget* pGLWidget);

private:
	GLItem* createTriangleDemoItem();

private:
	ItemFactory m_itemFactory;
	std::unordered_map<QTreeWidgetItem*, GLItem*> m_tableItems;
};

#endif // ITEMTREE_H

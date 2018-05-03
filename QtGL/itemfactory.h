#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <unordered_map>
#include <functional>

class QTreeWidgetItem;
class GLItem;

class ItemFactory
{
public:
	void AddFunctor(QTreeWidgetItem* pItem, const std::function<GLItem*()>& functor);
	GLItem* Create(QTreeWidgetItem* pItem) const;

private:
	std::unordered_map<QTreeWidgetItem*, std::function<GLItem*()>> m_tableFunctor;
};

#endif // ITEMFACTORY_H

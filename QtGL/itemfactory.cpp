#include "itemfactory.h"

void ItemFactory::AddFunctor(QTreeWidgetItem* pItem, const std::function<GLItem*()>& functor)
{
	m_tableFunctor.emplace(pItem, functor);
}

GLItem* ItemFactory::Create(QTreeWidgetItem* pItem) const
{
	auto found = m_tableFunctor.find(pItem);
	if (found == m_tableFunctor.end())
		return nullptr;

	return found->second();
}

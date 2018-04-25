#include "glview.h"
#include "glitem.h"

GLView::GLView(QWidget *parent)
	: QOpenGLWidget(parent)
{
	QSurfaceFormat defaultFormat = QSurfaceFormat::defaultFormat();
	defaultFormat.setMajorVersion(3);
	defaultFormat.setMinorVersion(3);
	defaultFormat.setProfile(QSurfaceFormat::CoreProfile);
	QSurfaceFormat::setDefaultFormat(defaultFormat);
}

GLView::~GLView()
{

}

void GLView::AddItem(GLItem *pItem)
{
	m_items.push_back(pItem);
}

void GLView::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	for (auto pItem : m_items)
		pItem->InitializeGL();
}

void GLView::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto pItem : m_items)
		pItem->Draw();
}

void GLView::resizeGL(int w, int h)
{
}

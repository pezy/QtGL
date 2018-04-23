#include "glview.h"

GLView::GLView(QWidget *parent)
	: QOpenGLWidget(parent)
{

}

GLView::~GLView()
{

}

void GLView::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void GLView::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void GLView::resizeGL(int w, int h)
{
}

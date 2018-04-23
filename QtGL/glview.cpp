#include "glview.h"

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

void GLView::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader/triangle/vertex");
	m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/triangle/fragment");
	m_program.link();

	m_vertex[0] = QVector3D(-0.5f, -0.5f, 0.0f);
	m_vertex[1] = QVector3D(0.5f, -0.5f, 0.0f);
	m_vertex[2] = QVector3D(0.0f, 0.5f, 0.0f);
}

void GLView::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);

	m_program.bind();
	m_program.setAttributeArray("aPos", m_vertex);
	m_program.enableAttributeArray("aPos");
	glDrawArrays(GL_TRIANGLES, 0, 3);
	m_program.disableAttributeArray("aPos");
	m_program.release();
}

void GLView::resizeGL(int w, int h)
{
}

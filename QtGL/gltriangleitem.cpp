#include "gltriangleitem.h"
#include "glview.h"
#include <QOpenGLShaderProgram>

GLTriangleItem::GLTriangleItem()
	: GLItem()
{

}

GLTriangleItem::~GLTriangleItem()
{
	
}

void GLTriangleItem::InitializeGL()
{
	initializeOpenGLFunctions();

	m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader/triangle/vertex");
	m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/triangle/fragment");
	m_program.link();

	m_vertex[0] = QVector3D(-0.5f, -0.5f, 0.0f);
	m_vertex[1] = QVector3D(0.5f, -0.5f, 0.0f);
	m_vertex[2] = QVector3D(0.0f, 0.5f, 0.0f);
}

void GLTriangleItem::Draw()
{
	m_program.bind();
	m_program.setAttributeArray("aPos", m_vertex);
	m_program.enableAttributeArray("aPos");
	glDrawArrays(GL_TRIANGLES, 0, 3);
	m_program.disableAttributeArray("aPos");
	m_program.release();
}

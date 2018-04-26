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

void GLTriangleItem::SetVertex(const QVector3D(&vertex)[3])
{
	m_vertex[0] = vertex[0];
	m_vertex[1] = vertex[1];
	m_vertex[2] = vertex[2];
}

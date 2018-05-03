#include "gltrianglemeshitem.h"
#include <QOpenGLWidget>

GLTriangleMeshItem::GLTriangleMeshItem()
	: GLItem(), m_ebo(QOpenGLBuffer::IndexBuffer)
{

}

GLTriangleMeshItem::~GLTriangleMeshItem()
{
	m_vbo.destroy();
	m_ebo.destroy();
}

void GLTriangleMeshItem::InitializeGL(QOpenGLWidget* pGLWidget)
{
	pGLWidget->makeCurrent();
	initializeOpenGLFunctions();

	m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader/triangle/vertex");
	m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/triangle/fragment");
	m_program.link();

	m_vbo.create();
	m_ebo.create();

	QVector3D vertices[] = {
		QVector3D(0.5f, 0.5f, 0.0f),
		QVector3D(0.5f, -0.5f, 0.0f),
		QVector3D(-0.5f, -0.5f, 0.0f),
		QVector3D(-0.5f, 0.5f, 0.0f)
	};

	GLushort indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	m_vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	m_vbo.bind();
	m_vbo.allocate(vertices, 4 * sizeof(QVector3D));
	
	m_ebo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	m_ebo.bind();
	m_ebo.allocate(indices, 6 * sizeof(GLushort));

	pGLWidget->doneCurrent();
}

void GLTriangleMeshItem::Draw()
{
	m_program.bind();
	m_vbo.bind();
	m_ebo.bind();

	m_program.enableAttributeArray("aPos");
	m_program.setAttributeBuffer("aPos", GL_FLOAT, 0, 3, sizeof(QVector3D));
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	m_program.disableAttributeArray("aPos");

	m_ebo.release();
	m_vbo.release();
	m_program.release();
}

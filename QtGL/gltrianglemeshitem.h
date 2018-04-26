#ifndef GLTRIANGLEMESHITEM_H
#define GLTRIANGLEMESHITEM_H

#include "glitem.h"
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class GLTriangleMeshItem : public GLItem
{
public:
	GLTriangleMeshItem();
	~GLTriangleMeshItem();

	void InitializeGL() override;
	void Draw() override;

private:
	QOpenGLShaderProgram m_program;
	QOpenGLBuffer m_vbo;
	QOpenGLBuffer m_ebo;
};

#endif // GLTRIANGLEMESHITEM_H

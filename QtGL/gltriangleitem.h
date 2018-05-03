#ifndef GLTRIANGLEITEM_H
#define GLTRIANGLEITEM_H

#include "glitem.h"
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class GLTriangleItem : public GLItem
{
public:
	GLTriangleItem();
	~GLTriangleItem();

	void InitializeGL(QOpenGLWidget* pGLWidget) override;
	void Draw() override;
	void SetVertex(const QVector3D(&vertex)[3]);

private:
	QOpenGLShaderProgram m_program;
	QVector3D m_vertex[3];
};

#endif // GLTRIANGLEITEM_H

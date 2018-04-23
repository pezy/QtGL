#ifndef GLVIEW_H
#define GLVIEW_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>

class GLView : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
	Q_OBJECT

public:
	GLView(QWidget *parent = Q_NULLPTR);
	~GLView();

protected:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int w, int h) override;

private:
	
};

#endif // GLVIEW_H

#ifndef GLITEM_H
#define GLITEM_H

#include <QOpenGLFunctions_3_3_Core>

class GLItem : protected QOpenGLFunctions_3_3_Core
{
public:
	virtual void InitializeGL() = 0;
	virtual void Draw() = 0;
};

#endif // GLITEM_H

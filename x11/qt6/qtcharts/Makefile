QT6NAME =		QtCharts
COMMENT =		Qt6 components for drawing 2D charts

SHARED_LIBS +=  Qt6Charts                 0.0 # 6.3
SHARED_LIBS +=  Qt6ChartsQml              0.0 # 6.3

WANTLIB += ${COMPILER_LIBCXX} GL Qt6Core Qt6Gui Qt6Network Qt6OpenGL
WANTLIB += Qt6OpenGLWidgets Qt6Qml Qt6QmlModels Qt6Quick Qt6Widgets
WANTLIB += c m

LIB_DEPENDS =		x11/qt6/qtdeclarative>=${QT6_VERSION},<${QT6_NEXT_VERSION}

.include <bsd.port.mk>

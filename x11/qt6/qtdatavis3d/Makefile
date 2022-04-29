QT6NAME =		QtDataVis3D
COMMENT =		Qt6 3D data visualization components

SHARED_LIBS +=  Qt6DataVisualization      0.0 # 6.3
SHARED_LIBS +=  Qt6DataVisualizationQml   0.0 # 6.3

WANTLIB += ${COMPILER_LIBCXX} GL Qt6Core Qt6Gui Qt6Network Qt6OpenGL
WANTLIB += Qt6Qml Qt6QmlModels Qt6Quick c m

LIB_DEPENDS =		x11/qt6/qtdeclarative>=${QT6_VERSION},<${QT6_NEXT_VERSION}

.include <bsd.port.mk>

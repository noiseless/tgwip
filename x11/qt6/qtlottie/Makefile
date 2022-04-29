QT6NAME =		QtLottie
COMMENT =		QML API for rendering graphics and animations

SHARED_LIBS +=  Qt6Bodymovin              0.0 # 6.3

WANTLIB += ${COMPILER_LIBCXX} GL Qt6Core Qt6Gui Qt6Network Qt6OpenGL
WANTLIB += Qt6Qml Qt6QmlModels Qt6Quick c m xkbcommon

LIB_DEPENDS =		x11/qt6/qtdeclarative>=${QT6_VERSION},<${QT6_NEXT_VERSION}

.include <bsd.port.mk>

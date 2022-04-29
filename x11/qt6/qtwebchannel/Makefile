QT6NAME =		QtWebChannel
COMMENT =		Qt6 seamless HTML/JavaScript integration

SHARED_LIBS +=  Qt6WebChannel             0.0 # 6.3

WANTLIB += ${COMPILER_LIBCXX} GL Qt6Core Qt6Gui Qt6Network Qt6OpenGL
WANTLIB += Qt6Qml Qt6QmlModels Qt6Quick c m

BUILD_DEPENDS =		x11/qt6/qtwebsockets>=${QT6_VERSION:R},<${QT6_NEXT_VERSION}
RUN_DEPENDS =		x11/qt6/qtwebsockets>=${QT6_VERSION:R},<${QT6_NEXT_VERSION}

LIB_DEPENDS =		x11/qt6/qtdeclarative>=${QT6_VERSION},<${QT6_NEXT_VERSION}

.include <bsd.port.mk>

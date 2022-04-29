QT6NAME =		QtWebSockets
COMMENT =		Qt6 implementation of WebSocket protocol

SHARED_LIBS +=  Qt6WebSockets             0.0 # 6.3

WANTLIB += ${COMPILER_LIBCXX} Qt6Core Qt6Network Qt6Qml c m

LIB_DEPENDS =		x11/qt6/qtdeclarative>=${QT6_VERSION},<${QT6_NEXT_VERSION}

.include <bsd.port.mk>

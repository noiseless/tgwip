QT6NAME =		QtRemoteObjects
COMMENT =		inter-process communication using Qt6 objects

SHARED_LIBS +=  Qt6RemoteObjects          0.0 # 6.3
SHARED_LIBS +=  Qt6RemoteObjectsQml       0.0 # 6.3

WANTLIB += ${COMPILER_LIBCXX} GL Qt6Core Qt6Gui Qt6Network Qt6Qml
WANTLIB += c m

LIB_DEPENDS =		x11/qt6/qtdeclarative>=${QT6_VERSION},<${QT6_NEXT_VERSION}

.include <bsd.port.mk>

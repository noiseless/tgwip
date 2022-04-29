QT6NAME =	Qt5Compat
COMMENT =	Qt6 module contains unsupported Qt 5 APIs

SHARED_LIBS +=  Qt6Core5Compat      0.0 # 6.0

LIB_DEPENDS =	x11/qt6/qtdeclarative

WANTLIB += ${COMPILER_LIBCXX} GL Qt6Core Qt6Gui Qt6Network Qt6OpenGL
WANTLIB += Qt6Qml Qt6QmlModels Qt6Quick c icudata icui18n icuuc
WANTLIB += m xkbcommon

.include <bsd.port.mk>

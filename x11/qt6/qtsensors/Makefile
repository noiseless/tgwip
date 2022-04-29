QT6NAME =		QtSensors
COMMENT =		Qt6 hardware sensors support

SHARED_LIBS +=  Qt6Sensors                0.0 # 6.3
SHARED_LIBS +=  Qt6SensorsQuick           0.0 # 6.3

WANTLIB += ${COMPILER_LIBCXX} Qt6Core Qt6Network Qt6Qml c m

LIB_DEPENDS =		x11/qt6/qtdeclarative>=${QT6_VERSION},<${QT6_NEXT_VERSION}

.include <bsd.port.mk>

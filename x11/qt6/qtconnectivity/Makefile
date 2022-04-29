QT6NAME =		QtConnectivity
COMMENT =		Bluetooth and NFC support for Qt6

SHARED_LIBS +=  Qt6Bluetooth              0.0 # 6.3
SHARED_LIBS +=  Qt6Nfc                    0.0 # 6.3

WANTLIB += ${COMPILER_LIBCXX} Qt6Core Qt6Network c m

LIB_DEPENDS =		x11/qt6/qtdeclarative>=${QT6_VERSION},<${QT6_NEXT_VERSION}

RUN_DEPENDS =		x11/dbus

.include <bsd.port.mk>

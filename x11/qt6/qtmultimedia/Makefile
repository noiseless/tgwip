QT6NAME =		QtMultimedia
COMMENT =		Qt6 multimedia components

SHARED_LIBS +=  Qt6Multimedia             0.0 # 6.3
SHARED_LIBS +=  Qt6MultimediaQuick        0.0 # 6.3
SHARED_LIBS +=  Qt6MultimediaWidgets      0.0 # 6.3

WANTLIB += ${COMPILER_LIBCXX} EGL GL Qt6Core Qt6Gui Qt6Network
WANTLIB += Qt6OpenGL Qt6Qml Qt6QmlModels Qt6Quick Qt6Widgets c
WANTLIB += glib-2.0 gobject-2.0 gstallocators-1.0 gstapp-1.0 gstaudio-1.0
WANTLIB += gstbase-1.0 gstgl-1.0 gstpbutils-1.0 gstphotography-1.0
WANTLIB += gstreamer-1.0 gstvideo-1.0 gthread-2.0 intl m xkbcommon

LIB_DEPENDS =		multimedia/gstreamer1/core \
			multimedia/gstreamer1/plugins-base \
			multimedia/gstreamer1/plugins-bad \
			x11/qt6/qtdeclarative>=${QT6_VERSION},<${QT6_NEXT_VERSION}

.include <bsd.port.mk>

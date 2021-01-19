# $OpenBSD: Makefile,v 1.4 2020/08/20 20:50:02 noiseless Exp $

PKGNAME =	telegram-desktop-${V}
V =		2.5.5
#REVISION =	1
COMMENT =	telegram desktop messaging app
DISTNAME =	${PRJ}-${V}-full
CATEGORIES =	tgwip net

ACC =	telegramdesktop
PRJ =	tdesktop

TGOWT_COMMIT =	d91d618889cc743aafd809151449012de62e5327
VPX_COMMIT =	3a38edea2cd114d53914cab017cab2e43a600031
YUV_COMMIT =	1d3f901aa016d42b5bc0148be2ef6c0fd56f3b81

MASTER_SITES0 =	https://github.com/${ACC}/${PRJ}/releases/download/v${V}/
MASTER_SITES1 =	https://github.com/desktop-app/tg_owt/archive/
MASTER_SITES2 =	https://github.com/webmproject/libvpx/archive/
MASTER_SITES3 =	https://gitlab.com/chromiumsrc/libyuv/-/archive/${YUV_COMMIT}/

DISTFILES =	${DISTNAME}${EXTRACT_SUFX}:0 \
		${TGOWT_COMMIT}${EXTRACT_SUFX}:1 \
		${VPX_COMMIT}${EXTRACT_SUFX}:2 \
		libyuv-${YUV_COMMIT}${EXTRACT_SUFX}:3

HOMEPAGE =	https://desktop.telegram.org/
#MAINTAINER =	S

# GPLv3
PERMIT_PACKAGE =	Yes

BUILD_DEPENDS +=	tgwip/libusrsctp audio/pulseaudio tgwip/microsoft-gsl
BUILD_DEPENDS +=	tgwip/range-v3 tgwip/tl-expected devel/yasm

LIB_DEPENDS += 	audio/opus graphics/ffmpeg audio/openal textproc/hunspell
LIB_DEPENDS += 	sysutils/xxhash x11/dbusmenu-qt

WANTLIB +=	${COMPILER_LIBCXX} GL Qt5Core Qt5Gui Qt5Network Qt5Widgets
WANTLIB +=	X11 atk-1.0 c cairo cairo-gobject crypto gdk-3 gdk_pixbuf-2.0
WANTLIB +=	gio-2.0 glib-2.0 gobject-2.0 gtk-3 harfbuzz intl jpeg
WANTLIB +=	lz4 lzma m pango-1.0 pangocairo-1.0 ssl xcb xcb-screensaver
WANTLIB +=	xkbcommon z opus avcodec avformat avutil swresample swscale
WANTLIB +=	openal hunspell-1.7 xxhash Qt5DBus dbusmenu-qt5

RUN_DEPENDS +=	x11/gtk+3,-guic devel/desktop-file-utils x11/qt5/qtimageformats

MODULES =	devel/cmake x11/qt5

TDESKTOP_DIR =	${WRKDIR}/${DISTNAME}
TGOWT_DIR =	${TDESKTOP_DIR}/tg_owt

CXXFLAGS +=	-DNDEBUG

# # We're allowed to used the API ID of the Snap package
CONFIGURE_ARGS +=	-DCMAKE_BUILD_TYPE=Release \
			-DTDESKTOP_API_ID=611335 \
			-DTDESKTOP_API_HASH=d524b414d21f4d37f08684c1df41ac9c \
			-DTDESKTOP_DISABLE_REGISTER_CUSTOM_SCHEME=ON \
			-DDESKTOP_APP_SPECIAL_TARGET="" \
			-Ddisable_autoupdate=1 \
			-DDESKTOP_APP_DISABLE_DBUS_INTEGRATION=OFF \
			-DDESKTOP_APP_DISABLE_WAYLAND_INTEGRATION=ON \
			-DDESKTOP_APP_DISABLE_CRASH_REPORTS=ON \
			-DDESKTOP_APP_USE_PACKAGED=ON \
			-DDESKTOP_APP_USE_GLIBC_WRAPS=OFF \
			-DDESKTOP_APP_USE_PACKAGED_FONTS=OFF \
			-DDESKTOP_APP_WEBRTC_LOCATION=${TGOWT_DIR}/src/

VPX_TMP_PATH = 	${WRKDIR}/libvpx-${VPX_COMMIT}
YUV_TMP_PATH = 	${WRKDIR}/libyuv-${YUV_COMMIT}
VPX_PATH =	${TGOWT_DIR}/src/third_party/libvpx/source/libvpx/
YUV_PATH = 	${TGOWT_DIR}/src/third_party/libyuv
LIBEVENT_DIR = 	${TGOWT_DIR}/src/base/third_party/libevent/openbsd/

pre-patch:
	@mv ${WRKDIR}/tg_owt-${TGOWT_COMMIT} ${TGOWT_DIR}
	@rm -fr ${VPX_PATH}
	@rm -fr ${YUV_PATH}
	@mv ${VPX_TMP_PATH} ${VPX_PATH}
	@mv ${YUV_TMP_PATH} ${YUV_PATH}

pre-configure:
	@mkdir ${LIBEVENT_DIR}
	@cp ${FILESDIR}/config.h ${LIBEVENT_DIR}
	@cp ${FILESDIR}/event-config.h ${LIBEVENT_DIR}
	@mkdir -p ${TGOWT_DIR}/out/Release
	@cd ${TGOWT_DIR}/out/Release && \
		${SETENV} CC="${CC}" \
		CXX="${CXX}" \
		CFLAGS="${CFLAGS} -fPIC" \
		CXXFLAGS="${CXXFLAGS} -DOPENSSL_IS_LIBRESSL -fPIC -DNDEBUG" \
		${CONFIGURE_ENV} \
		${LOCALBASE}/bin/cmake -G Ninja \
		${CONFIGURE_ARGS} \
		${TGOWT_DIR}

	@cd ${TGOWT_DIR}/out/Release && \
		${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/ninja

	@cd ${TDESKTOP_DIR}

.include <bsd.port.mk>

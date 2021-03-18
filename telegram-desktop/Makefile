# $OpenBSD: Makefile,v 1.4 2020/08/20 20:50:02 noiseless Exp $

PKGNAME =	telegram-desktop-${V}
V =		2.6.5
REVISION =	0
COMMENT =	telegram desktop messaging app
DISTNAME =	${PRJ}-${V}-full
CATEGORIES =	tgwip local net

USRSCTP_V =	0.9.5.0
ACC =	telegramdesktop
PRJ =	tdesktop

TGOWT_COMMIT =	7f965710b93c4dadd7e6f1ac739e708694df7929
VPX_COMMIT =	cb0d8ce313a5524d54304cba0a4bce139abe2c38
YUV_COMMIT =	f37014fcfffd62f00a80a900f016964763c56864

MASTER_SITES0 =	https://github.com/${ACC}/${PRJ}/releases/download/v${V}/
MASTER_SITES1 =	https://github.com/desktop-app/tg_owt/archive/
MASTER_SITES2 =	https://github.com/webmproject/libvpx/archive/
MASTER_SITES3 =	https://gitlab.com/chromiumsrc/libyuv/-/archive/${YUV_COMMIT}/

DISTFILES =	${DISTNAME}${EXTRACT_SUFX}:0 \
		${TGOWT_COMMIT}${EXTRACT_SUFX}:1 \
		${VPX_COMMIT}${EXTRACT_SUFX}:2 \
		libyuv-${YUV_COMMIT}${EXTRACT_SUFX}:3

TDESKTOP_DIR =	${WRKDIR}/${DISTNAME}
TGOWT_DIR =	${TDESKTOP_DIR}/tg_owt
VPX_PATH =	${TGOWT_DIR}/src/third_party/libvpx/source/libvpx/
YUV_PATH = 	${TGOWT_DIR}/src/third_party/libyuv
LIBEVENT_DIR = 	${TGOWT_DIR}/src/base/third_party/libevent/openbsd/

DEPS_MAPS = ${TGOWT_COMMIT}~${TGOWT_DIR} \
	${VPX_COMMIT}~${VPX_PATH} \
	libyuv-${YUV_COMMIT}~${YUV_PATH}

.for DMAP in ${DEPS_MAPS}
EXTRACT_CASES +=	${DMAP:C/~.+$//g}${EXTRACT_SUFX}) pax -zrs \
			',^.*${DMAP:C/~.+$//g},${WRKDIR}${DMAP:C/^.+~//g},' \
			-f ${FULLDISTDIR}/$$archive;;
.endfor

HOMEPAGE =	https://desktop.telegram.org/
#MAINTAINER =	S

# GPLv3
PERMIT_PACKAGE =	Yes

BUILD_DEPENDS +=	audio/pulseaudio tgwip/microsoft-gsl
BUILD_DEPENDS +=	tgwip/range-v3 tgwip/tl-expected devel/yasm

LIB_DEPENDS += 	audio/opus graphics/ffmpeg audio/openal textproc/hunspell
LIB_DEPENDS += 	sysutils/xxhash devel/glib2mm tgwip/libusrsctp>=${USRSCTP_V}
LIB_DEPENDS += 	x11/dbusmenu-qt

WANTLIB +=	${COMPILER_LIBCXX} Qt5Core Qt5Gui Qt5Network Qt5Widgets
WANTLIB +=	X11 atk-1.0 c cairo cairo-gobject crypto gdk-3 gdk_pixbuf-2.0
WANTLIB +=	gio-2.0 glib-2.0 gobject-2.0 gtk-3 harfbuzz intl jpeg
WANTLIB +=	lz4 lzma m pango-1.0 pangocairo-1.0 ssl xcb xcb-screensaver
WANTLIB +=	z opus avcodec avformat avutil swrtgwipesample swscale
WANTLIB +=	openal hunspell-1.7 xxhash usrsctp xcb-keysyms xcb-record
WANTLIB +=	giomm-2.4 glibmm-2.4 sigc-2.0 Qt5DBus dbusmenu-qt5

RUN_DEPENDS +=	x11/gtk+3,-guic devel/desktop-file-utils x11/qt5/qtimageformats

MODULES =	devel/cmake x11/qt5

CXXFLAGS +=	-DNDEBUG
USRSCTP_LDF =	`pkg-config --libs usrsctp` -pthread

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
			-DCMAKE_EXE_LINKER_FLAGS="${LDFLAGS} ${USRSCTP_LDF}" \
			-DDESKTOP_APP_WEBRTC_LOCATION=${TGOWT_DIR}/src/

pre-configure:
	@mkdir ${LIBEVENT_DIR}
	@cp ${FILESDIR}/{config,event-config}.h ${LIBEVENT_DIR}
	@mkdir -p ${TGOWT_DIR}/out/Release
	@cd ${TGOWT_DIR}/out/Release && \
		${SETENV} CC="${CC}" \
		CXX="${CXX}" \
		CFLAGS="${CFLAGS} -fPIC" \
		CXXFLAGS="${CXXFLAGS} -fPIC -DNDEBUG" \
		${CONFIGURE_ENV} \
		${LOCALBASE}/bin/cmake -G Ninja \
		-DBUILD_SHARED_LIBS=OFF \
		${TGOWT_DIR}

	@cd ${TGOWT_DIR}/out/Release && \
		${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/ninja

	@cd ${TDESKTOP_DIR}

.include <bsd.port.mk>

# $OpenBSD$

PKGNAME =	telegram-desktop-${V}
V =		3.1.5
REVISION =	0
TGOWT_V =	2021.09.14
USRSCTP_V =	0.9.5.0
COMMENT =	telegram desktop messaging app
DISTNAME =	${PRJ}-${V}-full
CATEGORIES =	tgwip local net

ACC =		telegramdesktop
PRJ =		tdesktop

MASTER_SITES=	https://github.com/${ACC}/${PRJ}/releases/download/v${V}/

TDESKTOP_DIR =	${WRKDIR}/${DISTNAME}

HOMEPAGE =	https://desktop.telegram.org/

# GPLv3
PERMIT_PACKAGE =	Yes

BUILD_DEPENDS +=	local/range-v3 local/tl-expected devel/yasm
BUILD_DEPENDS +=	local/microsoft-gsl local/libtg_owt=${TGOWT_V}

LIB_DEPENDS +=	audio/opus graphics/ffmpeg audio/openal textproc/hunspell
LIB_DEPENDS +=	sysutils/xxhash devel/glib2mm local/libusrsctp>=${USRSCTP_V}
LIB_DEPENDS +=	local/rnnoise local/abseil devel/libevent2 x11/qt5/qtsvg
LIB_DEPENDS +=	x11/dbusmenu-qt

WANTLIB +=	c ${COMPILER_LIBCXX} Qt5Core Qt5Gui Qt5Network Qt5Widgets Qt5Svg
WANTLIB +=	X11 crypto lz4 lzma m ssl xcb xcb-screensaver gio-2.0 glib-2.0
WANTLIB +=	gobject-2.0 intl jpeg vpx giomm-2.4 glibmm-2.4 sigc-2.0
WANTLIB +=	z opus avcodec avformat avutil swresample swscale
WANTLIB +=	openal hunspell-1.7 xxhash usrsctp xcb-keysyms xcb-record
WANTLIB +=	Xcomposite Xdamage Xext Xfixes Xrandr Xrender Xtst
WANTLIB +=	absl_base absl_int128 absl_log_severity absl_raw_logging_internal
WANTLIB +=	absl_spinlock_wait absl_strings absl_strings_internal
WANTLIB +=	absl_throw_delegate event_core event_extra rnnoise
WANTLIB +=	Qt5DBus dbusmenu-qt5

RUN_DEPENDS +=	devel/desktop-file-utils x11/qt5/qtimageformats

MODULES =	devel/cmake x11/qt5

CXXFLAGS +=	-DNDEBUG
EXTRA_LDFL =	`pkg-config --libs vpx usrsctp absl_strings libevent x11` -pthread

# # We're allowed to used the API ID of the Snap package
CONFIGURE_ARGS +=	-DCMAKE_BUILD_TYPE=Release \
			-DCMAKE_CXX_STANDARD=17 \
			-DLIBTGVOIP_DISABLE_ALSA=ON \
			-DLIBTGVOIP_DISABLE_PULSEAUDIO=ON \
			-DTDESKTOP_API_ID=611335 \
			-DTDESKTOP_API_HASH=d524b414d21f4d37f08684c1df41ac9c \
			-DDESKTOP_APP_SPECIAL_TARGET="" \
			-Ddisable_autoupdate=1 \
			-DDESKTOP_APP_DISABLE_DBUS_INTEGRATION=OFF \
			-DDESKTOP_APP_DISABLE_WAYLAND_INTEGRATION=ON \
			-DDESKTOP_APP_DISABLE_WEBKITGTK=ON \
			-DDESKTOP_APP_DISABLE_CRASH_REPORTS=ON \
			-DDESKTOP_APP_USE_PACKAGED=ON \
			-DDESKTOP_APP_USE_PACKAGED_FONTS=OFF \
			-DCMAKE_EXE_LINKER_FLAGS="${LDFLAGS} ${EXTRA_LDFL}"

.include <bsd.port.mk>

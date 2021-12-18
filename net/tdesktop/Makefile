# $OpenBSD$

# See https://github.com/telegramdesktop/tdesktop/issues/3167#issuecomment-658308298
NOT_FOR_ARCHS =	${BE_ARCHS}

COMMENT =		Official Telegram Desktop messenger
V =			3.3.0
DISTNAME =		tdesktop-${V}-full
PKGNAME =		tdesktop-${V}
CATEGORIES =		net

HOMEPAGE =		https://desktop.telegram.org
MASTER_SITES =		https://github.com/telegramdesktop/tdesktop/releases/download/v${V}/

# ${WRKSRC}/Telegram/ThirdParty/hunspell/tests/suggestiontest/Makefile.orig
PATCHORIG =		.pat.orig

MAINTAINER =		Andrew Krasavin <noiseless-ak@yandex.ru>, \
			Klemens Nanni <kn@openbsd.org>

# GPLv3
PERMIT_PACKAGE =	Yes

BUILD_DEPENDS =		devel/microsoft-gsl \
			devel/range-v3 \
			devel/tl-expected

LIB_DEPENDS =		audio/rnnoise \
			audio/openal \
			audio/opus \
			devel/abseil-cpp \
			devel/glib2mm \
			devel/libevent2 \
			graphics/ffmpeg \
			graphics/jpeg \
			net/tg_owt \
			net/usrsctp>=0.9.5.0 \
			sysutils/xxhash \
			textproc/hunspell \
			x11/dbusmenu-qt \
			x11/qt5/qtsvg

RUN_DEPENDS =		devel/desktop-file-utils \
			x11/gtk+3,-guic \
			x11/qt5/qtimageformats

MODULES =		devel/cmake \
			lang/python \
			x11/qt5
MODPY_RUNDEP =		No

WANTLIB +=	${COMPILER_LIBCXX} Qt5Core Qt5Gui Qt5Network Qt5Svg
WANTLIB +=	Qt5Widgets X11 absl_base absl_int128 absl_log_severity
WANTLIB +=	absl_raw_logging_internal absl_spinlock_wait absl_strings
WANTLIB +=	absl_strings_internal absl_throw_delegate avcodec avformat
WANTLIB +=	avutil c crypto event_core event_extra hunspell-1.7
WANTLIB +=	lz4 m openal opus rnnoise swresample swscale tg_owt
WANTLIB +=	usrsctp vpx xcb xcb-keysyms xcb-record xcb-screensaver
WANTLIB +=	xxhash z Qt5DBus dbusmenu-qt5

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
			-DDESKTOP_APP_DISABLE_CRASH_REPORTS=ON \
			-DDESKTOP_APP_USE_PACKAGED=ON \
			-DDESKTOP_APP_USE_PACKAGED_FONTS=OFF \
			-DDESKTOP_APP_QT6=OFF \
			-DCMAKE_EXE_LINKER_FLAGS="${LDFLAGS} ${EXTRA_LDFL}"

.include <bsd.port.mk>
# $OpenBSD: Makefile,v 1.4 2020/08/20 20:50:02 noiseless Exp $

PKGNAME =	libtg_owt-${V}
V =		2021.12.07
REVISION =	1
COMMENT =	open webrtc toolkit with telegram patches
DISTNAME =	${TGOWT_COMMIT}
CATEGORIES =	tgwip local net

USRSCTP_V =	0.9.5.0

TGOWT_COMMIT =	d5c3d43b959c7e9e7d8004b9b7fdadd12ce7d589
YUV_COMMIT =	a04e4f87fbf40405707b1d0ae9fcba8fc93f7856

MASTER_SITES0 =	https://github.com/desktop-app/tg_owt/archive/
MASTER_SITES2 =	https://gitlab.com/chromiumsrc/libyuv/-/archive/${YUV_COMMIT}/

DISTFILES =	${DISTNAME}${EXTRACT_SUFX}:0 \
		libyuv-${YUV_COMMIT}${EXTRACT_SUFX}:2

WRKDIST =	${WRKDIR}/tg_owt-${DISTNAME}
YUV_PATH = 	${WRKDIST}/src/third_party/libyuv
LIBUV =		libyuv-${YUV_COMMIT}

EXTRACT_CASES +=	${LIBUV}${EXTRACT_SUFX}) pax -zrs \
			',^.*${LIBUV},${YUV_PATH},' \
			-f ${FULLDISTDIR}/$$archive;;

HOMEPAGE =	https://github.com/desktop-app/tg_owt

# GPLv3
PERMIT_PACKAGE =	Yes

BUILD_DEPENDS +=	local/range-v3 local/tl-expected devel/yasm
BUILD_DEPENDS +=	local/microsoft-gsl local/abseil

BUILD_DEPENDS += 	audio/opus graphics/ffmpeg devel/protobuf
BUILD_DEPENDS += 	multimedia/libvpx net/usrsctp>=${USRSCTP_V}
BUILD_DEPENDS +=	devel/libevent2 graphics/ffmpeg

MODULES =	devel/cmake

SHARED_LIBS =	tg_owt	1.0

# shared builds is not officially supported:
# https://github.com/telegramdesktop/tdesktop/issues/10257#issuecomment-769698680
CONFIGURE_ARGS +=	-DCMAKE_BUILD_TYPE=RelWithDebInfo \
			-DBUILD_SHARED_LIBS:BOOL=OFF \
			-DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON \
			-DCMAKE_CXX_FLAGS="-DNDEBUG" \
			-DCMAKE_CXX_STANDARD=17 \
			-DTG_OWT_USE_PIPEWIRE=OFF \
			-DTG_OWT_BUILD_AUDIO_BACKENDS=OFF

.include <bsd.port.mk>

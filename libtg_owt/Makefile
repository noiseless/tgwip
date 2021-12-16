# $OpenBSD$

PKGNAME =	libtg_owt-${V}
V =		2021.12.07
REVISION =	2
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

LIB_DEPENDS +=		audio/opus graphics/ffmpeg devel/protobuf
LIB_DEPENDS +=		multimedia/libvpx net/usrsctp>=${USRSCTP_V}
LIB_DEPENDS +=		devel/libevent2 graphics/ffmpeg

MODULES =	devel/cmake

SHARED_LIBS =	tg_owt	1.0

WANTLIB +=	${COMPILER_LIBCXX} X11 Xcomposite Xdamage Xext Xfixes
WANTLIB +=	Xrandr Xrender Xtst crypto m ssl
WANTLIB +=	absl_bad_optional_access absl_bad_variant_access absl_base
WANTLIB +=	absl_city absl_civil_time absl_cord absl_cord_internal
WANTLIB +=	absl_cordz_functions absl_cordz_handle absl_cordz_info
WANTLIB +=	absl_debugging_internal absl_demangle_internal absl_exponential_biased
WANTLIB +=	absl_flags absl_flags_commandlineflag absl_flags_commandlineflag_internal
WANTLIB +=	absl_flags_config absl_flags_internal absl_flags_marshalling
WANTLIB +=	absl_flags_parse absl_flags_private_handle_accessor
WANTLIB +=	absl_flags_program_name absl_flags_reflection absl_flags_usage
WANTLIB +=	absl_flags_usage_internal absl_graphcycles_internal
WANTLIB +=	absl_hash absl_hashtablez_sampler absl_int128 absl_log_severity
WANTLIB +=	absl_low_level_hash absl_malloc_internal absl_raw_hash_set
WANTLIB +=	absl_raw_logging_internal absl_spinlock_wait absl_stacktrace
WANTLIB +=	absl_str_format_internal absl_strings absl_strings_internal
WANTLIB +=	absl_symbolize absl_synchronization absl_throw_delegate
WANTLIB +=	absl_time absl_time_zone avcodec avformat avutil gio-2.0
WANTLIB +=	glib-2.0 gobject-2.0 intl jpeg opus protobuf swresample
WANTLIB +=	swscale usrsctp vpx

# shared builds is not officially supported:
# https://github.com/telegramdesktop/tdesktop/issues/10257#issuecomment-769698680
CONFIGURE_ARGS +=	-DCMAKE_BUILD_TYPE=RelWithDebInfo \
			-DBUILD_SHARED_LIBS:BOOL=ON \
			-DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON \
			-DCMAKE_CXX_FLAGS="-DNDEBUG" \
			-DCMAKE_CXX_STANDARD=17 \
			-DTG_OWT_USE_PIPEWIRE=OFF \
			-DTG_OWT_BUILD_AUDIO_BACKENDS=OFF

.include <bsd.port.mk>

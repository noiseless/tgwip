# $OpenBSD$

# follow net/tdeskop
NOT_FOR_ARCHS =	${BE_ARCHS}

COMMENT =		WebRTC build for Telegram

GH_ACCOUNT =		desktop-app
GH_PROJECT =		tg_owt
# no releases or tags, use latest master
GH_COMMIT =		429a6869e4a164e0aad2d8657db341d56f9a6a6f
DISTNAME =		${GH_PROJECT}-0.0.0.20211212
CATEGORIES =		net

SHARED_LIBS =		tg_owt	1.0	# 0.0.0

# Fetch bundled dependencies that are missing from the tarball as per
# ${WRKSRC}/.gitmodules
#
# clone of https://chromium.googlesource.com/libyuv/libyuv which has
# no releases or tags, main/master/stable/<commit> tarballs are *unstable*;
# use GitHub fork with stable tarballs;
# no releases or tags, use latest master
LIBYUV_COMMIT =		742791f13a8ca9e8a297c323699aff8af30a360b
LIBYUV_DISTNAME =	libyuv-20210205-${LIBYUV_COMMIT:C/(........).*/\1/}
# Henry Hy maintains the FreeBSD package, they probably forked/clone precisely
# to have stable tarballs
MASTER_SITES0 =		https://github.com/HenryHu/libyuv/archive/

DISTFILES =		${GH_DISTFILE} \
			${LIBYUV_DISTNAME}${EXTRACT_SUFX}
# XXX can we rely on bsd.port.mk extracting libyuv after/inside of tg_owt?
EXTRACT_CASES =		${LIBYUV_DISTNAME}${EXTRACT_SUFX}) ${TAR} -xz \
			    -f ${FULLDISTDIR}/$$archive \
			    -C ${WRKSRC}/src/third_party/libyuv/ \
			    -s ,libyuv-${LIBYUV_COMMIT}/,, ;;

MAINTAINER =		Andrew Krasavin <noiseless-ak@yandex.ru>, \
			Klemens Nanni <kn@openbsd.org>

# BSD 3-clause
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} X11 Xcomposite Xdamage Xext Xfixes
WANTLIB += Xrandr Xrender Xtst absl_bad_optional_access absl_bad_variant_access
WANTLIB += absl_base absl_city absl_civil_time absl_cord absl_cord_internal
WANTLIB += absl_cordz_functions absl_cordz_handle absl_cordz_info
WANTLIB += absl_debugging_internal absl_demangle_internal absl_exponential_biased
WANTLIB += absl_flags absl_flags_commandlineflag absl_flags_commandlineflag_internal
WANTLIB += absl_flags_config absl_flags_internal absl_flags_marshalling
WANTLIB += absl_flags_parse absl_flags_private_handle_accessor
WANTLIB += absl_flags_program_name absl_flags_reflection absl_flags_usage
WANTLIB += absl_flags_usage_internal absl_graphcycles_internal
WANTLIB += absl_hash absl_hashtablez_sampler absl_int128 absl_log_severity
WANTLIB += absl_low_level_hash absl_malloc_internal absl_raw_hash_set
WANTLIB += absl_raw_logging_internal absl_spinlock_wait absl_stacktrace
WANTLIB += absl_str_format_internal absl_strings absl_strings_internal
WANTLIB += absl_symbolize absl_synchronization absl_throw_delegate
WANTLIB += absl_time absl_time_zone avcodec avformat avutil crypto
WANTLIB += gio-2.0 glib-2.0 gobject-2.0 intl jpeg m opus protobuf
WANTLIB += ssl swresample swscale usrsctp vpx

# C++17 set below, some components use -std=gnu++20
COMPILER =		base-clang ports-gcc

BUILD_DEPENDS =		devel/yasm

LIB_DEPENDS =		audio/opus \
			devel/abseil-cpp \
			devel/gettext,-runtime \
			devel/glib2 \
			devel/protobuf \
			graphics/ffmpeg \
			graphics/jpeg \
			multimedia/libvpx>=1.10.0 \
			net/usrsctp>=0.9.5.0

MODULES =		devel/cmake \
			lang/python
MODPY_RUNDEP =		No

# indicate an official package build and imply -DBUILD_SHARED_LIBS=ON;
# shared builds are not officially supported as per
# https://github.com/telegramdesktop/tdesktop/issues/10257#issuecomment-769698680
# but OpenBSD ports can do better
CONFIGURE_ARGS +=	-DTG_OWT_PACKAGED_BUILD=ON

# aovid unported ALSA und unneeded PulseAudio, net/tdesktop works wit OpenAL
CONFIGURE_ARGS +=	-DTG_OWT_BUILD_AUDIO_BACKENDS=OFF

# do not use unported pipewire for desktop capture (or anything else)
CONFIGURE_ARGS +=	-DTG_OWT_USE_PIPEWIRE=OFF

CONFIGURE_ARGS +=	-DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON \
			-DCMAKE_CXX_FLAGS="-DNDEBUG" \
			-DCMAKE_CXX_STANDARD=17

.include <bsd.port.mk>
# $OpenBSD$

# CMake Warning at cmake/arch.cmake:114 (message):
#   Unsupported CPU architecture.
# ...
# [1045/1275]
# ${WRKSRC}/src/common_audio/wav_header.cc:30:2:
#   error: #error "Code not working properly for big endian platforms."
NOT_FOR_ARCHS =		${BE_ARCHS}

COMMENT =		WebRTC build for Telegram
REVISION =		0

GH_ACCOUNT =		desktop-app
GH_PROJECT =		tg_owt
# no releases or tags, use latest master
GH_COMMIT =		6708e0d31a73e64fe12f54829bf4060c41b2658e
DISTNAME =		${GH_PROJECT}-0.0.0.20211214
CATEGORIES =		net

SHARED_LIBS =		tg_owt	0.0	# 0.0.0

MASTER_SITES1 =		https://github.com/desktop-app/tg_owt/commit/
# Pending "video_capture: Use correct V4L2 header on OpenBSD"
# https://github.com/desktop-app/tg_owt/pull/81
PATCHFILES +=		v4l2-header-fix-{}5036a7a5.patch:1
# Pending "Build on OpenBSD"
# https://github.com/desktop-app/tg_owt/pull/79
PATCHFILES +=		rtc_base-pthread-{}1f3189db.patch:1
PATCHFILES +=		rtc_base-endianness-{}442e3386.patch:1
PATCHFILES +=		libwebrtc-recognise-os-{}843c18ca.patch:1
PATCH_DIST_STRIP =	-p1

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
WANTLIB += gio-2.0 glib-2.0 gobject-2.0 intl m openh264 opus protobuf
WANTLIB += ssl swresample swscale usrsctp vpx yuv

# C++17 set below, some components use -std=gnu++20
COMPILER =		base-clang ports-gcc

BUILD_DEPENDS =		devel/yasm

LIB_DEPENDS =		audio/opus \
			devel/abseil-cpp \
			devel/gettext,-runtime \
			devel/glib2 \
			devel/protobuf \
			graphics/ffmpeg \
			graphics/libyuv \
			multimedia/libvpx>=1.10.0 \
			multimedia/openh264>=2.1.1p0 \
			net/usrsctp>=0.9.5.0

MODULES =		devel/cmake \
			lang/python
MODPY_RUNDEP =		No

# build an official package to look for system libraries and explicitly build
# a shared library, even though upstream officially discourages it as per
# https://github.com/telegramdesktop/tdesktop/issues/10257#issuecomment-769698680
CONFIGURE_ARGS +=	-DTG_OWT_PACKAGED_BUILD=ON \
			-DBUILD_SHARED_LIBS=ON

# do not use unported pipewire for desktop capture (or anything else)
CONFIGURE_ARGS +=	-DTG_OWT_USE_PIPEWIRE=OFF

CONFIGURE_ARGS +=	-DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON \
			-DCMAKE_CXX_STANDARD=17

# devel/abseil-cpp is found but it's include path is not picked up
CXXFLAGS +=		-I/usr/local/include

# ${WRKSRC}/src/third_party/ subdirectories
ALL_BUNDLES =	abseil-cpp libsrtp libvpx libyuv openh264 pffft pipewire rnnoise usrsctp yasm
# these are ported and probed for in ${WRKSRC}/cmake/external.cmake
PORTED_BUNDLES =abseil-cpp libsrtp libvpx libyuv openh264                rnnoise usrsctp yasm
# these are unported and/or not probed for and/or contain patches
NEEDED_BUNDLES =           libsrtp                        pffft          rnnoise

BAD_HDR_PATH_FILES =	src/api/video/i010_buffer.cc \
			src/api/video/i420_buffer.cc \
			src/api/video/nv12_buffer.cc \
			src/common_video/libyuv/libyuv_unittest.cc \
			src/common_video/libyuv/webrtc_libyuv.cc \
			src/common_video/video_frame_buffer.cc \
			src/modules/desktop_capture/desktop_frame.cc \
			src/modules/desktop_capture/desktop_frame_rotation.cc \
			src/modules/video_capture/video_capture_impl.cc \
			src/modules/video_coding/codecs/av1/libaom_av1_decoder.cc \
			src/modules/video_coding/codecs/h264/h264_decoder_impl.cc \
			src/modules/video_coding/codecs/h264/h264_encoder_impl.cc \
			src/modules/video_coding/codecs/test/videoprocessor.cc \
			src/modules/video_coding/codecs/vp8/libvpx_vp8_decoder.cc \
			src/modules/video_coding/codecs/vp8/libvpx_vp8_encoder.cc \
			src/modules/video_coding/codecs/vp9/libvpx_vp9_decoder.cc \
			src/modules/video_coding/codecs/vp9/libvpx_vp9_encoder.cc \
			src/modules/video_processing/video_denoiser.cc

post-extract:
	# remove unneeded bundles to prevent (accidential) use and packaging
.for _bundle in ${ALL_BUNDLES}
.    if !${NEEDED_BUNDLES:M${_bundle}}
	rm -fr -- ${WRKSRC}/src/third_party/${_bundle}
.    endif
.endfor

	# Remove wrong paths to the libyuv header files
.for _file in ${BAD_HDR_PATH_FILES}
	sed -i "s|third_party/libyuv/include/||g" "${WRKSRC}/${_file}"
.endfor
.include <bsd.port.mk>

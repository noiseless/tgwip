# $OpenBSD: Makefile,v 1.4 2020/08/20 20:50:02 noiseless Exp $

PKGNAME =	${GH_ACCOUNT}-${V}
V =		20210324.1
#REVISION =	1
COMMENT =	abseil common libraries (c++)
DISTNAME =	${GH_TAGNAME}
CATEGORIES =	tgwip local devel

GH_ACCOUNT =	abseil
GH_PROJECT =	${GH_ACCOUNT}-cpp
GH_TAGNAME =	${V}

HOMEPAGE =	https://abseil.io/
#MAINTAINER =	S

# APACHE20
PERMIT_PACKAGE =	Yes

SHARED_LIBS +=	absl_bad_any_cast_impl				0.0 # 2103.0.1
SHARED_LIBS +=	absl_bad_optional_access			0.0 # 2103.0.1
SHARED_LIBS +=	absl_bad_variant_access				0.0 # 2103.0.1
SHARED_LIBS +=	absl_base					0.0 # 2103.0.1
SHARED_LIBS +=	absl_city					0.0 # 2103.0.1
SHARED_LIBS +=	absl_civil_time					0.0 # 2103.0.1
SHARED_LIBS +=	absl_cord					0.0 # 2103.0.1
SHARED_LIBS +=	absl_debugging_internal				0.0 # 2103.0.1
SHARED_LIBS +=	absl_demangle_internal				0.0 # 2103.0.1
SHARED_LIBS +=	absl_examine_stack				0.0 # 2103.0.1
SHARED_LIBS +=	absl_exponential_biased				0.0 # 2103.0.1
SHARED_LIBS +=	absl_failure_signal_handler			0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags					0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags_commandlineflag			0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags_commandlineflag_internal		0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags_config				0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags_internal				0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags_marshalling				0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags_parse				0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags_private_handle_accessor		0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags_program_name				0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags_reflection				0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags_usage				0.0 # 2103.0.1
SHARED_LIBS +=	absl_flags_usage_internal			0.0 # 2103.0.1
SHARED_LIBS +=	absl_graphcycles_internal			0.0 # 2103.0.1
SHARED_LIBS +=	absl_hash					0.0 # 2103.0.1
SHARED_LIBS +=	absl_hashtablez_sampler				0.0 # 2103.0.1
SHARED_LIBS +=	absl_int128					0.0 # 2103.0.1
SHARED_LIBS +=	absl_leak_check					0.0 # 2103.0.1
SHARED_LIBS +=	absl_leak_check_disable				0.0 # 2103.0.1
SHARED_LIBS +=	absl_log_severity				0.0 # 2103.0.1
SHARED_LIBS +=	absl_malloc_internal				0.0 # 2103.0.1
SHARED_LIBS +=	absl_periodic_sampler				0.0 # 2103.0.1
SHARED_LIBS +=	absl_random_distributions			0.0 # 2103.0.1
SHARED_LIBS +=	absl_random_internal_distribution_test_util	0.0 # 2103.0.1
SHARED_LIBS +=	absl_random_internal_platform			0.0 # 2103.0.1
SHARED_LIBS +=	absl_random_internal_pool_urbg			0.0 # 2103.0.1
SHARED_LIBS +=	absl_random_internal_randen			0.0 # 2103.0.1
SHARED_LIBS +=	absl_random_internal_randen_hwaes		0.0 # 2103.0.1
SHARED_LIBS +=	absl_random_internal_randen_hwaes_impl		0.0 # 2103.0.1
SHARED_LIBS +=	absl_random_internal_randen_slow		0.0 # 2103.0.1
SHARED_LIBS +=	absl_random_internal_seed_material		0.0 # 2103.0.1
SHARED_LIBS +=	absl_random_seed_gen_exception			0.0 # 2103.0.1
SHARED_LIBS +=	absl_random_seed_sequences			0.0 # 2103.0.1
SHARED_LIBS +=	absl_raw_hash_set				0.0 # 2103.0.1
SHARED_LIBS +=	absl_raw_logging_internal			0.0 # 2103.0.1
SHARED_LIBS +=	absl_scoped_set_env				0.0 # 2103.0.1
SHARED_LIBS +=	absl_spinlock_wait				0.0 # 2103.0.1
SHARED_LIBS +=	absl_stacktrace					0.0 # 2103.0.1
SHARED_LIBS +=	absl_status					0.0 # 2103.0.1
SHARED_LIBS +=	absl_statusor					0.0 # 2103.0.1
SHARED_LIBS +=	absl_str_format_internal			0.0 # 2103.0.1
SHARED_LIBS +=	absl_strerror					0.0 # 2103.0.1
SHARED_LIBS +=	absl_strings					0.0 # 2103.0.1
SHARED_LIBS +=	absl_strings_internal				0.0 # 2103.0.1
SHARED_LIBS +=	absl_symbolize					0.0 # 2103.0.1
SHARED_LIBS +=	absl_synchronization				0.0 # 2103.0.1
SHARED_LIBS +=	absl_throw_delegate				0.0 # 2103.0.1
SHARED_LIBS +=	absl_time					0.0 # 2103.0.1
SHARED_LIBS +=	absl_time_zone					0.0 # 2103.0.1
SHARED_LIBS +=	absl_wyhash					0.0 # 2103.0.1

WANTLIB +=	${COMPILER_LIBCXX} m
MODULES =	devel/cmake

CONFIGURE_ENV =		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS =	-DBUILD_SHARED_LIBS:BOOL=ON \
			-DCMAKE_CXX_STANDARD=17

.include <bsd.port.mk>

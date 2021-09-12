# $OpenBSD: Makefile,v 1.4 2020/08/20 20:50:02 noiseless Exp $

PKGNAME =	tl-expected-${V}
V =		1.0.0

COMMENT =	c++11/14/17 std::expected with functional-style extensions
DISTNAME =	${GH_TAGNAME}
CATEGORIES =	tgwip local devel

GH_ACCOUNT =	TartanLlama
GH_PROJECT =	expected
GH_TAGNAME =	v${V}

_COMMIT =	284c6a3f0f61823cc3871b0f193e8df699e2c4ce
_URL =	https://raw.githubusercontent.com
MASTER_SITES0 =	${_URL}/${GH_ACCOUNT}/tl-cmake/${_COMMIT}/

DISTFILES =	${DISTNAME}${EXTRACT_SUFX} \
		add-tl.cmake:0

EXTRACT_ONLY =	${DISTNAME}${EXTRACT_SUFX}

HOMEPAGE =	https://github.com/TartanLlama/expected
#MAINTAINER =	S

# PD
PERMIT_PACKAGE =	Yes

MODULES =	devel/cmake

CONFIGURE_ARGS +=	-DFETCHCONTENT_SOURCE_DIR_TL_CMAKE=${WRKDIR}/cmake/tl-cmake

pre-configure:
	@mkdir -p ${WRKDIR}/cmake/tl-cmake/
	@cp ${FULLDISTDIR}/add-tl.cmake ${WRKDIR}/cmake/tl-cmake/

.include <bsd.port.mk>

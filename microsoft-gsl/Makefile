# $OpenBSD: Makefile,v 1.4 2020/08/20 20:50:02 noiseless Exp $

PKGNAME =	microsoft-gsl-${V}
V =		3.1.0
COMMENT =	guidelines support library
DISTNAME =	${GH_TAGNAME}
CATEGORIES =	tgwip local devel

GH_ACCOUNT =	microsoft
GH_PROJECT =	GSL
GH_TAGNAME =	v${V}

HOMEPAGE =	https://github.com/microsoft/GSL
#MAINTAINER =	S

# MIT
PERMIT_PACKAGE =	Yes

MODULES =	devel/cmake

CONFIGURE_ARGS =	-DGSL_TEST=OFF

.include <bsd.port.mk>

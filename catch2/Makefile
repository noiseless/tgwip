# $OpenBSD$

COMMENT =	Catch2 is testing framework for C++ with basic micro-benchmarking features

GH_ACCOUNT =		catchorg
GH_PROJECT =		Catch2
GH_TAGNAME =		v2.13.7
PKGNAME =		catch2-${GH_TAGNAME:C/v//g}
CATEGORIES =		local devel

HOMEPAGE =		https://github.com/catchorg/Catch2

# BSL 1.0 (boost software license)
PERMIT_PACKAGE =	Yes

MAINTAINER =		Andrew Krasavin <noiseless-ak@yandex.ru>, \
			Klemens Nanni <kn@openbsd.org>

# C++11 or higher
COMPILER =		base-clang ports-gcc
COMPILER_LANGS =	c++

MODULES =		devel/cmake

# All options look sane by default. There is nothing to change.
# If the extra tests don't take an inadequate amount of time, I'll
# turn them on by default. There's no serious reason for this, but
# extra tests seem like a good idea to me anyway.
CONFIGURE_ARGS +=	-DCATCH_BUILD_EXTRA_TESTS=ON

pre-configure:
	echo ${PKGNAME}

.include <bsd.port.mk>

# qmlplugindump
USE_WXNEEDED =		Yes

QT6NAME =		QtDeclarative
COMMENT =		Qt6 Quick and QML components
REVISION =		0

SHARED_LIBS +=	Qt6Qml                    0.2 # 6.3
SHARED_LIBS +=	Qt6Quick                  0.2 # 6.3
SHARED_LIBS +=	Qt6QuickParticles         0.2 # 6.3
SHARED_LIBS +=	Qt6QuickTest              0.2 # 6.3
SHARED_LIBS +=	Qt6QuickWidgets           0.2 # 6.3
SHARED_LIBS +=	Qt6QuickShapes            0.2 # 6.3
SHARED_LIBS +=	Qt6QmlModels              0.2 # 6.3
SHARED_LIBS +=	Qt6QmlWorkerScript        0.2 # 6.3
SHARED_LIBS +=	Qt6LabsFolderListModel    0.0 # 6.3
SHARED_LIBS +=	Qt6LabsQmlModels          0.0 # 6.3
SHARED_LIBS +=	Qt6LabsSettings           0.0 # 6.3
SHARED_LIBS +=	Qt6QmlCore                0.0 # 6.3
SHARED_LIBS +=	Qt6QmlLocalStorage        0.0 # 6.3
SHARED_LIBS +=	Qt6QmlXmlListModel        0.0 # 6.3
SHARED_LIBS +=	Qt6LabsAnimation          0.0 # 6.3
SHARED_LIBS +=	Qt6LabsSharedImage        0.0 # 6.3
SHARED_LIBS +=	Qt6LabsWavefrontMesh      0.0 # 6.3
SHARED_LIBS +=	Qt6QuickControls2         0.0 # 6.3
SHARED_LIBS +=	Qt6QuickControls2Impl     0.0 # 6.3
SHARED_LIBS +=	Qt6QuickDialogs2          0.0 # 6.3
SHARED_LIBS +=	Qt6QuickDialogs2QuickImpl 0.0 # 6.3
SHARED_LIBS +=	Qt6QuickDialogs2Utils     0.0 # 6.3
SHARED_LIBS +=	Qt6QuickLayouts           0.0 # 6.3
SHARED_LIBS +=	Qt6QuickTemplates2        0.0 # 6.3

WANTLIB += ${COMPILER_LIBCXX} GL Qt6Core Qt6Gui Qt6Network Qt6OpenGL
WANTLIB += Qt6Sql Qt6Test Qt6Widgets c m xkbcommon

MODULES =		lang/python
MODPY_RUNDEP =		No
MODQT6_DEPS =		Yes
LIB_DEPENDS =		x11/qt6/qtbase>=${VERSION},<${NEXT_VERSION}
BUILD_DEPENDS =		graphics/vulkan-loader
CONFIGURE_STYLE =	cmake

pre-configure:
# Python is used for building, this path does not get into final packages.
	ln -sf ${MODPY_BIN} ${WRKDIR}/bin/python

.include <bsd.port.mk>

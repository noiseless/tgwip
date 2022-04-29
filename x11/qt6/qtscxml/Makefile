QT6NAME =		QtScxml
COMMENT =		create state machines from SCXML files

SHARED_LIBS +=  Qt6Scxml                  0.0 # 6.3
SHARED_LIBS +=  Qt6ScxmlQml               0.0 # 6.3
SHARED_LIBS +=  Qt6StateMachine           0.0 # 6.3
SHARED_LIBS +=  Qt6StateMachineQml        0.0 # 6.3

WANTLIB += ${COMPILER_LIBCXX} GL Qt6Core Qt6Gui Qt6Network Qt6Qml
WANTLIB += c m xkbcommon

LIB_DEPENDS =		x11/qt6/qtdeclarative>=${QT6_VERSION},<${QT6_NEXT_VERSION}

.include <bsd.port.mk>

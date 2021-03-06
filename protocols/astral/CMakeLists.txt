CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
PROJECT( Astral )

find_package( PkgConfig )

if( PKG_CONFIG_FOUND )
	pkg_check_modules( TELEPATHY TelepathyQt4>=0.3.0 )
	include_directories( ${TELEPATHY_INCLUDE_DIRS} )
else( PKG_CONFIG_FOUND )
	set( TELEPATHY_INCLUDE_DIR "" CACHE PATH "Path to telepathy-qt4 include dir" )
	set( TELEPATHY_LIBRARY "" CACHE FILEPATH "Filepath to telepathy-qt4 library" )
	include_directories( ${TELEPATHY_INCLUDE_DIR} )
	list( APPEND TELEPATHY_LIBRARIES ${TELEPATHY_LIBRARY} )
endif( PKG_CONFIG_FOUND)


IF (NOT TELEPATHY_FOUND)
	message( "TelepathyQt4 not found. Can't enter the astral" )
	return()
ENDIF()

qutim_add_plugin( astral
	DISPLAY_NAME "Astral"
	DESCRIPTION "Communication by Telepathy"
	LINK_LIBRARIES ${TELEPATHY_LIBRARIES}
	GROUP "Protocols"
)

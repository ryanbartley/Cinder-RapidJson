if( NOT TARGET Cinder-RapidJson )
	
  get_filename_component( CINDER_RAPIDJSON_BLOCKS_PATH "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE )
  get_filename_component( CINDER_RAPIDJSON_PATH "${CINDER_RAPIDJSON_BLOCKS_PATH}/../../include" ABSOLUTE )
  get_filename_component( RAPIDJSON_INCLUDE_PATH "${CINDER_RAPIDJSON_BLOCKS_PATH}/rapidjson/include" ABSOLUTE )

	# Add OSC block as a dependency
  set( Cinder-RapidJson_INCLUDES ${RAPIDJSON_INCLUDE_PATH} ) 

endif()

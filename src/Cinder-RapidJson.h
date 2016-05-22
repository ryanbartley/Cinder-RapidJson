//
//  Cinder-RapidJson.h
//  Test
//
//  Created by Ryan Bartley on 5/20/16.
//
//

#pragma once

#include "rapidjson/document.h"
#include "rapidjson/writer.h"

class JsonDocument {
public:
	
	JsonDocument( const std::string &document );
	JsonDocument( const ci::DataSourceRef &document );
	JsonDocument( const char* document );
	JsonDocument();
	
	const rapidjson::Document& getDocument() const { return mDocument; }
	rapidjson::Document& getDocument() { return mDocument; }

	bool hasMember( const std::string &memberName ) { return mDocument.HasMember( memberName.c_str() ); }
	rapidjson::Value::MemberIterator findMember( const std::string &memberName )
	{ return mDocument.FindMember( memberName.c_str() ); }
	
	template<typename T>
	bool	is( const std::string &memberName ) { return mDocument[memberName.c_str()].Is<T>(); }
	template<typename T>
	T		get( const std::string &memberName ) { return mDocument[memberName.c_str()].Get<T>(); }
	template<typename T>
	void	set( const std::string &memberName, T val ) { return mDocument[memberName.c_str()].Set( val ); }
	
	template<typename T>
	void add( const std::string &name, T val ) { mDocument.AddMember( name, val, mDocument.GetAllocator() ); }
	template<typename T>
	void add( uint32_t index, T val ) { mDocument.AddMember( index, val, mDocument.GetAllocator() ); }
	
	void remove( const std::string &memberName ) { mDocument.RemoveMember( memberName.c_str() ); }
	
	rapidjson::Value& operator[]( const std::string &memberName ) { return mDocument[memberName.c_str()]; }
	rapidjson::Value& operator[]( const char* memberName ) { return mDocument[memberName]; }
	rapidjson::Value& operator[]( uint32_t index ) { return mDocument[index]; }
	
	rapidjson::Value::ValueIterator begin(){ return mDocument.Begin(); }
	rapidjson::Value::ValueIterator end() { return mDocument.End(); }
	
	rapidjson::Document::MemberIterator keysBegin() { return mDocument.MemberBegin(); }
	
	template<typename T>
	bool writeTo( T writeType );
	
	class ParseExc : public ci::Exception {
	public:
		ParseExc( const std::string &errorMsg );
		/*!
		 Document doc;
		 ParseResult ok = doc.Parse(json);
		 if (!ok)
			printf( "JSON parse error: %s (%u)\n", GetParseError_En(ok.Code()), ok.Offset());
		 */
	};
	
private:
	rapidjson::Document mDocument;
};

inline JsonDocument::JsonDocument( const std::string &document )
{
	
}

inline JsonDocument::JsonDocument( const ci::DataSourceRef &document )
{
	
}

inline JsonDocument::JsonDocument( const char *document )
{
	
}

inline JsonDocument::JsonDocument()
{
	
}


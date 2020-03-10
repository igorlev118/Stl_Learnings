// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_XML_PARSER_H__
#define __MURL_UTIL_XML_PARSER_H__

#include "murl_data.h"

namespace Murl
{
    namespace Util
    {
        class Attributes;
        
        /**
         * @ingroup MurlUtilClasses
         * @brief The XML parser base class.
         * A xml parser class has to derive from the XmlParser and implement
         * at least the CanParseRoot(), ParseRoot() and ParseElement() method.
         */
        class XmlParser
        {
        public:
            /**
             * @brief The default constructor.
             */
            XmlParser();
            
            /**
             * @brief The destructor.
             */
            virtual ~XmlParser();
            
            /**
             * @brief Start parsing a data object.
             * Parsing XML data calls StartElement() for each start tag which
             * reports the tag's attributes by calling CanParseRoot() and
             * ParseRoot() for the root tag, or ParseElement() for all other tags.\n
             * The characters between a start / end tag are reported by
             * calling ParseCharacterData().
             * The end tag is reported by EndElement().
             * @param data The data object to parse.
             * @return true if successful.
             */
            virtual Bool Parse(const ConstData& data);
            /**
             * @brief Start parsing a data object.
             * Use this overloaded method if you e.g. expect file names in the XML
             * data being parsed to be relative to some base path.
             * See Parse(const ConstData& data), which parses XML data relative
             * to the current path.
             * @param data The data object to parse.
             * @param basePath The base path to use.
             * @return true if successful.
             */
            virtual Bool Parse(const ConstData& data, const String& basePath);

            /**
             * @brief Check if the last Parse() was not successful.
             * @return true if the last Parse() was not successful.
             */
            virtual Bool HasError() const;
            
            /**
             * @brief Get the error string of the last Parse().
             * @return The error string of the last Parse().
             */
            virtual const String& GetErrorString() const;
            
            /**
             * @brief Enable / disable tracing of unused attributes during Parse().
             * Trace all unused attributes at the end of each StartElement()
             * call if enabled.
             * @param enable Set to true to enable or false to disable tracing.
             */
            virtual void SetTraceUnusedAttributes(Bool enable);
            
            /**
             * @brief Set the tracing prefix string.
             * The default prefix string is "Util::XmlParser".
             * @param prefix The prefix string.
             */
            virtual void SetTracePrefix(const String& prefix);
            
        protected:
            /**
             * @brief Report a start tag.
             * Reports the tag's attributes by calling CanParseRoot() and
             * ParseRoot() for the root tag, or ParseElement() for all other tags.
             * At last TraceUnusedAttributes() is called if tracing is enabled.
             * @param name The tag name.
             * @param attributes The attributes.
             * @return The result from CanParseRoot() and ParseRoot() or ParseElement(),
             *  if false is returned the parsing of this tag and all nested tags is skipped.
             */
            virtual Bool StartElement(const String& name, Attributes& attributes);
            /**
             * @brief Report an end tag.
             * @param name The tag name.
             * @param attributes The attributes.
             * @return true if successful.
             */
            virtual Bool EndElement(const String& name, Attributes& attributes);

            /**
             * @brief Report the begin of a CDATA section.
             * @return true if successful.
             */
            virtual Bool StartCData();
            /**
             * @brief Report the end of a CDATA section.
             * @return true if successful.
             */
            virtual Bool EndCData();

            /**
             * @brief Check if the root tag is valid.
             * @param name The tag name.
             * @return true if the root tag is valid, if false is returned the parsing
             *  of this tag of all nested tags is skipped.
             */
            virtual Bool CanParseRoot(const String& name) = 0;
            
            /**
             * @brief Parse the root tag and attributes.
             * @param name The tag name.
             * @param attributes The attributes.
             * @return true if successful, if false is returned the parsing of
             *  this tag and all nested tags is skipped.
             */
            virtual Bool ParseRoot(const String& name, Attributes& attributes) = 0;
            
            /**
             * @brief Parse a tag and attributes.
             * @param name The tag name.
             * @param attributes The attributes.
             * @return true if successful, if false is returned the parsing of
             *  this tag and all nested tags is skipped.
             */
            virtual Bool ParseElement(const String& name, Attributes& attributes) = 0;
            
            /**
             * @brief Parse the characters between a start / end tag.
             * @param name The tag name.
             * @param data The characters string.
             * @return true if successful.
             */
            virtual Bool ParseCharacterData(const String& name, const String& data);
            
            /**
             * @brief Get the current tag level.
             * The current tag level is the nested tag counter which
             * starts with zero at the root tag.
             * @return The current tag level or -1 if the parser is not active.
             */
            virtual SInt32 GetCurrentLevel() const;
            
            /**
             * @brief Get the line number from the current parsing position.
             * @return The current line number, zero if the parser is not active.
             */
            virtual UInt32 GetCurrentLine() const;
            
            /**
             * @brief Get the column number from the current parsing position.
             * @return The current column number, zero if the parser is not active.
             */
            virtual UInt32 GetCurrentColumn() const;
            
            /**
             * @brief Append a text to the error string.
             * After parsing the error string can be retreived by GetErrorString().
             * @param errorText The text to append, the current line number is
             *  inserted in front of the error text automatically.
             * @return true if successful, false if the parser is not active.
             */
            virtual Bool AppendError(const String& errorText);

            /**
             * @brief Get the base path set when Parse() was called.
             * @return The base path for the current parsing operation.
             */
            virtual String GetBasePath() const;

            /**
             * @brief Trace all unused attributes.
             * Uses the prefix set by SetTracePrefix().
             * @param attributes The attributes.
             */
            virtual void TraceUnusedAttributes(const Attributes& attributes);
            
        private:
            void StartElementHandler(const Char* name, const Char** attributes);
            void EndElementHandler(const char* name);
            void StartCDataHandler();
            void EndCDataHandler();
            void CharacterDataHandler(const char* data, int len);
            
            static void StaticStartElementHandler(void* userData, const char* name, const char** atts);
            static void StaticEndElementHandler(void* userData, const char* name);
            static void StaticStartCDataHandler(void* userData);
            static void StaticEndCDataHandler(void* userData);
            static void StaticCharacterDataHandler(void* userData, const char* data, int len);
            
            UInt32 mSkipCount;
            SInt32 mCurrentLevel;
            Bool mHasKnownRoot;
            Bool mHasParsingErrors;
            Bool mHasError;
            String mErrorString;
            String mBasePath;
            
            Bool mTraceUnusedAttributes;
            String mTracePrefix;
            
            String mCurrentElement;
            Array<Attributes*> mAttributesStack;
            void* mXmlParserHandle;
        };
    }
}

#endif // __MURL_UTIL_XML_PARSER_H__

// Copyright 2014 Spraylight GmbH

#ifndef __MURL_GRAPH_TRACKER_RESULT_H__
#define __MURL_GRAPH_TRACKER_RESULT_H__

#include "murl_graph_i_tracker_result.h"

namespace Murl
{
    namespace Graph
    {
        class INode;

        class TrackerResult : public ITrackerResult
        {
        public:
            TrackerResult(const INode* node, Type type, const Char* fnc, UInt32 line, const Char* message)
            : mNode(node)
            , mController(0)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
            }

            template<class Type0>
            TrackerResult(const INode* node, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0)
            : mNode(node)
            , mController(0)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
            }

            template<class Type0, class Type1>
            TrackerResult(const INode* node, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0, Type1 p1)
            : mNode(node)
            , mController(0)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
                mParameters.Add(Convert(p1));
            }

            template<class Type0, class Type1, class Type2>
            TrackerResult(const INode* node, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0, Type1 p1, Type2 p2)
            : mNode(node)
            , mController(0)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
                mParameters.Add(Convert(p1));
                mParameters.Add(Convert(p2));
            }

            template<class Type0, class Type1, class Type2, class Type3>
            TrackerResult(const INode* node, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0, Type1 p1, Type2 p2, Type3 p3)
            : mNode(node)
            , mController(0)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
                mParameters.Add(Convert(p1));
                mParameters.Add(Convert(p2));
                mParameters.Add(Convert(p3));
            }

            template<class Type0, class Type1, class Type2, class Type3, class Type4>
            TrackerResult(const INode* node, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0, Type1 p1, Type2 p2, Type3 p3, Type4 p4)
            : mNode(node)
            , mController(0)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
                mParameters.Add(Convert(p1));
                mParameters.Add(Convert(p2));
                mParameters.Add(Convert(p3));
                mParameters.Add(Convert(p4));
            }

            template<class Type0, class Type1, class Type2, class Type3, class Type4, class Type5>
            TrackerResult(const INode* node, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0, Type1 p1, Type2 p2, Type3 p3, Type4 p4, Type5 p5)
            : mNode(node)
            , mController(0)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
                mParameters.Add(Convert(p1));
                mParameters.Add(Convert(p2));
                mParameters.Add(Convert(p3));
                mParameters.Add(Convert(p4));
                mParameters.Add(Convert(p5));
            }

            TrackerResult(const IController* controller, Type type, const Char* fnc, UInt32 line, const Char* message)
            : mNode(0)
            , mController(controller)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
            }

            template<class Type0>
            TrackerResult(const IController* controller, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0)
            : mNode(0)
            , mController(controller)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
            }

            template<class Type0, class Type1>
            TrackerResult(const IController* controller, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0, Type1 p1)
            : mNode(0)
            , mController(controller)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
                mParameters.Add(Convert(p1));
            }

            template<class Type0, class Type1, class Type2>
            TrackerResult(const IController* controller, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0, Type1 p1, Type2 p2)
            : mNode(0)
            , mController(controller)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
                mParameters.Add(Convert(p1));
                mParameters.Add(Convert(p2));
            }

            template<class Type0, class Type1, class Type2, class Type3>
            TrackerResult(const IController* controller, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0, Type1 p1, Type2 p2, Type3 p3)
            : mNode(0)
            , mController(controller)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
                mParameters.Add(Convert(p1));
                mParameters.Add(Convert(p2));
                mParameters.Add(Convert(p3));
            }

            template<class Type0, class Type1, class Type2, class Type3, class Type4>
            TrackerResult(const IController* controller, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0, Type1 p1, Type2 p2, Type3 p3, Type4 p4)
            : mNode(0)
            , mController(controller)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
                mParameters.Add(Convert(p1));
                mParameters.Add(Convert(p2));
                mParameters.Add(Convert(p3));
                mParameters.Add(Convert(p4));
            }

            template<class Type0, class Type1, class Type2, class Type3, class Type4, class Type5>
            TrackerResult(const IController* controller, Type type, const Char* fnc, UInt32 line, const Char* message, Type0 p0, Type1 p1, Type2 p2, Type3 p3, Type4 p4, Type5 p5)
            : mNode(0)
            , mController(controller)
            , mType(type)
            , mFunction(fnc)
            , mLine(line)
            , mMessage(message)
            {
                mParameters.Add(Convert(p0));
                mParameters.Add(Convert(p1));
                mParameters.Add(Convert(p2));
                mParameters.Add(Convert(p3));
                mParameters.Add(Convert(p4));
                mParameters.Add(Convert(p5));
            }
            
            virtual ~TrackerResult();

            virtual const ITrackerResult* Clone() const;

            virtual const INode* GetNode() const;
            virtual const IController* GetController() const;

            virtual Type GetType() const;

            virtual const String& GetFunction() const;
            virtual UInt32 GetLine() const;

            virtual const String& GetMessage() const;
            virtual const StringArray& GetParameters() const;

        protected:
            template<class DataType>
            String Convert(DataType v);

            template<class PointerType>
            String Convert(const PointerType* v)
            {
                if (sizeof(v) == 4)
                {
                    return Util::UInt64ToString((UInt32)v, "%08x");
                }
                else
                {
                    return Util::UInt64ToString((UInt64)v, "%016x");
                }
            }

            template<class PointerType>
            String Convert(PointerType* v)
            {
                if (sizeof(v) == 4)
                {
                    return Util::UInt64ToString((UInt32)v, "%08x");
                }
                else
                {
                    return Util::UInt64ToString((UInt64)v, "%016x");
                }
            }

            const INode* mNode;
            const IController* mController;

            Type mType;

            String mFunction;
            UInt32 mLine;

            String mMessage;
            StringArray mParameters;
        };
    }
}

#define MURL_TRACKER_INFO(...) tracker->GetTrackerInterface()->AddResult(::Murl::Graph::TrackerResult(this, ::Murl::Graph::ITrackerResult::TYPE_INFO, MURL_CURRENT_FUNCTION, __LINE__, __VA_ARGS__));
#define MURL_TRACKER_WARNING(...) tracker->GetTrackerInterface()->AddResult(::Murl::Graph::TrackerResult(this, ::Murl::Graph::ITrackerResult::TYPE_WARNING, MURL_CURRENT_FUNCTION, __LINE__, __VA_ARGS__));
#define MURL_TRACKER_ERROR(...) tracker->GetTrackerInterface()->AddResult(::Murl::Graph::TrackerResult(this, ::Murl::Graph::ITrackerResult::TYPE_ERROR, MURL_CURRENT_FUNCTION, __LINE__, __VA_ARGS__));

#endif // __MURL_GRAPH_TRACKER_RESULT_H__

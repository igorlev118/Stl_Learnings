// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_UTIL_ENVIRONMENT_H__
#define __MURL_UTIL_ENVIRONMENT_H__

#include "murl_string.h"
#include "murl_color.h"
#include "murl_enum.h"
#include "murl_auto_pointer.h"
#include "murl_system_console.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilClasses
         * @brief The command arguments parser base class.
         * To create and register command arguments, you must derive from
         * the base class and implement Init() e.g.:
         * @code
         *  class MyEnvironment : public Util::Environment
         *  {
         *  public:
         *      const SwitchParameter* mMySwitchParam;
         *      const StringArrayParameter* mMyFilesParam;
         *
         *  protected:
         *      virtual void Init()
         *      {
         *          mMySwitchParam = Register<SwitchParameter>(PARAMETER_TYPE_OPTIONAL, "switch", "s", "Enable My Switch");
         *          mMyFilesParam = Register<StringArrayParameter>(PARAMETER_TYPE_MANDATORY, "file", "f", "Specify files(s)");
         *      }
         *  };
         * @endcode
         * To get the command arguments simply call Create(),
         *  e.g. assuming an instance mMyEnvironment exists:
         * @code
         *  if (!mMyEnvironment.Create(argC, argV))
         *  {
         *      System::Console::Print(mEnvironment.GetUsage());
         *      return false;
         *  }
         *  if (mMyEnvironment.mMySwitchParam->mValue)
         *  {
         *      // parameter --switch or -s was specified
         *  }
         *  for (UInt32 i = 0; i < mMyEnvironment.mMyFilesParam->mValue.GetCount(); i++)
         *  {
         *      // parameter --file or -f was specified, e.g. -f aFile1 -f aFile2 --file aFile3
         *      mMyEnvironment.mMyFilesParam->mValue[i];    // get the file name string
         *  }
         * @endcode
         */
        class Environment
        {
        public:
            /**
             * @brief The default constructor.
             */
            Environment();
            /**
             * @brief The destructor.
             */
            virtual ~Environment();

            /**
             * @brief Initialize and parse the command arguments.
             * Calls DeInit(), deletes all registered parameters,
             * calls Init() and ParseParameters().
             * @param argC The number of arguments.
             * @param argV The argument string values.
             * @return false if ParseParameters() failed,
             *  otherwise the result from IsValid() is returned.
             */
            virtual Bool Create(SInt32 argC, const char** argV);

            /**
             * @brief Forward to Create(SInt32 argC, const char** argV).
             * @param argC The number of arguments.
             * @param argV The argument string values.
             * @return false if ParseParameters() failed,
             *  otherwise the result from IsValid() is returned.
             */
            virtual Bool Create(SInt32 argC, char** argV);

            /**
             * @brief Initialize and parse the command arguments.
             * See Create(SInt32 argC, const char** argV).
             * @param args A string array containing the arguments.
             * @return false if ParseParameters() failed,
             *  otherwise the result from IsValid() is returned.
             */
            virtual Bool Create(const StringArray& args);

            /**
             * @brief Get the free parameters string array.
             * Free parameters are parameters which have no leading '-' option,
             * e.g. a list of file names. To accept this kind of parameters
             * SetAcceptFreeParameters() must be called before Create() or during Init().
             * @return The free parameters string array.
             */
            const StringArray& GetFreeParameters() const;

            /**
             * @brief Check if all mandatory parameters are set.
             * @return true if all mandatory parameters are set.
             */
            virtual Bool Validate();

            /**
             * @brief Get the usage string of all registered parameters.
             * @return The usage string of all registered parameters.
             */
            virtual String GetUsage() const;

            /**
             * @brief Get the last error parameter.
             * @return The last error parameter string.
             */
            virtual const String& GetLastError() const;

        protected:
            /**
             * @brief Overload to initialize and register parameters.
             */
            virtual void Init() = 0;

            /**
             * @brief Overload to de-initialize, default implementation is empty.
             */
            virtual void DeInit();

            /**
             * @brief Register a new allocated parameter object.
             * All registered parameter objects are deleted automatically
             * at environment class destruction or when calling Create().
             * @param param The new allocated parameter object.
             * @return The registered parameter object.
             */
            template<class ParamType>
            const ParamType* Register(ParamType* param)
            {
                mParameters.Add(Parameter::AutoPtr(param));
                return param;
            }

            /**
             * @brief Parse the command arguments and convert the argument
             * values into the corresponding registered parameter objects.
             * @param argC The number of arguments.
             * @param argV The argument string values.
             * @return true if successful.
             */
            virtual Bool ParseParameters(SInt32 argC, const char** argV);

            /**
             * @brief Definition of the parameter types.
             */
            enum ParameterType
            {
                /** @brief The mandatory parameter type. */
                PARAMETER_TYPE_MANDATORY,
                /** @brief The optional parameter type. */
                PARAMETER_TYPE_OPTIONAL,

                NUM_PARAMETER_TYPES
            };

            /**
             * @brief Set the free parameters acceptance.
             * Free parameters are parameters which have no leading '-' option,
             * e.g. a list of file names. To accept this kind of parameters
             * this method must be called before Create() or during Init().
             * \n Use GetFreeParameters() to read the parameters after parsing.
             * @param accept true to accept free parameters.
             * @param type The type of the parameter.
             */
            void SetAcceptFreeParameters(Bool accept, ParameterType type);

            /**
             * @brief Create and register a parameter class.
             * @param type The type of the parameter.
             * @param longId The long parameter identifier string.
             * @param shortId The short parameter identifier string.
             * @param description The parameter description string.
             * @tparam ParamType The parameter class type to create.
             * @return The registered parameter object.
             */
            template<class ParamType>
            const ParamType* Register(ParameterType type, const String& longId, const String& shortId,
                                      const String& description)
            {
                ParamType* param = new ParamType(type, longId, shortId, description);
                return Register(param);
            }

            /**
             * @brief Create and register a parameter class with a default value.
             * @param type The type of the parameter.
             * @param longId The long parameter identifier string.
             * @param shortId The short parameter identifier string.
             * @param description The parameter description string.
             * @param defaultValue The parameter default value.
             * @tparam ParamType The parameter class type to create.
             * @tparam DataType The default value class type.
             * @return The registered parameter object.
             */
            template<class ParamType, class DataType>
            const ParamType* Register(ParameterType type, const String& longId, const String& shortId,
                                      const String& description, const DataType& defaultValue)
            {
                ParamType* param = new ParamType(type, longId, shortId, description, defaultValue);
                return Register(param);
            }

            /**
             * @brief Create and register an enumeration parameter class.
             * @param type The type of the parameter.
             * @param longId The long parameter identifier string.
             * @param shortId The short parameter identifier string.
             * @param description The parameter description string.
             * @param enumClass The enumeration string mapping class.
             * @tparam ParamType The parameter class type to create.
             * @tparam EnumType The enumeration class type.
             * @return The registered parameter object.
             */
            template<class ParamType, class EnumType>
            const ParamType* Register(ParameterType type, const String& longId, const String& shortId,
                                      const String& description, const Enum<EnumType>& enumClass)
            {
                ParamType* param = new ParamType(type, longId, shortId, description, enumClass);
                return Register(param);
            }

            /**
             * @brief Create and register an enumeration parameter class with a default value.
             * @param type The type of the parameter.
             * @param longId The long parameter identifier string.
             * @param shortId The short parameter identifier string.
             * @param description The parameter description string.
             * @param enumClass The enumeration string mapping class.
             * @param defaultValue The parameter default value.
             * @tparam ParamType The parameter class type to create.
             * @tparam EnumType The enumeration class type.
             * @return The registered parameter object.
             */
            template<class ParamType, class EnumType>
            const ParamType* Register(ParameterType type, const String& longId, const String& shortId,
                                      const String& description, const Enum<EnumType>& enumClass, EnumType defaultValue)
            {
                ParamType* param = new ParamType(type, longId, shortId, description, enumClass, defaultValue);
                return Register(param);
            }

            /**
             * @brief The parameter base class.
             */
            class Parameter
            {
            public:
                /**
                 * @brief Definition of the parameter auto pointer.
                 */
                typedef AutoPointer<Parameter> AutoPtr;

                /**
                 * @brief The constructor.
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param skip The number of arguments used by the parameter.
                 * @param isArray true if the parameter implements an array.
                 */
                Parameter(ParameterType type, const String& longId, const String& shortId,
                          const String& description, SInt32 skip, Bool isArray);
                /**
                 * @brief The destructor.
                 */
                virtual ~Parameter() {}

                /**
                 * @brief Process the parameter's arguments.
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV);

                /** @brief The parameter type. */
                ParameterType mType;

                /** @brief The long parameter identifier string. */
                String mLongId;

                /** @brief The short parameter identifier string. */
                String mShortId;

                /** @brief The parameter description string. */
                String mDescription;

                /** @brief Flag if the parameter is set. */
                Bool mIsSet;

                /** @brief The number of arguments used by the parameter. */
                SInt32 mSkip;

                /** @brief Signature for parameter arrays. */
                Bool mIsArray;
            };

            /**
             * @brief The string parameter class.
             */
            class StringParameter : public Parameter
            {
            public:
                /**
                 * @brief The constructor taking an optional default string,
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param defaultValue The default value.
                 */
                StringParameter(ParameterType type, const String& longId, const String& shortId, const String& description,
                                const String& defaultValue = Util::StaticEmptyString());

                /**
                 * @brief Overload of Parameter::Process() converting the mValue.
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV);

                /** @brief The processed argument value. */
                String mValue;
            };

            /**
             * @brief The string array parameter class.
             * The default value is replaced by the first argument processed.
             */
            class StringArrayParameter : public Parameter
            {
            public:
                /**
                 * @brief The constructor taking a default value, see Parameter::Parameter().
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param defaultValue The default value.
                 */
                StringArrayParameter(ParameterType type, const String& longId, const String& shortId, const String& description,
                                     const String& defaultValue);
                /**
                 * @brief The constructor, see Parameter::Parameter().
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 */
                StringArrayParameter(ParameterType type, const String& longId, const String& shortId, const String& description);

                /**
                 * @brief Overload of Parameter::Process() converting the mValue(s).
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV);

                /** @brief Flag if mValue array has a default value set. */
                Bool mHasDefaultValue;

                /** @brief The processed argument values. */
                StringArray mValue;
            };

            /**
             * @brief The string pair array parameter class.
             * Takes two string arguments for each parameter.
             */
            class StringPairArrayParameter : public Parameter
            {
            public:
                /**
                 * @brief The constructor, see Parameter::Parameter().
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 */
                StringPairArrayParameter(ParameterType type, const String& longId, const String& shortId, const String& description);

                /**
                 * @brief Overload of Parameter::Process() converting the mValue[1|2](s).
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV);

                /** @brief The first processed argument values. */
                StringArray mValue1;

                /** @brief The second processed argument values. */
                StringArray mValue2;
            };

            /**
             * @brief The integer parameter class.
             */
            class SInt32Parameter : public Parameter
            {
            public:
                /**
                 * @brief The constructor taking an optional default value,
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param defaultValue The default value.
                 */
                SInt32Parameter(ParameterType type, const String& longId, const String& shortId, const String& description,
                                SInt32 defaultValue = 0);

                /**
                 * @brief Overload of Parameter::Process() converting the mValue.
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV);

                /** @brief The processed argument value. */
                SInt32 mValue;
            };

            /**
             * @brief The integer array parameter class.
             * The default value is replaced by the first argument processed.
             */
            class SInt32ArrayParameter : public Parameter
            {
            public:
                /**
                 * @brief The constructor taking a default value, see Parameter::Parameter().
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param defaultValue The default value.
                 */
                SInt32ArrayParameter(ParameterType type, const String& longId, const String& shortId, const String& description,
                                     SInt32 defaultValue);
                /**
                 * @brief The constructor, see Parameter::Parameter().
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 */
                SInt32ArrayParameter(ParameterType type, const String& longId, const String& shortId, const String& description);

                /**
                 * @brief Overload of Parameter::Process() converting the mValue(s).
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV);

                /** @brief Flag if mValue array has a default value set. */
                Bool mHasDefaultValue;

                /** @brief The processed argument values. */
                SInt32Array mValue;
            };

            /**
             * @brief The floating point parameter class.
             */
            class DoubleParameter : public Parameter
            {
            public:
                /**
                 * @brief The constructor taking an optional default value,
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param defaultValue The default value.
                 */
                DoubleParameter(ParameterType type, const String& longId, const String& shortId, const String& description,
                                Double defaultValue = 0);

                /**
                 * @brief Overload of Parameter::Process() converting the mValue.
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV);

                /** @brief The processed argument value. */
                Double mValue;
            };

            /**
             * @brief The floating point array parameter class.
             * The default value is replaced by the first argument processed.
             */
            class DoubleArrayParameter : public Parameter
            {
            public:
                /**
                 * @brief The constructor taking a default value, see Parameter::Parameter().
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param defaultValue The default value.
                 */
                DoubleArrayParameter(ParameterType type, const String& longId, const String& shortId, const String& description,
                                     Double defaultValue);
                /**
                 * @brief The constructor, see Parameter::Parameter().
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 */
                DoubleArrayParameter(ParameterType type, const String& longId, const String& shortId, const String& description);

                /**
                 * @brief Overload of Parameter::Process() converting the mValue(s).
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV);

                /** @brief Flag if mValue array has a default value set. */
                Bool mHasDefaultValue;

                /** @brief The processed argument values. */
                DoubleArray mValue;
            };

            /**
             * @brief The color parameter class.
             * The color processing uses the Util::StringToColor() syntax.
             */
            class ColorParameter : public Parameter
            {
            public:
                /**
                 * @brief The constructor taking an optional default value,
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param defaultValue The default value.
                 */
                ColorParameter(ParameterType type, const String& longId, const String& shortId, const String& description,
                               const Color& defaultValue = Color(0));

                /**
                 * @brief Overload of Parameter::Process() converting the mValue.
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV);

                /** @brief The processed argument value. */
                Color mValue;
            };

            /**
             * @brief The boolean parameter class.
             */
            class SwitchParameter : public Parameter
            {
            public:
                /**
                 * @brief The constructor taking an optional default value,
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param defaultValue The default value.
                 */
                SwitchParameter(ParameterType type, const String& longId, const String& shortId, const String& description,
                                Bool defaultValue = false);

                /**
                 * @brief Overload of Parameter::Process() converting the mValue.
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV);

                /** @brief The processed argument value. */
                Bool mValue;
            };

            /**
             * @brief The enumeration parameter template class.
             */
            template<class EnumType>
            class EnumParameter : public Parameter
            {
            public:
                /**
                 * @brief The constructor.
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param enumClass The enumeration string mapping class.
                 * @param defaultValue The default value.
                 */
                EnumParameter(ParameterType type, const String& longId, const String& shortId, const String& description,
                              const Enum<EnumType>& enumClass, EnumType defaultValue)
                : Parameter(type, longId, shortId, description, 2, false)
                , mEnum(enumClass)
                , mValue(defaultValue)
                {
                }

                /**
                 * @brief Overload of Parameter::Process() converting the mValue.
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV)
                {
                    SInt32 skip = Parameter::Process(currentIndex, argC, argV);
                    if (skip > 0)
                    {
                        String value = argV[currentIndex + 1];
                        Bool error;
                        mValue = mEnum.GetEnumValueByName(value, error);
                        if (error)
                        {
                            System::Console::Print("Unknown name '%s' for Enum '%s'\n", value.Begin(), mEnum.GetName().Begin());
                            return -1;
                        }
                    }
                    return skip;
                }

                /** @brief The enumeration string mapping class. */
                const Enum<EnumType>& mEnum;

                /** @brief The processed argument value. */
                EnumType mValue;
            };

            /**
             * @brief The enumeration array parameter template class.
             */
            template<class EnumType>
            class EnumArrayParameter : public Parameter
            {
            public:
                /**
                 * @brief The constructor taking a default value.
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param enumClass The enumeration string mapping class.
                 * @param defaultValue The default value.
                 */
                EnumArrayParameter(ParameterType type, const String& longId, const String& shortId, const String& description,
                                   const Enum<EnumType>& enumClass, EnumType defaultValue)
                : Parameter(type, longId, shortId, description, 2, true)
                , mEnum(enumClass)
                , mHasDefaultValue(true)
                {
                    mValue.Add(defaultValue);
                }

                /**
                 * @brief The constructor.
                 * @param type The type of the parameter.
                 * @param longId The long parameter identifier string.
                 * @param shortId The short parameter identifier string.
                 * @param description The parameter description string.
                 * @param enumClass The enumeration string mapping class.
                 */
                EnumArrayParameter(ParameterType type, const String& longId, const String& shortId, const String& description,
                                   const Enum<EnumType>& enumClass)
                : Parameter(type, longId, shortId, description, 2, true)
                , mEnum(enumClass)
                , mHasDefaultValue(false)
                {
                }

                /**
                 * @brief Overload of Parameter::Process() converting the mValue(s).
                 * @param currentIndex The zero-based index to the current argument.
                 * @param argC The number of arguments.
                 * @param argV The argument string values.
                 * @return The number of arguments processed or
                 *  -1 if parsing the argument failed.
                 */
                virtual SInt32 Process(SInt32 currentIndex, SInt32 argC, const char** argV)
                {
                    SInt32 skip = Parameter::Process(currentIndex, argC, argV);
                    if (skip > 0)
                    {
                        if (mHasDefaultValue)
                        {
                            mValue.Clear();
                            mHasDefaultValue = false;
                        }

                        String param = argV[currentIndex + 1];
                        Bool error = false;
                        EnumType value = mEnum.GetEnumValueByName(param, error);
                        if (error)
                        {
                            System::Console::Print("Unknown name '%s' for Enum '%s'\n", param.Begin(), mEnum.GetName().Begin());
                            return -1;
                        }
                        mValue.Add(value);
                    }
                    return skip;
                }

                /** @brief The enumeration string mapping class. */
                const Enum<EnumType>& mEnum;

                /** @brief Flag if mValue array has a default value set. */
                Bool mHasDefaultValue;

                /** @brief The processed argument values. */
                Array<EnumType> mValue;
            };

            /** @brief The registered parameter objects. */
            Array<Parameter::AutoPtr> mParameters;

            /** @brief The accept free parameters, default false. */
            Bool mAcceptFreeParameters;
            /** @brief The free parameters type, default PARAMETER_TYPE_OPTIONAL. */
            ParameterType mFreeParametersType;
            /** @brief The free parameters. */
            StringArray mFreeParameters;

            /** @brief The last error parameter. */
            String mLastError;
        };
    }
}

#endif // __MURL_UTIL_ENVIRONMENT_H__

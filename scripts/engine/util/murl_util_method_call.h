// Copyright 2012 Spraylight GmbH

#ifndef __MURL_UTIL_METHOD_CALL_H__
#define __MURL_UTIL_METHOD_CALL_H__

#include "murl_i_method_call.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object.
         */
        template<class ObjectType>
        class MethodCall0 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             */
            MethodCall0(ObjectType* object, Bool (ObjectType::*method)())
            : mObject(object)
            , mMethod(method)
            {
            }
            
            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)();
                delete this;
                return ret;
            }
            
        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)();
        };
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @return The method call object.
         */
        template<class ObjectType>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)())
        {
            return new MethodCall0<ObjectType>(obj, method);
        }
        
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 1 method parameter.
         */
        template<class ObjectType, class Par1Type>
        class MethodCall1 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             */
            MethodCall1(ObjectType* object, Bool (ObjectType::*method)(Par1Type), Par1Type par1)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            {
            }
            
            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1);
                delete this;
                return ret;
            }
            
        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type);
            Par1Type mPar1;
        };
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 1 method parameter.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type),
                                            Par1Type par1)
        {
            return new MethodCall1<ObjectType, Par1Type>(obj, method, par1);
        }

        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 2 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type>
        class MethodCall2 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             */
            MethodCall2(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type),
                        Par1Type par1, Par2Type par2)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            {
            }
            
            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2);
                delete this;
                return ret;
            }
            
        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type);
            Par1Type mPar1;
            Par2Type mPar2;
        };
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 2 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type),
                                            Par1Type par1, Par2Type par2)
        {
            return new MethodCall2<ObjectType, Par1Type, Par2Type>(obj, method, par1, par2);
        }
        
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 3 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type>
        class MethodCall3 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             * @param par3 The 3rd parameter.
             */
            MethodCall3(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type),
                        Par1Type par1, Par2Type par2, Par3Type par3)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            , mPar3(par3)
            {
            }
            
            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2, mPar3);
                delete this;
                return ret;
            }
            
        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type, Par3Type);
            Par1Type mPar1;
            Par2Type mPar2;
            Par3Type mPar3;
        };
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 3 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @param par3 The 3rd parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type),
                                            Par1Type par1, Par2Type par2, Par3Type par3)
        {
            return new MethodCall3<ObjectType, Par1Type, Par2Type, Par3Type>(obj, method, par1, par2, par3);
        }
        
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 4 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type>
        class MethodCall4 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             * @param par3 The 3rd parameter.
             * @param par4 The 4th parameter.
             */
            MethodCall4(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type),
                        Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            , mPar3(par3)
            , mPar4(par4)
            {
            }
            
            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2, mPar3, mPar4);
                delete this;
                return ret;
            }
            
        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type, Par3Type, Par4Type);
            Par1Type mPar1;
            Par2Type mPar2;
            Par3Type mPar3;
            Par4Type mPar4;
        };
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 4 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @param par3 The 3rd parameter.
         * @param par4 The 4th parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type),
                                            Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4)
        {
            return new MethodCall4<ObjectType, Par1Type, Par2Type, Par3Type, Par4Type>(obj, method, par1, par2, par3, par4);
        }
        
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 5 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type>
        class MethodCall5 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             * @param par3 The 3rd parameter.
             * @param par4 The 4th parameter.
             * @param par5 The 5th parameter.
             */
            MethodCall5(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type),
                        Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            , mPar3(par3)
            , mPar4(par4)
            , mPar5(par5)
            {
            }
            
            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2, mPar3, mPar4, mPar5);
                delete this;
                return ret;
            }
            
        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type);
            Par1Type mPar1;
            Par2Type mPar2;
            Par3Type mPar3;
            Par4Type mPar4;
            Par5Type mPar5;
        };
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 5 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @param par3 The 3rd parameter.
         * @param par4 The 4th parameter.
         * @param par5 The 5th parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type),
                                            Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5)
        {
            return new MethodCall5<ObjectType, Par1Type, Par2Type, Par3Type, Par4Type, Par5Type>(obj, method, par1, par2, par3, par4, par5);
        }
        
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 6 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type>
        class MethodCall6 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             * @param par3 The 3rd parameter.
             * @param par4 The 4th parameter.
             * @param par5 The 5th parameter.
             * @param par6 The 6th parameter.
             */
            MethodCall6(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type),
                        Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            , mPar3(par3)
            , mPar4(par4)
            , mPar5(par5)
            , mPar6(par6)
            {
            }
            
            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2, mPar3, mPar4, mPar5, mPar6);
                delete this;
                return ret;
            }
            
        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type);
            Par1Type mPar1;
            Par2Type mPar2;
            Par3Type mPar3;
            Par4Type mPar4;
            Par5Type mPar5;
            Par6Type mPar6;
        };
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 6 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @param par3 The 3rd parameter.
         * @param par4 The 4th parameter.
         * @param par5 The 5th parameter.
         * @param par6 The 6th parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type),
                                            Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6)
        {
            return new MethodCall6<ObjectType, Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type>(obj, method, par1, par2, par3, par4, par5, par6);
        }
        
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 7 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type>
        class MethodCall7 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             * @param par3 The 3rd parameter.
             * @param par4 The 4th parameter.
             * @param par5 The 5th parameter.
             * @param par6 The 6th parameter.
             * @param par7 The 7th parameter.
             */
            MethodCall7(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type),
                        Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            , mPar3(par3)
            , mPar4(par4)
            , mPar5(par5)
            , mPar6(par6)
            , mPar7(par7)
            {
            }
            
            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2, mPar3, mPar4, mPar5, mPar6, mPar7);
                delete this;
                return ret;
            }
            
        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type);
            Par1Type mPar1;
            Par2Type mPar2;
            Par3Type mPar3;
            Par4Type mPar4;
            Par5Type mPar5;
            Par6Type mPar6;
            Par7Type mPar7;
        };
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 7 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @param par3 The 3rd parameter.
         * @param par4 The 4th parameter.
         * @param par5 The 5th parameter.
         * @param par6 The 6th parameter.
         * @param par7 The 7th parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type),
                                            Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7)
        {
            return new MethodCall7<ObjectType, Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type>(obj, method, par1, par2, par3, par4, par5, par6, par7);
        }
        
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 8 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type>
        class MethodCall8 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             * @param par3 The 3rd parameter.
             * @param par4 The 4th parameter.
             * @param par5 The 5th parameter.
             * @param par6 The 6th parameter.
             * @param par7 The 7th parameter.
             * @param par8 The 8th parameter.
             */
            MethodCall8(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type),
                        Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            , mPar3(par3)
            , mPar4(par4)
            , mPar5(par5)
            , mPar6(par6)
            , mPar7(par7)
            , mPar8(par8)
            {
            }
            
            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2, mPar3, mPar4, mPar5, mPar6, mPar7, mPar8);
                delete this;
                return ret;
            }
            
        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type);
            Par1Type mPar1;
            Par2Type mPar2;
            Par3Type mPar3;
            Par4Type mPar4;
            Par5Type mPar5;
            Par6Type mPar6;
            Par7Type mPar7;
            Par8Type mPar8;
        };
        
        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 8 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @param par3 The 3rd parameter.
         * @param par4 The 4th parameter.
         * @param par5 The 5th parameter.
         * @param par6 The 6th parameter.
         * @param par7 The 7th parameter.
         * @param par8 The 8th parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type),
                                            Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8)
        {
            return new MethodCall8<ObjectType, Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type>(obj, method, par1, par2, par3, par4, par5, par6, par7, par8);
        }


        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 9 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type, class Par9Type>
        class MethodCall9 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             * @param par3 The 3rd parameter.
             * @param par4 The 4th parameter.
             * @param par5 The 5th parameter.
             * @param par6 The 6th parameter.
             * @param par7 The 7th parameter.
             * @param par8 The 8th parameter.
             * @param par9 The 9th parameter.
             */
            MethodCall9(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type),
                        Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8, Par9Type par9)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            , mPar3(par3)
            , mPar4(par4)
            , mPar5(par5)
            , mPar6(par6)
            , mPar7(par7)
            , mPar8(par8)
            , mPar9(par9)
            {
            }

            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2, mPar3, mPar4, mPar5, mPar6, mPar7, mPar8, mPar9);
                delete this;
                return ret;
            }

        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type);
            Par1Type mPar1;
            Par2Type mPar2;
            Par3Type mPar3;
            Par4Type mPar4;
            Par5Type mPar5;
            Par6Type mPar6;
            Par7Type mPar7;
            Par8Type mPar8;
            Par9Type mPar9;
        };

        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 9 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @param par3 The 3rd parameter.
         * @param par4 The 4th parameter.
         * @param par5 The 5th parameter.
         * @param par6 The 6th parameter.
         * @param par7 The 7th parameter.
         * @param par8 The 8th parameter.
         * @param par9 The 9th parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type, class Par9Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type),
                                            Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8, Par9Type par9)
        {
            return new MethodCall9<ObjectType, Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type>(obj, method, par1, par2, par3, par4, par5, par6, par7, par8, par9);
        }

        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 10 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type, class Par9Type, class Par10Type>
        class MethodCall10 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             * @param par3 The 3rd parameter.
             * @param par4 The 4th parameter.
             * @param par5 The 5th parameter.
             * @param par6 The 6th parameter.
             * @param par7 The 7th parameter.
             * @param par8 The 8th parameter.
             * @param par9 The 9th parameter.
             * @param par10 The 10th parameter.
             */
            MethodCall10(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type),
                        Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8, Par9Type par9, Par10Type par10)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            , mPar3(par3)
            , mPar4(par4)
            , mPar5(par5)
            , mPar6(par6)
            , mPar7(par7)
            , mPar8(par8)
            , mPar9(par9)
            , mPar10(par10)
            {
            }

            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2, mPar3, mPar4, mPar5, mPar6, mPar7, mPar8, mPar9, mPar10);
                delete this;
                return ret;
            }

        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type);
            Par1Type mPar1;
            Par2Type mPar2;
            Par3Type mPar3;
            Par4Type mPar4;
            Par5Type mPar5;
            Par6Type mPar6;
            Par7Type mPar7;
            Par8Type mPar8;
            Par9Type mPar9;
            Par10Type mPar10;
        };

        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 10 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @param par3 The 3rd parameter.
         * @param par4 The 4th parameter.
         * @param par5 The 5th parameter.
         * @param par6 The 6th parameter.
         * @param par7 The 7th parameter.
         * @param par8 The 8th parameter.
         * @param par9 The 9th parameter.
         * @param par10 The 10th parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type, class Par9Type, class Par10Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type),
                                            Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8, Par9Type par9, Par10Type par10)
        {
            return new MethodCall10<ObjectType, Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type>(obj, method, par1, par2, par3, par4, par5, par6, par7, par8, par9, par10);
        }

        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 11 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type, class Par9Type, class Par10Type, class Par11Type>
        class MethodCall11 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             * @param par3 The 3rd parameter.
             * @param par4 The 4th parameter.
             * @param par5 The 5th parameter.
             * @param par6 The 6th parameter.
             * @param par7 The 7th parameter.
             * @param par8 The 8th parameter.
             * @param par9 The 9th parameter.
             * @param par10 The 10th parameter.
             * @param par11 The 11th parameter.
             */
            MethodCall11(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type),
                         Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8, Par9Type par9, Par10Type par10, Par11Type par11)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            , mPar3(par3)
            , mPar4(par4)
            , mPar5(par5)
            , mPar6(par6)
            , mPar7(par7)
            , mPar8(par8)
            , mPar9(par9)
            , mPar10(par10)
            , mPar11(par11)
            {
            }

            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2, mPar3, mPar4, mPar5, mPar6, mPar7, mPar8, mPar9, mPar10, mPar11);
                delete this;
                return ret;
            }

        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type);
            Par1Type mPar1;
            Par2Type mPar2;
            Par3Type mPar3;
            Par4Type mPar4;
            Par5Type mPar5;
            Par6Type mPar6;
            Par7Type mPar7;
            Par8Type mPar8;
            Par9Type mPar9;
            Par10Type mPar10;
            Par11Type mPar11;
        };

        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 11 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @param par3 The 3rd parameter.
         * @param par4 The 4th parameter.
         * @param par5 The 5th parameter.
         * @param par6 The 6th parameter.
         * @param par7 The 7th parameter.
         * @param par8 The 8th parameter.
         * @param par9 The 9th parameter.
         * @param par10 The 10th parameter.
         * @param par11 The 11th parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type, class Par9Type, class Par10Type, class Par11Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type),
                                            Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8, Par9Type par9, Par10Type par10, Par11Type par11)
        {
            return new MethodCall11<ObjectType, Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type>(obj, method, par1, par2, par3, par4, par5, par6, par7, par8, par9, par10, par11);
        }

        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 12 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type, class Par9Type, class Par10Type, class Par11Type, class Par12Type>
        class MethodCall12 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             * @param par3 The 3rd parameter.
             * @param par4 The 4th parameter.
             * @param par5 The 5th parameter.
             * @param par6 The 6th parameter.
             * @param par7 The 7th parameter.
             * @param par8 The 8th parameter.
             * @param par9 The 9th parameter.
             * @param par10 The 10th parameter.
             * @param par11 The 11th parameter.
             * @param par12 The 12th parameter.
             */
            MethodCall12(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type, Par12Type),
                         Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8, Par9Type par9, Par10Type par10, Par11Type par11, Par12Type par12)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            , mPar3(par3)
            , mPar4(par4)
            , mPar5(par5)
            , mPar6(par6)
            , mPar7(par7)
            , mPar8(par8)
            , mPar9(par9)
            , mPar10(par10)
            , mPar11(par11)
            , mPar12(par12)
            {
            }

            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2, mPar3, mPar4, mPar5, mPar6, mPar7, mPar8, mPar9, mPar10, mPar11, mPar12);
                delete this;
                return ret;
            }

        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type, Par12Type);
            Par1Type mPar1;
            Par2Type mPar2;
            Par3Type mPar3;
            Par4Type mPar4;
            Par5Type mPar5;
            Par6Type mPar6;
            Par7Type mPar7;
            Par8Type mPar8;
            Par9Type mPar9;
            Par10Type mPar10;
            Par11Type mPar11;
            Par12Type mPar12;
        };

        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 12 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @param par3 The 3rd parameter.
         * @param par4 The 4th parameter.
         * @param par5 The 5th parameter.
         * @param par6 The 6th parameter.
         * @param par7 The 7th parameter.
         * @param par8 The 8th parameter.
         * @param par9 The 9th parameter.
         * @param par10 The 10th parameter.
         * @param par11 The 11th parameter.
         * @param par12 The 12th parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type, class Par9Type, class Par10Type, class Par11Type, class Par12Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type, Par12Type),
                                            Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8, Par9Type par9, Par10Type par10, Par11Type par11, Par12Type par12)
        {
            return new MethodCall12<ObjectType, Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type, Par12Type>(obj, method, par1, par2, par3, par4, par5, par6, par7, par8, par9, par10, par11, par12);
        }
        /**
         * @ingroup MurlUtilMethodCall
         * @brief The method call object with 13 method parameters.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type, class Par9Type, class Par10Type, class Par11Type, class Par12Type, class Par13Type>
        class MethodCall13 : public IMethodCall
        {
        public:
            /**
             * @brief The constructor.
             * @param object The method's object context.
             * @param method The method pointer.
             * @param par1 The 1st parameter.
             * @param par2 The 2nd parameter.
             * @param par3 The 3rd parameter.
             * @param par4 The 4th parameter.
             * @param par5 The 5th parameter.
             * @param par6 The 6th parameter.
             * @param par7 The 7th parameter.
             * @param par8 The 8th parameter.
             * @param par9 The 9th parameter.
             * @param par10 The 10th parameter.
             * @param par11 The 11th parameter.
             * @param par12 The 12th parameter.
             * @param par13 The 13th parameter.
             */
            MethodCall13(ObjectType* object, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type, Par12Type, Par13Type),
                         Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8, Par9Type par9, Par10Type par10, Par11Type par11, Par12Type par12, Par13Type par13)
            : mObject(object)
            , mMethod(method)
            , mPar1(par1)
            , mPar2(par2)
            , mPar3(par3)
            , mPar4(par4)
            , mPar5(par5)
            , mPar6(par6)
            , mPar7(par7)
            , mPar8(par8)
            , mPar9(par9)
            , mPar10(par10)
            , mPar11(par11)
            , mPar12(par12)
            , mPar13(par13)
            {
            }

            /**
             * @brief Invoke the method pointer.
             * @return The return value from the method called.
             */
            virtual Bool Invoke() const
            {
                Bool ret = (mObject->*mMethod)(mPar1, mPar2, mPar3, mPar4, mPar5, mPar6, mPar7, mPar8, mPar9, mPar10, mPar11, mPar12, mPar13);
                delete this;
                return ret;
            }

        protected:
            ObjectType* mObject;
            Bool (ObjectType::*mMethod)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type, Par12Type, Par13Type);
            Par1Type mPar1;
            Par2Type mPar2;
            Par3Type mPar3;
            Par4Type mPar4;
            Par5Type mPar5;
            Par6Type mPar6;
            Par7Type mPar7;
            Par8Type mPar8;
            Par9Type mPar9;
            Par10Type mPar10;
            Par11Type mPar11;
            Par12Type mPar12;
            Par13Type mPar13;
        };

        /**
         * @ingroup MurlUtilMethodCall
         * @brief Create a method call object with 13 method parameters.
         * @param obj The method's object context.
         * @param method The method pointer.
         * @param par1 The 1st parameter.
         * @param par2 The 2nd parameter.
         * @param par3 The 3rd parameter.
         * @param par4 The 4th parameter.
         * @param par5 The 5th parameter.
         * @param par6 The 6th parameter.
         * @param par7 The 7th parameter.
         * @param par8 The 8th parameter.
         * @param par9 The 9th parameter.
         * @param par10 The 10th parameter.
         * @param par11 The 11th parameter.
         * @param par12 The 12th parameter.
         * @param par13 The 13th parameter.
         * @return The method call object.
         */
        template<class ObjectType, class Par1Type, class Par2Type, class Par3Type, class Par4Type, class Par5Type, class Par6Type, class Par7Type, class Par8Type, class Par9Type, class Par10Type, class Par11Type, class Par12Type, class Par13Type>
        const IMethodCall* CreateMethodCall(ObjectType* obj, Bool (ObjectType::*method)(Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type, Par12Type, Par13Type),
                                            Par1Type par1, Par2Type par2, Par3Type par3, Par4Type par4, Par5Type par5, Par6Type par6, Par7Type par7, Par8Type par8, Par9Type par9, Par10Type par10, Par11Type par11, Par12Type par12, Par13Type par13)
        {
            return new MethodCall13<ObjectType, Par1Type, Par2Type, Par3Type, Par4Type, Par5Type, Par6Type, Par7Type, Par8Type, Par9Type, Par10Type, Par11Type, Par12Type, Par13Type>(obj, method, par1, par2, par3, par4, par5, par6, par7, par8, par9, par10, par11, par12, par13);
        }
    }
}

#endif // __MURL_UTIL_METHOD_CALL_H__

// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_WAVE_UNIFORM_TIME_CONTROLLER_H__
#define __MURL_GRAPH_I_WAVE_UNIFORM_TIME_CONTROLLER_H__

#include "murl_graph_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class IController;
        class ITimeController;
        class IUniformTimeController;

        /**
         * @ingroup MurlGraphControllerInterfaces
         * @interface IWaveUniformTimeController
         * @brief The IWaveUniformTimeController interface.
         * A wave uniform controller can be attached to any node implementing the Graph::IGenericParameter
         * interface. It is used to control the value of that parameter by applying one or more predefined
         * waveform functions such as sine or rectangle wave or noise.
         */
        class IWaveUniformTimeController
        {
        public:
            /**
             * @brief Get the mutable IController interface.
             * @return The mutable IController interface.
             */
            virtual IController* GetControllerInterface() = 0;
            /**
             * @brief Get the constant IController interface.
             * @return The constant IController interface.
             */
            virtual const IController* GetControllerInterface() const = 0;

            /**
             * @brief Get the mutable ITimeController interface.
             * @return The mutable ITimeController interface.
             */
            virtual ITimeController* GetTimeControllerInterface() = 0;
            /**
             * @brief Get the constant ITimeController interface.
             * @return The constant ITimeController interface.
             */
            virtual const ITimeController* GetTimeControllerInterface() const = 0;

            /**
             * @brief Get the mutable IUniformTimeController interface.
             * @return The mutable IUniformTimeController interface.
             */
            virtual IUniformTimeController* GetUniformTimeControllerInterface() = 0;
            /**
             * @brief Get the constant IUniformTimeController interface.
             * @return The constant IUniformTimeController interface.
             */
            virtual const IUniformTimeController* GetUniformTimeControllerInterface() const = 0;

            /**
             * @brief Add a waveform generator.
             * This method adds a waveform item affecting a given set of components of
             * the controlled Graph::IGenericParameter.
             * @param components A bit mask of affected components, with bit numbers in the 
             *      range from 0 to IEnums::GetUniformTypeNumberOfComponents()-1 with the
             *      referenced parameter's data type. 
             * @param waveform The waveform to generate.
             * @param offset The value offset to add to the generated output (bias).
             * @param amplitude The output amplitude.
             * @param phase The phase shift in seconds.
             * @param frequency The waveform frequency in Hertz.
             * @param dutyCycle The duty cycle, used for rectangle and triangle waves.
             * @return true if successful.
             */
            virtual Bool AddGenerator(UInt32 components, IEnums::Waveform waveform, Real offset, Real amplitude, Real phase, Real frequency, Real dutyCycle) = 0;
            /**
             * @brief Get the total number of waveform generators defined.
             * @return The number of generators.
             */
            virtual UInt32 GetNumberOfGenerators() const = 0;
            /**
             * @brief Get the affected variable components of a generator at a given index.
             * @param generatorIndex The index of the generator, from 0 to GetNumberOfGenerators()-1.
             * @return A bit mask of affected variable components.
             */
            virtual UInt32 GetAffectedGeneratorComponents(UInt32 generatorIndex) const = 0;
            /**
             * @brief Get the waveform function of a generator at a given index.
             * @param generatorIndex The index of the generator, from 0 to GetNumberOfGenerators()-1.
             * @return The waveform.
             */
            virtual IEnums::Waveform GetGeneratorWaveform(UInt32 generatorIndex) const = 0;
            /**
             * @brief Get the value offset (bias) of a generator at a given index.
             * @param generatorIndex The index of the generator, from 0 to GetNumberOfGenerators()-1.
             * @return The offset.
             */
            virtual Real GetGeneratorOffset(UInt32 generatorIndex) const = 0;
            /**
             * @brief Get the amplitude of a generator at a given index.
             * @param generatorIndex The index of the generator, from 0 to GetNumberOfGenerators()-1.
             * @return The amplitude.
             */
            virtual Real GetGeneratorAmplitude(UInt32 generatorIndex) const = 0;
            /**
             * @brief Get the phase shift of a generator at a given index.
             * @param generatorIndex The index of the generator, from 0 to GetNumberOfGenerators()-1.
             * @return The phase shift.
             */
            virtual Real GetGeneratorPhase(UInt32 generatorIndex) const = 0;
            /**
             * @brief Get the frequency of a generator at a given index.
             * @param generatorIndex The index of the generator, from 0 to GetNumberOfGenerators()-1.
             * @return The frequency.
             */
            virtual Real GetGeneratorFrequency(UInt32 generatorIndex) const = 0;
            /**
             * @brief Get the duty cycle of a generator at a given index.
             * @param generatorIndex The index of the generator, from 0 to GetNumberOfGenerators()-1.
             * @return The duty cycle.
             */
            virtual Real GetGeneratorDutyCycle(UInt32 generatorIndex) const = 0;

        protected:
            virtual ~IWaveUniformTimeController() {}
        };
    }
}

#endif // __MURL_GRAPH_I_WAVE_UNIFORM_TIME_CONTROLLER_H__

// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_GRAPH_NODE_TYPES_H__
#define __MURL_LOGIC_GRAPH_NODE_TYPES_H__

#include "murl_logic_graph_node.h"

#include "murl_graph_i_aligner.h"
#include "murl_graph_i_anchor.h"
#include "murl_graph_i_anchor_state.h"
#include "murl_graph_i_anchor_state_copy.h"
#include "murl_graph_i_audio_sequence.h"
#include "murl_graph_i_audio_source.h"
#include "murl_graph_i_ball_joint.h"
#include "murl_graph_i_body.h"
#include "murl_graph_i_bone.h"
#include "murl_graph_i_bone_state.h"
#include "murl_graph_i_bone_state_copy.h"
#include "murl_graph_i_bounding_box.h"
#include "murl_graph_i_button.h"
#include "murl_graph_i_camera.h"
#include "murl_graph_i_camera_state.h"
#include "murl_graph_i_camera_state_copy.h"
#include "murl_graph_i_camera_transform.h"
#include "murl_graph_i_clip.h"
#include "murl_graph_i_clip_sequencer.h"
#include "murl_graph_i_clip_transition.h"
#include "murl_graph_i_clone_transform.h"
#include "murl_graph_i_collider.h"
#include "murl_graph_i_constant_buffer_parameter.h"
#include "murl_graph_i_constant_buffer_parameter_group.h"
#include "murl_graph_i_constant_buffer_parameters.h"
#include "murl_graph_i_contact.h"
#include "murl_graph_i_cube_collider.h"
#include "murl_graph_i_cube_geometry.h"
#include "murl_graph_i_culler.h"
#include "murl_graph_i_culler_state.h"
#include "murl_graph_i_culler_state_copy.h"
#include "murl_graph_i_field.h"
#include "murl_graph_i_fixed_parameters.h"
#include "murl_graph_i_fixed_program.h"
#include "murl_graph_i_frame_buffer.h"
#include "murl_graph_i_generic_geometry.h"
#include "murl_graph_i_generic_parameter.h"
#include "murl_graph_i_generic_parameter_group.h"
#include "murl_graph_i_generic_parameters.h"
#include "murl_graph_i_height_field.h"
#include "murl_graph_i_hinge_joint.h"
#include "murl_graph_i_instance.h"
#include "murl_graph_i_island.h"
#include "murl_graph_i_island_state.h"
#include "murl_graph_i_island_state_copy.h"
#include "murl_graph_i_joint.h"
#include "murl_graph_i_layer_state.h"
#include "murl_graph_i_light.h"
#include "murl_graph_i_light_state.h"
#include "murl_graph_i_light_state_copy.h"
#include "murl_graph_i_light_transform.h"
#include "murl_graph_i_listener.h"
#include "murl_graph_i_listener_state.h"
#include "murl_graph_i_listener_state_copy.h"
#include "murl_graph_i_listener_transform.h"
#include "murl_graph_i_material.h"
#include "murl_graph_i_material_state.h"
#include "murl_graph_i_material_state_copy.h"
#include "murl_graph_i_namespace.h"
#include "murl_graph_i_nine_patch_plane_geometry.h"
#include "murl_graph_i_nine_patch_plane_sequence_geometry.h"
#include "murl_graph_i_node.h"
#include "murl_graph_i_parameters.h"
#include "murl_graph_i_parameters_state.h"
#include "murl_graph_i_parameters_state_copy.h"
#include "murl_graph_i_plane_collider.h"
#include "murl_graph_i_plane_geometry.h"
#include "murl_graph_i_plane_sequence_geometry.h"
#include "murl_graph_i_program.h"
#include "murl_graph_i_reference.h"
#include "murl_graph_i_reset_transform.h"
#include "murl_graph_i_resource_mesh_collider.h"
#include "murl_graph_i_resource_mesh_culler.h"
#include "murl_graph_i_resource_mesh_geometry.h"
#include "murl_graph_i_resource_shadow_geometry.h"
#include "murl_graph_i_scale.h"
#include "murl_graph_i_shader.h"
#include "murl_graph_i_shader_parameter.h"
#include "murl_graph_i_shader_parameter_group.h"
#include "murl_graph_i_shader_parameters.h"
#include "murl_graph_i_shader_program.h"
#include "murl_graph_i_shadow_camera.h"
#include "murl_graph_i_sphere_collider.h"
#include "murl_graph_i_spring.h"
#include "murl_graph_i_sub_state.h"
#include "murl_graph_i_subject.h"
#include "murl_graph_i_surface.h"
#include "murl_graph_i_surface_state.h"
#include "murl_graph_i_surface_state_copy.h"
#include "murl_graph_i_switch.h"
#include "murl_graph_i_template.h"
#include "murl_graph_i_text_geometry.h"
#include "murl_graph_i_text_texture.h"
#include "murl_graph_i_texture.h"
#include "murl_graph_i_texture_state.h"
#include "murl_graph_i_texture_state_copy.h"
#include "murl_graph_i_timeline.h"
#include "murl_graph_i_timeline_state.h"
#include "murl_graph_i_timeline_state_copy.h"
#include "murl_graph_i_transform.h"
#include "murl_graph_i_variable.h"
#include "murl_graph_i_video_sequence.h"
#include "murl_graph_i_video_source.h"
#include "murl_graph_i_view.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @addtogroup MurlLogicGraphNodeTypes
         * @brief Logic graph node objects are implementing the IObservableNode
         * interface which can be registered to the INodeObserver.
         * @{
         */

        /** @brief IObservableNode for accessing the Graph::IAligner interface. */
        typedef GraphNodeT<Graph::IAligner>                 AlignerNode;

        /** @brief IObservableNode for accessing the Graph::IAnchor interface. */
        typedef GraphNodeT<Graph::IAnchor>                  AnchorNode;

        /** @brief IObservableNode for accessing the Graph::IAnchorState interface. */
        typedef GraphNodeT<Graph::IAnchorState>             AnchorStateNode;

        /** @brief IObservableNode for accessing the Graph::IAnchorStateCopy interface. */
        typedef GraphNodeT<Graph::IAnchorStateCopy>         AnchorStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::IAudioSequence interface. */
        typedef GraphNodeT<Graph::IAudioSequence>           AudioSequenceNode;

        /** @brief IObservableNode for accessing the Graph::IAudioSource interface. */
        typedef GraphNodeT<Graph::IAudioSource>             AudioSourceNode;

        /** @brief IObservableNode for accessing the Graph::IBallJoint interface. */
        typedef GraphNodeT<Graph::IBallJoint>               BallJointNode;

        /** @brief IObservableNode for accessing the Graph::IBody interface. */
        typedef GraphNodeT<Graph::IBody>                    BodyNode;

        /** @brief IObservableNode for accessing the Graph::IBone interface. */
        typedef GraphNodeT<Graph::IBone>                    BoneNode;

        /** @brief IObservableNode for accessing the Graph::IBoneState interface. */
        typedef GraphNodeT<Graph::IBoneState>               BoneStateNode;

        /** @brief IObservableNode for accessing the Graph::IBoneStateCopy interface. */
        typedef GraphNodeT<Graph::IBoneStateCopy>           BoneStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::IBoundingBox interface. */
        typedef GraphNodeT<Graph::IBoundingBox>             BoundingBoxNode;

        /** @brief IObservableNode for accessing the Graph::IButton interface. */
        typedef GraphNodeT<Graph::IButton>                  ButtonNode;

        /** @brief IObservableNode for accessing the Graph::ICamera interface. */
        typedef GraphNodeT<Graph::ICamera>                  CameraNode;

        /** @brief IObservableNode for accessing the Graph::ICameraState interface. */
        typedef GraphNodeT<Graph::ICameraState>             CameraStateNode;

        /** @brief IObservableNode for accessing the Graph::ICameraStateCopy interface. */
        typedef GraphNodeT<Graph::ICameraStateCopy>         CameraStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::ICameraTransform interface. */
        typedef GraphNodeT<Graph::ICameraTransform>         CameraTransformNode;

        /** @brief IObservableNode for accessing the Graph::IClip interface. */
        typedef GraphNodeT<Graph::IClip>                    ClipNode;

        /** @brief IObservableNode for accessing the Graph::IClipSequencer interface. */
        typedef GraphNodeT<Graph::IClipSequencer>           ClipSequencerNode;

        /** @brief IObservableNode for accessing the Graph::IClipTransition interface. */
        typedef GraphNodeT<Graph::IClipTransition>          ClipTransitionNode;

        /** @brief IObservableNode for accessing the Graph::ICloneTransform interface. */
        typedef GraphNodeT<Graph::ICloneTransform>          CloneTransformNode;

        /** @brief IObservableNode for accessing the Graph::ICollider interface. */
        typedef GraphNodeT<Graph::ICollider>                ColliderNode;

        /** @brief IObservableNode for accessing the Graph::IConstantBufferParameter interface. */
        typedef GraphNodeT<Graph::IConstantBufferParameter> ConstantBufferParameterNode;

        /** @brief IObservableNode for accessing the Graph::IConstantBufferParameterGroup interface. */
        typedef GraphNodeT<Graph::IConstantBufferParameterGroup> ConstantBufferParameterGroupNode;

        /** @brief IObservableNode for accessing the Graph::IConstantBufferParameters interface. */
        typedef GraphNodeT<Graph::IConstantBufferParameters> ConstantBufferParametersNode;
        
        /** @brief IObservableNode for accessing the Graph::IContact interface. */
        typedef GraphNodeT<Graph::IContact>                 ContactNode;

        /** @brief IObservableNode for accessing the Graph::ICubeCollider interface. */
        typedef GraphNodeT<Graph::ICubeCollider>            CubeColliderNode;

        /** @brief IObservableNode for accessing the Graph::ICubeGeometry interface. */
        typedef GraphNodeT<Graph::ICubeGeometry>            CubeGeometryNode;

        /** @brief IObservableNode for accessing the Graph::ICuller interface. */
        typedef GraphNodeT<Graph::ICuller>                  CullerNode;

        /** @brief IObservableNode for accessing the Graph::ICullerState interface. */
        typedef GraphNodeT<Graph::ICullerState>             CullerStateNode;

        /** @brief IObservableNode for accessing the Graph::ICullerStateCopy interface. */
        typedef GraphNodeT<Graph::ICullerStateCopy>         CullerStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::IField interface. */
        typedef GraphNodeT<Graph::IField>                   FieldNode;

        /** @brief IObservableNode for accessing the Graph::IFixedParameters interface. */
        typedef GraphNodeT<Graph::IFixedParameters>         FixedParametersNode;

        /** @brief IObservableNode for accessing the Graph::IFixedProgram interface. */
        typedef GraphNodeT<Graph::IFixedProgram>            FixedProgramNode;

        /** @brief IObservableNode for accessing the Graph::IFrameBuffer interface. */
        typedef GraphNodeT<Graph::IFrameBuffer>             FrameBufferNode;

        /** @brief IObservableNode for accessing the Graph::IGenericGeometry interface. */
        typedef GraphNodeT<Graph::IGenericGeometry>         GenericGeometryNode;

        /** @brief IObservableNode for accessing the Graph::IGenericParameter interface. */
        typedef GraphNodeT<Graph::IGenericParameter>        GenericParameterNode;

        /** @brief IObservableNode for accessing the Graph::IGenericParameterGroup interface. */
        typedef GraphNodeT<Graph::IGenericParameterGroup>   GenericParameterGroupNode;

        /** @brief IObservableNode for accessing the Graph::IGenericParameters interface. */
        typedef GraphNodeT<Graph::IGenericParameters>       GenericParametersNode;

        /** @brief IObservableNode for accessing the Graph::IHeightField interface. */
        typedef GraphNodeT<Graph::IHeightField>             HeightFieldNode;

        /** @brief IObservableNode for accessing the Graph::IHingeJoint interface. */
        typedef GraphNodeT<Graph::IHingeJoint>              HingeJointNode;

        /** @brief IObservableNode for accessing the Graph::IInstance interface. */
        typedef GraphNodeT<Graph::IInstance>                InstanceNode;

        /** @brief IObservableNode for accessing the Graph::IIsland interface. */
        typedef GraphNodeT<Graph::IIsland>                  IslandNode;

        /** @brief IObservableNode for accessing the Graph::IIslandState interface. */
        typedef GraphNodeT<Graph::IIslandState>             IslandStateNode;

        /** @brief IObservableNode for accessing the Graph::IIslandStateCopy interface. */
        typedef GraphNodeT<Graph::IIslandStateCopy>         IslandStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::IJoint interface. */
        typedef GraphNodeT<Graph::IJoint>                   JointNode;

        /** @brief IObservableNode for accessing the Graph::ILayerState interface. */
        typedef GraphNodeT<Graph::ILayerState>              LayerStateNode;

        /** @brief IObservableNode for accessing the Graph::ILight interface. */
        typedef GraphNodeT<Graph::ILight>                   LightNode;

        /** @brief IObservableNode for accessing the Graph::ILightState interface. */
        typedef GraphNodeT<Graph::ILightState>              LightStateNode;

        /** @brief IObservableNode for accessing the Graph::ILightStateCopy interface. */
        typedef GraphNodeT<Graph::ILightStateCopy>          LightStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::ILightTransform interface. */
        typedef GraphNodeT<Graph::ILightTransform>          LightTransformNode;

        /** @brief IObservableNode for accessing the Graph::IListener interface. */
        typedef GraphNodeT<Graph::IListener>                ListenerNode;

        /** @brief IObservableNode for accessing the Graph::IListenerState interface. */
        typedef GraphNodeT<Graph::IListenerState>           ListenerStateNode;

        /** @brief IObservableNode for accessing the Graph::IListenerStateCopy interface. */
        typedef GraphNodeT<Graph::IListenerStateCopy>       ListenerStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::IListenerTransform interface. */
        typedef GraphNodeT<Graph::IListenerTransform>       ListenerTransformNode;

        /** @brief IObservableNode for accessing the Graph::IMaterial interface. */
        typedef GraphNodeT<Graph::IMaterial>                MaterialNode;

        /** @brief IObservableNode for accessing the Graph::IMaterialState interface. */
        typedef GraphNodeT<Graph::IMaterialState>           MaterialStateNode;

        /** @brief IObservableNode for accessing the Graph::IMaterialStateCopy interface. */
        typedef GraphNodeT<Graph::IMaterialStateCopy>       MaterialStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::INamespace interface. */
        typedef GraphNodeT<Graph::INamespace>               NamespaceNode;

        /** @brief IObservableNode for accessing the Graph::INinePatchPlaneGeometry interface. */
        typedef GraphNodeT<Graph::INinePatchPlaneGeometry>  NinePatchPlaneGeometryNode;

        /** @brief IObservableNode for accessing the Graph::INinePatchPlaneSequenceGeometry interface. */
        typedef GraphNodeT<Graph::INinePatchPlaneSequenceGeometry>  NinePatchPlaneSequenceGeometryNode;

        /** @brief IObservableNode for accessing the Graph::INode interface. */
        typedef GraphNodeT<Graph::INode>                    GraphNode;

        /** @brief IObservableNode for accessing the Graph::IParameters interface. */
        typedef GraphNodeT<Graph::IParameters>              ParametersNode;

        /** @brief IObservableNode for accessing the Graph::IParametersState interface. */
        typedef GraphNodeT<Graph::IParametersState>         ParametersStateNode;

        /** @brief IObservableNode for accessing the Graph::IParametersStateCopy interface. */
        typedef GraphNodeT<Graph::IParametersStateCopy>     ParametersStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::IPlaneCollider interface. */
        typedef GraphNodeT<Graph::IPlaneCollider>           PlaneColliderNode;

        /** @brief IObservableNode for accessing the Graph::IPlaneGeometry interface. */
        typedef GraphNodeT<Graph::IPlaneGeometry>           PlaneGeometryNode;

        /** @brief IObservableNode for accessing the Graph::IPlaneSequenceGeometry interface. */
        typedef GraphNodeT<Graph::IPlaneSequenceGeometry>   PlaneSequenceGeometryNode;

        /** @brief IObservableNode for accessing the Graph::IProgram interface. */
        typedef GraphNodeT<Graph::IProgram>                 ProgramNode;

        /** @brief IObservableNode for accessing the Graph::IReference interface. */
        typedef GraphNodeT<Graph::IReference>               ReferenceNode;

        /** @brief IObservableNode for accessing the Graph::IResetTransform interface. */
        typedef GraphNodeT<Graph::IResetTransform>          ResetTransformNode;

        /** @brief IObservableNode for accessing the Graph::IResourceMeshCollider interface. */
        typedef GraphNodeT<Graph::IResourceMeshCollider>    ResourceMeshColliderNode;

        /** @brief IObservableNode for accessing the Graph::IResourceMeshCuller interface. */
        typedef GraphNodeT<Graph::IResourceMeshCuller>      ResourceMeshCullerNode;

        /** @brief IObservableNode for accessing the Graph::IResourceMeshGeometry interface. */
        typedef GraphNodeT<Graph::IResourceMeshGeometry>    ResourceMeshGeometryNode;

        /** @brief IObservableNode for accessing the Graph::IResourceShadowGeometry interface. */
        typedef GraphNodeT<Graph::IResourceShadowGeometry>  ResourceShadowGeometryNode;

        /** @brief IObservableNode for accessing the Graph::IScale interface. */
        typedef GraphNodeT<Graph::IScale>                   ScaleNode;

        /** @brief IObservableNode for accessing the Graph::IShader interface. */
        typedef GraphNodeT<Graph::IShader>                  ShaderNode;

        /** @brief IObservableNode for accessing the Graph::IShaderParameter interface. */
        typedef GraphNodeT<Graph::IShaderParameter>         ShaderParameterNode;

        /** @brief IObservableNode for accessing the Graph::IShaderParameterGroup interface. */
        typedef GraphNodeT<Graph::IShaderParameterGroup>    ShaderParameterGroupNode;

        /** @brief IObservableNode for accessing the Graph::IShaderParameters interface. */
        typedef GraphNodeT<Graph::IShaderParameters>        ShaderParametersNode;

        /** @brief IObservableNode for accessing the Graph::IShaderProgram interface. */
        typedef GraphNodeT<Graph::IShaderProgram>           ShaderProgramNode;

        /** @brief IObservableNode for accessing the Graph::IShadowCamera interface. */
        typedef GraphNodeT<Graph::IShadowCamera>            ShadowCameraNode;

        /** @brief Deprecated, use Murl::Logic::AudioSourceNode. */
        typedef GraphNodeT<Graph::IAudioSource>             SoundNode;

        /** @brief IObservableNode for accessing the Graph::ISphereCollider interface. */
        typedef GraphNodeT<Graph::ISphereCollider>          SphereColliderNode;

        /** @brief IObservableNode for accessing the Graph::ISpring interface. */
        typedef GraphNodeT<Graph::ISpring>                  SpringNode;

        /** @brief IObservableNode for accessing the Graph::ISubState interface. */
        typedef GraphNodeT<Graph::ISubState>                SubStateNode;

        /** @brief IObservableNode for accessing the Graph::ISubject interface. */
        typedef GraphNodeT<Graph::ISubject>                 SubjectNode;

        /** @brief IObservableNode for accessing the Graph::ISurface interface. */
        typedef GraphNodeT<Graph::ISurface>                 SurfaceNode;

        /** @brief IObservableNode for accessing the Graph::ISurfaceState interface. */
        typedef GraphNodeT<Graph::ISurfaceState>            SurfaceStateNode;

        /** @brief IObservableNode for accessing the Graph::ISurfaceStateCopy interface. */
        typedef GraphNodeT<Graph::ISurfaceStateCopy>        SurfaceStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::ISwitch interface. */
        typedef GraphNodeT<Graph::ISwitch>                  SwitchNode;

        /** @brief IObservableNode for accessing the Graph::ITemplate interface. */
        typedef GraphNodeT<Graph::ITemplate>                TemplateNode;

        /** @brief IObservableNode for accessing the Graph::ITextGeometry interface. */
        typedef GraphNodeT<Graph::ITextGeometry>            TextGeometryNode;

        /** @brief IObservableNode for accessing the Graph::ITextTexture interface. */
        typedef GraphNodeT<Graph::ITextTexture>             TextTextureNode;

        /** @brief IObservableNode for accessing the Graph::ITexture interface. */
        typedef GraphNodeT<Graph::ITexture>                 TextureNode;

        /** @brief IObservableNode for accessing the Graph::ITextureState interface. */
        typedef GraphNodeT<Graph::ITextureState>            TextureStateNode;

        /** @brief IObservableNode for accessing the Graph::ITextureStateCopy interface. */
        typedef GraphNodeT<Graph::ITextureStateCopy>        TextureStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::ITimeline interface. */
        typedef GraphNodeT<Graph::ITimeline>                TimelineNode;

        /** @brief IObservableNode for accessing the Graph::ITimelineState interface. */
        typedef GraphNodeT<Graph::ITimelineState>           TimelineStateNode;

        /** @brief IObservableNode for accessing the Graph::ITimelineStateCopy interface. */
        typedef GraphNodeT<Graph::ITimelineStateCopy>       TimelineStateCopyNode;

        /** @brief IObservableNode for accessing the Graph::ITransform interface. */
        typedef GraphNodeT<Graph::ITransform>               TransformNode;

        /** @brief IObservableNode for accessing the Graph::IVariable interface. */
        typedef GraphNodeT<Graph::IVariable>                VariableNode;
        
        /** @brief IObservableNode for accessing the Graph::IVideoSequence interface. */
        typedef GraphNodeT<Graph::IVideoSequence>           VideoSequenceNode;
        
        /** @brief IObservableNode for accessing the Graph::IVideoSource interface. */
        typedef GraphNodeT<Graph::IVideoSource>             VideoSourceNode;
        
        /** @brief IObservableNode for accessing the Graph::IView interface. */
        typedef GraphNodeT<Graph::IView>                    ViewNode;
        
        /** @} */
    }
}

#endif  // __MURL_LOGIC_GRAPH_NODE_TYPES_H__

//---------------------------------------------------------------------
// <autogenerated>
//
//     Generated by Message Compiler (mc.exe)
//
//     Copyright (c) Microsoft Corporation. All Rights Reserved.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </autogenerated>
//---------------------------------------------------------------------




namespace SimpleProvider
{
using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using System.Diagnostics.Eventing;
using Microsoft.Win32;
using System.Runtime.InteropServices;
using System.Security.Principal;

    public class MicrosoftWindowsSDKSampleSimpleProviderCs
    {
        //
        // Provider Microsoft-Windows-SDKSample-SimpleProvider-CS Event Count 5
        //

        private EventProviderVersionTwo m_provider = new EventProviderVersionTwo(new Guid("21a9201e-73b0-43fe-9821-7e159a59bc71"));
        //
        // Task :  eventGUIDs
        //

        //
        // Event Descriptors
        //
        private EventDescriptor SampleEvt_INT32;
        private EventDescriptor SampleEvt_Float;
        private EventDescriptor SampleEvt_Bool;
        private EventDescriptor SampleEvt_UnicodeString;
        private EventDescriptor SampleEvt_Guid;


        public MicrosoftWindowsSDKSampleSimpleProviderCs()
        {
            unchecked
            {
                SampleEvt_INT32 = new EventDescriptor(0x65, 0x0, 0x9, 0x4, 0x0, 0x0, (long)0x8000000000000000);
                SampleEvt_Float = new EventDescriptor(0x66, 0x0, 0x10, 0x3, 0x0, 0x0, (long)0x4000000000000000);
                SampleEvt_Bool = new EventDescriptor(0x67, 0x0, 0x10, 0x2, 0x0, 0x0, (long)0x4000000000000000);
                SampleEvt_UnicodeString = new EventDescriptor(0x68, 0x0, 0x9, 0x1, 0x0, 0x0, (long)0x8000000000000000);
                SampleEvt_Guid = new EventDescriptor(0x69, 0x0, 0x9, 0x1, 0x0, 0x0, (long)0x8000000000000000);
            }
        }


        //
        // Event method for SampleEvt_INT32
        //
        public bool EventWriteSampleEvt_INT32(int Prop_Int32)
        {

            if (!m_provider.IsEnabled())
            {
                return true;
            }

            return m_provider.TemplateT_INT32(ref SampleEvt_INT32, Prop_Int32);
        }

        //
        // Event method for SampleEvt_Float
        //
        public bool EventWriteSampleEvt_Float(float Prop_Float)
        {

            if (!m_provider.IsEnabled())
            {
                return true;
            }

            return m_provider.TemplateT_FLOAT(ref SampleEvt_Float, Prop_Float);
        }

        //
        // Event method for SampleEvt_Bool
        //
        public bool EventWriteSampleEvt_Bool(bool Prop_Bool)
        {

            if (!m_provider.IsEnabled())
            {
                return true;
            }

            return m_provider.TemplateT_BOOL(ref SampleEvt_Bool, Prop_Bool);
        }

        //
        // Event method for SampleEvt_UnicodeString
        //
        public bool EventWriteSampleEvt_UnicodeString(string Prop_UnicodeString)
        {

            return m_provider.WriteEvent(ref SampleEvt_UnicodeString, Prop_UnicodeString);

        }

        //
        // Event method for SampleEvt_Guid
        //
        public bool EventWriteSampleEvt_Guid(Guid Prop_Guid)
        {

            if (!m_provider.IsEnabled())
            {
                return true;
            }

            return m_provider.TemplateT_GUID(ref SampleEvt_Guid, Prop_Guid);
        }
    }

    internal class EventProviderVersionTwo : EventProvider
    {
         internal EventProviderVersionTwo(Guid id)
                : base(id)
         {}


        [StructLayout(LayoutKind.Explicit, Size = 16)]
        private struct EventData
        {
            [FieldOffset(0)]
            internal UInt64 DataPointer;
            [FieldOffset(8)]
            internal uint Size;
            [FieldOffset(12)]
            internal int Reserved;
        }



        internal unsafe bool TemplateT_INT32(
            ref EventDescriptor eventDescriptor,
            int Prop_Int32
            )
        {
            int argumentCount = 1;
            bool status = true;

            if (IsEnabled(eventDescriptor.Level, eventDescriptor.Keywords))
            {
                byte* userData = stackalloc byte[sizeof(EventData) * argumentCount];
                EventData* userDataPtr = (EventData*)userData;

                userDataPtr[0].DataPointer = (UInt64)(&Prop_Int32);
                userDataPtr[0].Size = (uint)(sizeof(int)  );

                status = WriteEvent(ref eventDescriptor, argumentCount, (IntPtr)(userData));
            }

            return status;

        }



        internal unsafe bool TemplateT_FLOAT(
            ref EventDescriptor eventDescriptor,
            float Prop_Float
            )
        {
            int argumentCount = 1;
            bool status = true;

            if (IsEnabled(eventDescriptor.Level, eventDescriptor.Keywords))
            {
                byte* userData = stackalloc byte[sizeof(EventData) * argumentCount];
                EventData* userDataPtr = (EventData*)userData;

                userDataPtr[0].DataPointer = (UInt64)(&Prop_Float);
                userDataPtr[0].Size = (uint)(sizeof(float)  );

                status = WriteEvent(ref eventDescriptor, argumentCount, (IntPtr)(userData));
            }

            return status;

        }



        internal unsafe bool TemplateT_BOOL(
            ref EventDescriptor eventDescriptor,
            bool Prop_Bool
            )
        {
            int argumentCount = 1;
            bool status = true;

            if (IsEnabled(eventDescriptor.Level, eventDescriptor.Keywords))
            {
                byte* userData = stackalloc byte[sizeof(EventData) * argumentCount];
                EventData* userDataPtr = (EventData*)userData;

                int Prop_BoolInt = Prop_Bool ? 1 : 0;
                userDataPtr[0].DataPointer = (UInt64)(&Prop_BoolInt);
                userDataPtr[0].Size = (uint)(sizeof(int));

                status = WriteEvent(ref eventDescriptor, argumentCount, (IntPtr)(userData));
            }

            return status;

        }



        internal unsafe bool TemplateT_GUID(
            ref EventDescriptor eventDescriptor,
            Guid Prop_Guid
            )
        {
            int argumentCount = 1;
            bool status = true;

            if (IsEnabled(eventDescriptor.Level, eventDescriptor.Keywords))
            {
                byte* userData = stackalloc byte[sizeof(EventData) * argumentCount];
                EventData* userDataPtr = (EventData*)userData;

                userDataPtr[0].DataPointer = (UInt64)(&Prop_Guid);
                userDataPtr[0].Size = (uint)(sizeof(Guid)  );

                status = WriteEvent(ref eventDescriptor, argumentCount, (IntPtr)(userData));
            }

            return status;

        }

    }

}

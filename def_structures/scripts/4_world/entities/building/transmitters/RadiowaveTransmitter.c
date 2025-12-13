class DEF_RadiowaveTransmitter extends DEF_DynamicEventObject
{
        override void EEInit()
        {
            super.EEInit();

            if (GetGame().IsClient())
            {
                TransmitterBase.DEF_AddTransmitterToList(GetPosition());
            }
        }

        override void EEDelete(EntityAI parent)
        {
            super.EEDelete(parent);

            if (GetGame().IsClient())
            {
                TransmitterBase.DEF_RemoveTransmitterFromList(GetPosition());
            }
        }
};

class DEF_RADIOWAVE_TRANSMITTER_StaticObj_Transmitter_Small2_DE extends DEF_RadiowaveTransmitter {};
class DEF_RADIOWAVE_TRANSMITTER_Land_Mil_Antena_K7_DE extends DEF_RadiowaveTransmitter {};
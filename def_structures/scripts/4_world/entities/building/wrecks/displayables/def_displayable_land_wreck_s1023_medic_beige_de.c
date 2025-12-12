#ifdef GAMELABS
class DEF_Displayable_Land_Wreck_S1023_Medic_Beige_DE extends GameLabsLiveIndicator
{
    static bool m_SoundInit = SoundInit();

    static bool SoundInit()
    {
        CrashSoundSets.RegisterSoundSet("DEF_Dummy_Silent_SoundSet");
        return true;
    };

    override string GetSoundSet()
    {
        return "DEF_Dummy_Silent_SoundSet";
    };

    override void EEInit()
    {
    #ifdef GAMELABS
        _eventPictogram = "ambulance"
        _eventDisplayName = "Ambulance"
    #endif
        super.EEInit();
    };
}
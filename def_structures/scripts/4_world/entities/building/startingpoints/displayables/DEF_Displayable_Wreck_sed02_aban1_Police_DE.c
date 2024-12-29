class DEF_Displayable_Wreck_sed02_aban1_Police_DE extends GameLabsLiveIndicator
{
    static bool m_SoundInit = SoundInit();

    static bool SoundInit()
    {
        CrashSoundSets.RegisterSoundSet("Dummy_Silent_SoundSet");
        return true;
    }

    override string GetSoundSet()
    {
        return "Dummy_Silent_SoundSet";
    }

    override void EEInit()
    {
    #ifdef GAMELABS
        _eventPictogram = "taxi"
        _eventDisplayName = "Police car"
    #endif
        super.EEInit();
    }
}
class DEF_Displayable_Wreck_sed02_aban2_Police_DE extends GameLabsLiveIndicator
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
        _eventPictogram = "taxi"
        _eventDisplayName = "Police car"
    #endif
        super.EEInit();
    };
}
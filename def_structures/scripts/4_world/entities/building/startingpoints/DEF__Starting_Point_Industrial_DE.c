class DEF__Starting_Point_Industrial_DE extends GameLabsLiveIndicator
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
        _eventPictogram = "truck-container";
        _eventDisplayName = "Industrial event";
    #endif
        super.EEInit();
    };
}
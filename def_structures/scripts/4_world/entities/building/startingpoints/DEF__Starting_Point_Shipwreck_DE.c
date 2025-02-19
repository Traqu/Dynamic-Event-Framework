class DEF__Starting_Point_Shipwreck_DE extends GameLabsLiveIndicator
{
    static bool m_SoundInit = SoundInit();

    static bool SoundInit()
    {
        CrashSoundSets.RegisterSoundSet("Shipwreck_SoundSet");
        return true;
    }

    override string GetSoundSet()
    {
        return "Shipwreck_SoundSet";
    }

    override void EEInit()
    {
    #ifdef GAMELABS
        _eventPictogram = "anchor"
        _eventDisplayName = "Container ship"
    #endif
        super.EEInit();
    }
}
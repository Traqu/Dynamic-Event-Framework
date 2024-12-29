class DEF_Displayable_Container_1Moh_DE extends GameLabsLiveIndicator
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
        _eventPictogram = "container-storage"
        _eventDisplayName = "Washed container"
    #endif
        super.EEInit();
    }
}
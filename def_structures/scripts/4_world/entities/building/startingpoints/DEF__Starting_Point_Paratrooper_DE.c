class DEF__Starting_Point_Paratrooper_DE extends GameLabsLiveIndicator
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

};